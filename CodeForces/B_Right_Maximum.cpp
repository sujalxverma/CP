#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> f(n + 1);
    for (int i = 0; i < n; i++) {
        f[a[i]].push_back(i + 1);
    }
    int steps = 0;
    int idx = n + 1;
    for (int i = n; i >= 1; i--) {
        vector<int> v = f[i];
        if (v.size() == 0)
            continue;
        for (int j = (int)v.size() - 1; j >= 0; j--) {
            if (v[j] < idx) {
                idx = v[j];
                steps++;
            }
            if (idx == 1) {
                cout << steps << "\n";
                return;
            }
        }
    }
    cout << steps << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}