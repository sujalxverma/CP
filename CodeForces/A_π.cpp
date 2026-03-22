#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
const double pi = 3.141592653589793;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    double d;
    cin >> d;
    double ans = pi * (d / 2) * (d / 2);

    cout << fixed << setprecision(15) << ans << "\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}