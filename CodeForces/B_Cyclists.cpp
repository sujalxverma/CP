#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
vector<int> a;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        int n, k, p, m;
        cin >> n >> k >> p >> m;
        a.resize(n);

        for (auto &x : a)
            cin >> x;

        if (k == n) {
            cout << (m / a[p - 1]) << "\n";
            continue;
        }

        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = i + 1;
        }

        int cnt = 0;
        int cost = 0;
        while (cost <= m) {
            int idx = -1;
            vector<int> c = b;
            for (int i = 0; i < k; i++) {
                if (c[i] == p) {
                    idx = i;
                    break;
                }
            }
            if (idx != -1) {
                c[idx] = -1;
                if (cost + a[p - 1] <= m) {
                    cnt++;
                    // cout << "Y ";
                    cost += a[p - 1];
                    vector<int> d;
                    for (int i = 0; i < n; i++) {
                        if (idx == i)
                            continue;
                        d.push_back(c[i]);
                    }
                    d.push_back(p);
                    b = d;

                } else {
                    break;
                }
            }

            else {
                int v = 1e9;
                for (int i = 0; i < k; i++) {
                    if (a[c[i] - 1] < v) {
                        v = a[c[i] - 1];
                        idx = i;
                    }
                }
                // c[idx] = -1;
                vector<int> d;
                cost += a[c[idx] - 1];
                for (int i = 0; i < n; i++) {
                    if (idx == i)
                        continue;
                    d.push_back(c[i]);
                }
                d.push_back(c[idx]);
                b = d;
            }
        }
        // cout << "\n";
        cout << cnt << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}