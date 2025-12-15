#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        ll a, b;
        cin >> a >> b;

        // simple case
        // if (b == 1) {
        //     if(a%10 == 0){
        //         cout << ((a * (a + 1)) / 2) - a << "\n";
        //         continue;
        //     }
        //     cout << (a * (a + 1)) / 2 << "\n";
        //     continue;
        // }

        // Build cycle of (i*b)%10
        vector<ll> seq;
        bool seen[10] = {false};
        ll i = 1;
        ll sum = 0;

        while (true) {
            ll v = (i * b) % 10;
            if (seen[v]) break;    // cycle found
            seen[v] = true;
            seq.push_back(v);
            sum += v;
            i++;
        }

        ll f = a / b;              // how many terms to use
        ll times = f / seq.size(); // full cycles
        ll rem   = f % seq.size(); // leftover

        ll ans = times * sum;

        for (int i = 0; i < rem; i++)
            ans += seq[i];

        cout << ans << "\n";
    }

    return 0;
}
