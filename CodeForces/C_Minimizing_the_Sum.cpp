#include "bits/stdc++.h"
using namespace std;
#define int long long
const int inf = 4e18;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = inf;
    if (k >= n - 1) {
        cout << n * (*min_element(begin(a) + 1, end(a))) << "\n";
        return;
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, inf));
    for (int i = 0; i <= k; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + a[i];
        for (int j = 1; j <= k; j++) {
                }
    }
    cout << *min(dp[n].begin(), dp[n].end()) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}