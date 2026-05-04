#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
const int inf = 1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> dp(n + 1, 0);

    if (n >= a) {
        dp[a] = 1;
    }
    if (n >= b) {
        dp[b] = 1;
    }
    if (n >= c) {
        dp[c] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (i - a >= 0 && dp[i - a] > 0) {
            dp[i] = max(dp[i - a] + 1, dp[i]);
        }
        if (i - b >= 0 && dp[i - b] > 0) {
            dp[i] = max(dp[i - b] + 1, dp[i]);
        }
        if (i - c >= 0 && dp[i - c] > 0) {
            dp[i] = max(dp[i - c] + 1, dp[i]);
        }
    }

    cout << dp[n] << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}