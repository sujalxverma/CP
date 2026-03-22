#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int h, w, q;
    cin >> h >> w >> q;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        int cost = 0;
        if (type == 1) {
            // row
            int r;
            cin >> r;
            for (int i = h - r + 1; i <= h; i++) {
                for (int j = 1; j <= w; j++) {
                    cost++;
                }
            }
            h = h - r;
            cout << cost << "\n";
        } else {
            // col
            int c;
            cin >> c;

            for (int i = w - c + 1; i <= w; i++) {
                for (int j = 1; j <= h; j++) {
                    cost++;
                }
            }
            w = w - c;
            cout << cost << "\n";
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}