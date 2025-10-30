#include "bits/stdc++.h"
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 2);
    for (ll i = 0; i < n + 2; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll last_1 = a[n + 1];
    ll last_2 = a[n];

    // with last_1
    ll sum1 = 0;
    for (ll i = 0; i < n + 1; i++)
    {
        sum1 += a[i];
    }
    for (ll i = 0; i < n + 1; i++)
    {
        if (sum1 - a[i] == last_1)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == j)
                    continue;
                cout << a[j] << " ";
            }
            cout << endl;
            return;
        }
    }

    sum1 = 0;
    for (ll i = 0; i < n; i++)
    {
        sum1 += a[i];
    }
    if (sum1 == last_2)
    {
        for (ll i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }

    cout << -1 << "\n";
    return;
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