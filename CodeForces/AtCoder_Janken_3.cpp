#include "bits/stdc++.h"
using namespace std;
const int INF = -1e9;
int f(int you, int me) {
    // 0->rock,1->paper,2->scissor.
    if (you == 0) {
        if (me == 1) {
            return 1;
        }
        return 0;
    }
    if (you == 1) {
        if (me == 2) {
            return 1;
        }
        return 0;
    }
    if (you == 2) {
        if (me == 0) {
            return 1;
        }
        return 0;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            a[i] = 0;
        } else if (s[i] == 'P') {
            a[i] = 1;
        } else {
            a[i] = 2;
        }
    }
    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][0] = f(a[0], 0);
    dp[0][1] = f(a[0], 1);
    dp[0][2] = f(a[0], 2);
    // 0->rock,1->paper,2->scissor.

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                if (k == j)
                    continue;
                if (f(a[i], j) == -1)
                    dp[i][j] = -INF;
                else
                    dp[i][j] = max(dp[i - 1][k]) + (f(a[i], j) == 1);
            }
        }
    }

    cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << "\n";

    return 0;
}