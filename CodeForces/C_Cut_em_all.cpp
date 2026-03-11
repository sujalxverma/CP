#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto start = high_resolution_clock::now();

    int n;
    cin >> n;
    vector<vector<int>> g;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g.push_back({u, v});
    }

    if (n == 3) {
        cout << "-1\n";
        return 0;
    }

    if (n <= 2) {
        cout << "0\n";
        return 0;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}