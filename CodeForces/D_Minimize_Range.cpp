#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;

    sort(begin(a), end(a));
    long long ans = a[n - 1] - a[0]; // upper limit
    for (int i = 0; i < n - 1; i++) {
        while (a[i] + k <= a[n - 1]) {
            a[i] += k;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, abs(a[i] - a[n - 1]));
        a[i] += k;
        ans = min(ans, abs(a[i] - a[n - 1]));
    }

    cout << ans << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}