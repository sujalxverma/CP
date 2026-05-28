#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<vector<int>> g;
        for (auto &x : a) {
            cin >> x;
        }
        for (int i = 0; i < n; i++) {
            vector<int> c;
            for (int j = i; j < n; j++) {
                c.push_back(a[j]);
                g.push_back(c);
            }
        }
        int cnt = 0;
        for (auto &x : g) {
            // will greddily check for all subarrays.
            if (static_cast<int>(x.size()) == 1) {
                cnt++;
            } else {
                x[0] = 0;
                bool f = true;
                for (int i = 1; i < static_cast<int>(x.size()); i++) {
                    if (x[i - 1] < x[i]) {
                        int v = x[i - 1] + 1;
                        if (v == x[i]) {

                        } else {
                            int k = x[i] - v;
                            if (x[i] % k == v) {
                                x[i] = v;
                            }
                        }
                    } else {
                        f = false;
                    }
                }
                if (f) {
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}