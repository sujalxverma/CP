#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
vector<long> a;
long ans = 0;
double s = 0.5;
void f(long idx, double pos, long cross) {
    if (idx == (long)a.size()) {
        ans = max(cross, ans);
        return;
    }

    double newpos = pos + a[idx];
    // go right.
    if (pos <= 0 && 0 <= newpos) {
        f(idx + 1, newpos, cross + 1);
    } else {
        f(idx + 1, newpos, cross);
    }

    // go left.
    newpos = pos - a[idx];
    if (newpos <= 0 && 0 <= pos) {
        f(idx + 1, newpos, cross + 1);
    } else {
        f(idx + 1, newpos, cross);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    long n;
    cin >> n;
    a.resize(n);
    for (long i = 0; i < n; i++) {
        cin >> a[i];
    }

    f(0, s, 0);
    cout << ans << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}