#include "bits/stdc++.h"
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;
vector<double> c, p;
int n;

double f(int idx, double s) {
    if (idx >= n) {
        return 0.0;
    }

    double nottake = f(idx + 1, s);
    double take = s * c[idx] + f(idx + 1, s * (1 - (p[idx] / 100)));

    return max(nottake, take);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        c.resize(n);
        p.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> c[i] >> p[i];
        }
        double s = 1; // starting value = 1.
        double ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans = max(ans, c[i] + ans * (1 - (p[i] / 100)));
        }
        cout << fixed << setprecision(10) << ans << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}