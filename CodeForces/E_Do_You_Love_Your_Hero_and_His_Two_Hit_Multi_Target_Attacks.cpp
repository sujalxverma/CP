#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

/*
Manhattan Distance == Euclidean Distance, only when either x or y coordinate is same.

N points, then number of pairs : (N * (N-1))/2
If N = 500 , then pairs = 1,24,750
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 0) {
            cout << "2\n";
            cout << "1 3\n";
            cout << "3 10\n";
            continue;
        }

        int xCor = 1;
        int yCor = 1;
        vector<pair<int, int>> points;
        while (n > 0) {
            int maxVal = 0;
            for (int k = 1; k <= 2 * n; k++) {
                if (k * (k - 1) <= 2 * n) {
                    maxVal = k;
                } else if (k * (k - 1) > 2 * n) {
                    break;
                }
            }
            // maxVal -> number of points.
            for (int i = 1; i <= maxVal; i++) {
                points.push_back({xCor, yCor});
                yCor++;
            }
            n -= maxVal * (maxVal - 1) / 2;
            xCor++;
        }
        cout << (int)points.size() << "\n";
        for (auto &[x, y] : points) {
            cout << x << " " << y << "\n";
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}