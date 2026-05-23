#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    // each tube must be 2 units long.
    bool f = 0; // 1 -> l to r, 0 -> r to l
    int size = 0;
    vector<pair<int, int>> store;
    for (int i = 1; i <= n; i++) {
        if (f == 0) {
            // l to r
            for (int j = 1; j <= m; j++) {
                if (k > 1) {
                    if (size <= 1) {
                        store.push_back({i, j});
                        size++;
                    } else {
                        cout << size << " ";
                        for (auto &[x, y] : store) {
                            cout << x << " " << y << " ";
                        }
                        cout << "\n";
                        store.clear();
                        k--;
                        store.push_back({i, j});
                        size = 1;
                    }
                } else {
                    store.push_back({i, j});
                }
            }
            f = 1;
        } else {
            // r to l
            for (int j = m; j >= 1; j--) {
                if (k > 1) {
                    if (size <= 1) {
                        store.push_back({i, j});
                        size++;
                    } else {
                        cout << size << " ";
                        for (auto &[x, y] : store) {
                            cout << x << " " << y << " ";
                        }
                        cout << "\n";
                        store.clear();
                        k--;
                        store.push_back({i, j});
                        size = 1;
                    }
                } else {
                    store.push_back({i, j});
                }
            }
            f = 0;
        }
    }
    cout << (int)store.size() << " ";
    for (auto &[x, y] : store) {
        cout << x << " " << y << " ";
    }
    cout << "\n";

    return 0;
}