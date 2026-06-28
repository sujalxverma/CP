#include "bits/stdc++.h"
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<vector<int>> dp;
    dp.push_back({h[0], 0});

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = b[i];
    }

    for (int i = 1; i < n; i++) {
        if (dp.back()[0] < h[i]) {
            ans[i] = max(ans[i], ans[dp.back()[1]] + b[i]);
            dp.push_back({h[i], i});
        } else {
            auto idx = lower_bound(begin(dp), end(dp), h[i],
                                   [](const vector<int> &a, int x) {
                                       return a[0] < x;
                                   });

            if (ans[(*idx)[1]] + b[i] - b[(*idx)[1]] > ans[(*idx)[1]]) {
                ans[i] = max(ans[i], ans[(*idx)[1]] + b[i] - b[(*idx)[1]]);
                *idx = {h[i], i};
            }
        }
    }

    cout << *max_element(begin(ans), end(ans)) << "\n";

    return 0;
}
