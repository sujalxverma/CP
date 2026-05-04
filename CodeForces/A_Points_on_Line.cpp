#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;

    for (long long i = 0; i < n; i++) {
        long long s = a[i];
        long long e = a[i] + k;
        auto id = upper_bound(begin(a), end(a), e);
        long long idx = 0;
        if (id == a.end()) {
            idx = n - 1;
        } else {
            idx = id - a.begin() - 1;
        }

        // now count number of polong longs by taking as first polong long, and then select two more polong longs.
        long long diff = (idx - i);
        ans += (diff * (diff - 1)) / 2;
    }
    cout << ans << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}