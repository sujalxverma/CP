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
    vector<int> a(m + 1, 0), b(m + 1, 0);

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        b[v]++;
        a[u]++;
    }
    for (int i = 1; i <= m; i++) {
        cout << b[i] - a[i] << "\n";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}