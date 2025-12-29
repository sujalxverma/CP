#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<ll> f;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            f.push_back(i);
            if (n / i != i)
            {
                f.push_back(n / i);
            }
        }
    }
    sort(begin(f), end(f));
    if ((int)f.size() >= k)
    {
        cout << f[k - 1] << "\n";
    }
    else
    {
        cout << "-1\n";
    }
    return 0;
}