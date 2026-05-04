#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int n, m;
    cin >> n >> m;
    if (n < m) {
        swap(n, m);
    }
    // n >= m.

    if (n == m) {
        cout << n - 1 << " " << n << "\n";
    } else {
        int d = n - m;
        cout << (m - 1) + (d) << " " << m << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}