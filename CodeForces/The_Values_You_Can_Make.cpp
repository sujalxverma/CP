#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(begin(a), end(a));
    set<int> ans;
    ans.insert(0);
    // number of sums can be made are from 0 to k.
    // we can use knapsack for each K from 1 to k.

    for (int s = 1; s <= k; s++) {
        vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - a[i - 1] >= 0) {
                    dp[i][j] |= dp[i - 1][j - a[i - 1]];
                }
            }
        }
        if (dp[n][s] == 1) {
            ans.insert(s);
        }
    }

    for (auto &x : ans) {
        cout << x << "\n";
    }
    return 0;
}