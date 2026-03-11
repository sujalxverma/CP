#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
using ll = long long;

/*
- Using BS, to find largest index such that it will pref <= suff.
- Because after this index, the pref > suff.
- So either answer is to that index, min(pref-fuff , suff-pref), as polarity switches.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        ll total = n * (2 * k + n - 1) / 2;

        ll s = 0;
        ll e = n - 1;
        ll idx = -1;

        while (s <= e) {
            ll i = s + (e - s) / 2;

            ll pref = (i + 1) * (2 * k + i) / 2;
            ll suff = total - pref;

            if (pref <= suff) {
                idx = i;
                s = i + 1;
            } else {
                e = i - 1;
            }
        }

        auto calc = [&](ll i) {
            if (i < 0 || i > n - 1) {
                return (ll)4e18;
            }
            ll pref = (i + 1) * (2 * k + i) / 2;
            ll suff = total - pref;
            return abs(pref - suff);
        };

        cout << min(calc(idx), calc(idx + 1)) << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}