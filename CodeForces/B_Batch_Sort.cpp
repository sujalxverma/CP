#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

/*
Total possible swaps : [0 to n+1].
Only one column swap is allowed.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            vector<vector<int>> g = a;
            // swap columns.
            for (int k = 0; k < n; k++) {
                swap(g[k][i], g[k][j]);
            }
            bool f = true;
            // now for row swaps.
            for (int k = 0; k < n; k++) {
                int swaps = 0;
                for (int kt = 0; kt < m; kt++) {
                    if (g[k][kt] != (kt + 1)) {
                        swaps++;
                    }
                }
                if (swaps == 0) {
                    // no problem.
                } else if (swaps == 2) {
                    // no problem.
                } else {
                    f = false;
                }
            }
            if (f) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    bool f = true;
    vector<vector<int>> g = a;
    // now for row swaps.
    for (int k = 0; k < n; k++) {
        int swaps = 0;
        for (int kt = 0; kt < m; kt++) {
            if (g[k][kt] != (kt + 1)) {
                swaps++;
            }
        }
        if (swaps == 0) {
            // no problem.
        } else if (swaps == 2) {
            // no problem.
        } else {
            f = false;
        }
    }
    if (f) {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}