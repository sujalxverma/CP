#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<ll, ll> m;
    ll s = 0;
    m[0] = 1; // empty prefix sum
    for (int i = 0; i < n; i++)
    {
        a[i] *= ((i % 2) ? -1 : 1); // alternate sign inline
        s += a[i];                  // running prefix sum
        if (m[s])
        { // if prefix already seen
            cout << "YES\n";
            return;
        }
        ++m[s];
    }
    cout << "NO\n";
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
}
