#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<ll> a, b , pref;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        a.resize(n);
        b.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        pref.resize(n+1);

        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + b[i - 1];
        }

       
        sort(a.begin(), a.end());

      
        vector<ll> vals = a;
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        ll ans = 0;

      
        for (ll x : vals) {
           
            auto it = lower_bound(a.begin(), a.end(), x);
            ll hits = (ll)(a.end() - it);

            if (hits == 0) continue;

          
            int k = upper_bound(pref.begin(), pref.end(), hits) - pref.begin() - 1;

            ll score = x * (ll)k;
            ans = max(ans, score);
        }

        cout << ans << "\n";
    }
    return 0;
}
