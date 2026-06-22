#include <iostream>
#include <vector>
using namespace std;
int t, n;
vector<int> a, p;
vector<vector<int>> dp;
int f(int rating, int x) {
    if (rating > x) {
        rating--;
    } else if (rating < x) {
        rating++;
    }
    return rating;
}
void solve2() {
    cin >> n;
    a.resize(n + 1, 0);
    p.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp.resize(n + 1, vector<int>(4, 0));
    // dp[i][1] = maximum rating after processing first i contests, before the skipped segment starts.
    // dp[i][2] = maximum rating after processing first i contests, currently inside the skipped segment.
    // dp[i][3] = maximum rating after processing first i contests, after the skipped segment has ended.

    dp[0][1] = 0;
    dp[0][2] = -1e9;
    dp[0][3] = -1e9;

    for (int i = 1; i <= n; i++) {
        // skipped segment not started. pre skipped era.
        dp[i][1] = f(dp[i - 1][1], a[i]);

        // skipped era.
        dp[i][2] = max(
            dp[i - 1][1], // starts skipping from this ith index.
            dp[i - 1][2]  // stay inside the skipped segment.
        );

        // post skipped era.
        dp[i][3] = max(
            f(dp[i - 1][3], a[i]), // skipped seg closed already, so continue it.
            f(dp[i - 1][2], a[i])  // will close seg at i-1, will now start post skipped.
        );
    }

    cout << max(dp[n][2], dp[n][3]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve2();
    }
    return 0;
}