#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;

    if (n % 2 == 0) {
        cout << n/2 << " " << n/2 << "\n";
        return;
    }

    ll best = 1;

    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i <= n/2) best = max(best, i);
            if (n/i <= n/2) best = max(best, n/i);
        }
    }

    cout << best << " " << n - best << "\n";
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}