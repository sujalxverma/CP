#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<int> s;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }

        // if ((int)s.size() == n) {
        //     for (int i = 1; i <= n; i++) {
        //         cout << n - 2 << " ";
        //     }
        //     cout << "\n";
        //     continue;
        // }

        sort(begin(a), end(a));
        a.erase(unique(begin(a), end(a)), end(a));
        int m = (int)a.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < m; i++) {
            mp[a[i]] = 1;
        }

        vector<int> dp(n + 1, 1);
        vector<int> dp2(n + 1, 1);
        bool f = false;
        int idx = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (mp.count(i)) {
                // this key is present.
                if (mp.count(i + 1)) {
                    // next key also present.
                    dp[i] = dp[i + 1] + 1;
                    if (dp[i] >= 4) {
                        f = true;
                        idx = i;
                        break;
                    }
                } else {
                    // dp[i] = dp[i + 1];
                    dp[i] = 1;
                }
            } else {
                dp[i] = dp[i + 1];
            }
        }
        for (int i = idx; i >= 1; i--) {
            dp[i] = 4;
        }
        f = false;
        for (int i = n - 1; i >= 0; i--) {
            if (mp.count(i)) {
                // this key is present.
                if (mp.count(i + 2)) {
                    // next key also present.
                    dp2[i] = dp2[i + 1] + 1;
                    if (dp2[i] >= 2) {
                        f = true;
                        idx = i;
                        break;
                    }
                } else {
                    // dp[i] = dp[i + 1];
                    dp2[i] = 1;
                }
            } else {
                dp[i] = 1;
            }
        }
        for (int i = idx; i >= 1; i--) {
            dp2[i] = 2;
        }

        for (int i = 1; i <= n; i++) {
            // cout << dp[i] << " ";
        }

        for (int i = 1; i <= n; i++) {
            if (dp[i] >= 4) {
                cout << m - 2 << " ";
            } else if (dp2[i] >= 2) {
                cout << m - 1 << " ";
            } else {
                cout << m << " ";
            }
        }
        cout << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}