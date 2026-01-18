#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll a = 0;
        ll b = 0;

        for (ll j = i; j < n; j++)
        {
            if (s[j] == 'A')
            {
                a++;
            }
            else if (s[j] == 'B')
            {
                b++;
            }

            if (a > b)
            {
                ans++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}