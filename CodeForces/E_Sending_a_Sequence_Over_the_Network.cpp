#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
vector<int> a;
vector<char> dp;
int t, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        dp.assign(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            if ((i - a[i]) >= 1 && dp[i - a[i] - 1]) {
                dp[i] = 1;
            }

            if ((i + a[i]) <= n && dp[i - 1]) {
                dp[i + a[i]] = 1;
            }
        }

        cout << (dp[n] == 1 ? "YES\n" : "NO\n");
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}