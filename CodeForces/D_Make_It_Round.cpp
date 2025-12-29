#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll find(ll num, ll opr, ll digit)
{
    ll ans = 0;
    ll tens = 1;
    for (int i = 1; i <= digit; i++)
    {
        tens *= 10;
    }
    for (int i = 1; i <= opr; i++)
    {
        if ((num * i) % tens == 0)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        ll ans = 0;
        bool f = true;
        ll c = 1;
        while (f)
        {

            ll digits = find(n, m, c);
            // cout<<digits<<"\n";
            if (digits == 0)
            {
                break;
            }
            else
            {
                ans = ((n * digits) * (m / (digits)));
                n = n * digits;
                m = m / digits;
                c++;
            }
        }

        if (ans == 0)
        {
            ans = n * m;
        }
        cout << ans << "\n";
    }
    return 0;
}