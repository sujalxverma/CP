#include "bits/stdc++.h"
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int k, p, q;
        cin >> k >> p >> q;
        if (p > q) {
            swap(p, q);
        }
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        vector<int> pf(n, 0), sf(n, 0);
        pf[0] = a[0] % p;
        sf[0] = (a[0] % q) % p;
        for (int i = 1; i < n; i++) {
            pf[i] = pf[i - 1] + (a[i] % p);
            sf[i] = sf[i - 1] + (a[i] % q) % p;
        }
        vector<int> s(n);
        s[0] = min(a[0] % p, (a[0] % q) % p);
        for (int i = 1; i < n; i++) {
            s[i] = s[i - 1] + min(a[i] % p, (a[i] % q) % p);
        }
        int ans = 1e18;
        for (int i = 0; i <= n - k; i++) {
            int val1 = pf[i + k - 1] - (i - 1 >= 0 ? pf[i - 1] : 0);
            int val2 = sf[i + k - 1] - (i - 1 >= 0 ? sf[i - 1] : 0);
            int outside = (i ? s[i - 1] : 0) + (s[n - 1] - s[i + k - 1]);
            int cur = outside + min(val1, val2);
            ans = min(ans, cur);
        }
        cout << ans << "\n";
    }

    return 0;
}