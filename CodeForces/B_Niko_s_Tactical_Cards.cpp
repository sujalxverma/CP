#include "bits/stdc++.h"
using namespace std;
using ll = long long;

/*
1. To take blue case in ith , we need k to be min, as to maximize (bi - k).
2. To take red case in ith, k should be maxi.
3. for every ith, maxi = max(maxi - a[i] , b[i] - mini );
4. mini = max(mini - a[i] , b[i] - maxi ); , to get minium effect.
5. Atlast maxi is the final answer.
*/

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];

    ll mini = 0;
    ll maxi = 0;

    for (ll i = 0; i < n; i++)
    {
        ll nmaxi = max(maxi - a[i], b[i] - mini);
        ll nmini = min(mini - a[i], b[i] - maxi);
        maxi = nmaxi;
        mini = nmini;
    }
    cout << maxi << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
