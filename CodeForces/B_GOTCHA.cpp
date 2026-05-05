#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
const int mod = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> p(n, a[0]);
    for (int i = 1; i < n; i++) {
        int cal = 1;
        for (int j = 1; j <= i; j++) {
            (cal += a[i] % mod);
        }
        p[i] = (p[i - 1] + cal) % mod;
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == 0) {
            cout << p[r] << "\n";
        } else {
            cout << (p[r] - p[l - 1] + mod) % mod << "\n";
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}