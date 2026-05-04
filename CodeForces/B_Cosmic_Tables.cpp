#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    vector<int> rows(n), cols(m);
    for (int i = 0; i < n; i++) {
        rows[i] = i;
    }
    for (int j = 0; j < m; j++) {
        cols[j] = j;
    }
    while (q--) {
        char c;
        cin >> c;
        if (c == 'g') {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            cout << g[rows[x]][cols[y]] << "\n";
        }
        if (c == 'r') {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            swap(rows[x], rows[y]);
        }
        if (c == 'c') {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            swap(cols[x], cols[y]);
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}