#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int n, x;
    cin >> n >> x;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        if (d < x) {
            x = d;
            a.push_back(1);
        } else {
            a.push_back(0);
        }
    }

    for (auto &x : a) {
        cout << x << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}