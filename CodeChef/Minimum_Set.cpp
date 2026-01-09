#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll f(ll s, ll n, ll k)
{
    if (n <= 1)
    {
        return 0;
    }
    return (1LL << k) + (n == (1LL << k)) + f(1, (1LL << k) - 1, k - 1) + f(0, n - (1LL << k) - 1, k - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll k = 0;
        if(n <= 3){
            cout<<3<<"\n";
            continue;
        }
        while ((1LL << k) <= n)
        {
            k++;
        }
        k--;
        ll ans = f(1, n, k);
        cout << ans << "\n";
    }
    return 0;
}