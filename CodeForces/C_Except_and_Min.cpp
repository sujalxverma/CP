#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &X : a)
        cin >> X;
    vector<int> c = a;
    sort(begin(c), end(c));
    while (q--) {
        int k;
        cin >> k;
        vector<int> b(k);
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            b[i] = a[x - 1];
        }
        // traverse in c.
        int idx = 0;
        bool f = false;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < k; i++) {
                if (c[j] == b[i]) {
                    f = true;
                    b[i] = -100;
                    break;
                }
            }
            if (!f) {
                idx = j;
                break;
            }
            f = false;
        }
        cout << c[idx] << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}