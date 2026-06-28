#include "bits/stdc++.h"
using namespace std;
void fun(vector<vector<int>> &p, int idx1, int idx2, int n, string s) {
    int i = idx1;
    int j = idx2;
    while (i >= 0 && j < n) {
        if (s[i] == s[j]) {
            p[i][j] = 1;
            i--;
            j++;
        } else {
            break;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = (int)s.length();
    // tells, if s[i,j] is a palindrome or not.
    vector<vector<int>> isPalindrome(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        fun(isPalindrome, i, i, n, s);
        if (i + 1 < n) {
            fun(isPalindrome, i, i + 1, n, s);
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= (n - len); i++) {
            int j = i + len - 1;
            dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            // if (s[i] == s[j]) {  // this is wrong, it only checks character,
            //     dp[i][j] += 1;   // but we want to check if s[i,j] is a palindrome
            // }
            if (isPalindrome[i][j] == 1) {
                dp[i][j] += 1;
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        std::cout << dp[l][r] << "\n";
    }

    return 0;
}