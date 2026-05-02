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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<vector<int>> pos(n + 1);
        for (int i = 0; i < n; i++) {

            int num = a[i];
            for (int j = 1; j <= num; j++) {
                pos[j].push_back(i + 1);
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << pos[i].size() << "\n";
        }
        continue;
        int moves = 0;
        int full = 0;
        for (int i = 1; i <= n; i++) {
            if (pos[i].size() == n) {
                full++;
                continue;
            }
            if (pos[i].size() == 0) {
                continue; // no movement possible.
            }
            for (int j = 0; j < (int)pos[i].size(); j++) {
                int k = (pos[i].size());
                if (pos[i][k - 1] != n) {
                    moves += k;
                    // cout << i << " " << k << "\n";
                    break;
                    // all blocks will shift.
                } else {
                    // need to count how many will shift.
                    int count = 0;
                    int idx = n;
                    for (int m = k - 1; m >= 0; m--) {
                        if (pos[i][m] == idx) {
                            count++;
                            idx--;
                        } else {
                            break;
                        }
                    }
                    moves += (k - count);
                }
            }
        }

        if (full > 0) {
            moves += (n - 1);
        }
        cout << moves << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}