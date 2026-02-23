#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll maxN = 2e5 + 10;

ll sum_of_number(ll n)
{
    ll s = 0;
    while (n > 0)
    {
        s += (n % 10);
        n = n / 10;
    }
    return s;
}

vector<ll> precompute()
{
    vector<ll> f(maxN);
    f[0] = 0;
    for (int i = 1; i <= maxN; i++)
    {
        f[i] = f[i - 1] + sum_of_number(i);
    }
    return f;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<ll> f = precompute();
    while (t--)
    {
        int n;
        cin >> n;
        cout << f[n] << "\n";
    }
    return 0;
}