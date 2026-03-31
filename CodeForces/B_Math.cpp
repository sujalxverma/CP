#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto start = high_resolution_clock::now();
    ll n;
    cin >> n;
    ll value = 1;
    vector<pair<ll, ll>> factors;
    for (ll i = 2; i <= n; i++) {
        if (n % i == 0) {
            value *= i;
            ll s = 0;
            while (n % i == 0) {
                s++;
                n = n / i;
            }
            factors.push_back({i, s});
        }
    }
    ll maxi = 0;
    for (auto &[x, y] : factors) {
        maxi = max(maxi, y);
    }
    maxi = maxi + (maxi % 2);
    ll count = 0;
    for (auto &[x, y] : factors) {
        count += maxi - y;
    }

    if (count == 0) {
        cout << n << " " << 0 << "\n";
    } else {
        cout << value << " " << count + factors
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";
    return 0;
}