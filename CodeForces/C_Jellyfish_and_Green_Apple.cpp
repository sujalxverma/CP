#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if ((int)n % (int)m == 0) {
            cout << "0\n";
            continue;
        }

        int rem = n - m * (n / m);
        int g = gcd(rem, m);
        int b = m / g;

        if ((b & (b - 1)) != 0) {
            cout << "-1\n";
            // not possible to divide.
            continue;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}