#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int l, r, d, u;
    cin >> l >> r >> d >> u;

    /*
    max(|x| , |y|) -> even -> black, else white
    Divide the plane into 4 cartesian blocks.
    Assuming that l,r,d,u are spreased in all 4 cartesian blocks, if not then also no problem.
    */
    long long ans = 0;
    // x >= 0 && y >= 0
    if (l <= 0 && 0 <= r) {
        // x coordinates are both in neg and pos sides.
        if (d <= 0 && 0 <= u) {
            // y coordinates are both in neg and pos sides.
            for (int i = 0; i <= r; i++) {
                ans += (u + 1) / 2;
                ans += (abs(d) - 1) / 2;
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}