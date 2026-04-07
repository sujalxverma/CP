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
        int x, y;
        cin >> x >> y;
        // x->even , y->odd
        if (((x + y) % 2 == 0 && x == 0) || (x + y) % 2 == 1 && y == 0) {
            cout << "NO\n";
            continue;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}