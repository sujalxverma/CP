#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

// Precompute powers of 2
vector<ll> pow2(1000001, 1);

void preC()
{
    for (int i = 1; i <= 1000001; i++)
    {
        pow2[i] = (pow2[i - 1] * 2) % mod;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    preC();
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        ll ans = 0;
        sort(a.begin() + 1, a.end());
        for (ll i = 1; i <= n; i++)
        {
            ans = (ans + a[i] * ((pow2[i - 1]) - 1)) % mod;
        }
        for (ll i = 1; i <= n; i++)
        {
            ans = (ans - a[i] * ((pow2[n - i]) - 1)) % mod;
        }
        if(ans < 0){
            ans = (ans + mod )%mod;
        }
        cout << ans << "\n";
    }
    return 0;
}