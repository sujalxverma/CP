#include "bits/stdc++.h"
using namespace std;

using ll = long long;
// const ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        int o = 0, tw = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                o++;
            else
                tw++;
        }

        if (o == n)
        {
            for (int i = 2; i <= n + 1; i++)
            {
                ll x = 1LL * i * (i + 1) / 2;
                cout << (x) << " ";
            }
            cout << "\n";
        }
        else if (tw == n)
        {
            for (int i = 0; i < n; i++)
                cout << "0 ";
            cout << "\n";
        }
        else
        {
            vector<ll> fr(n + 1, 0);
            fr[0] = 1;

            ll inv = 0;
            ll mex = 0;
            ll size = 1;

            for (int i = 0; i < n; i++)
            {
                if (a[i] == 1)
                {
                    mex++;
                    size = (size + 1);

                    fr[mex] = (fr[mex] + 1);
                    inv = (inv + size - 1);

                    cout << inv << " ";
                }
                else
                {
                    size = (size * 2);

                    if (mex == 0)
                    {
                        fr[0] = (fr[0] * 2);
                        inv = (inv * 2);
                        cout << inv << " ";
                        continue;
                    }

                    inv = (inv * 2);

                    ll cnt = 0;
                    for (int j = 1; j <= mex; j++)
                    {
                        cnt = (cnt + fr[j - 1]);
                        inv = (inv + cnt * fr[j]);
                    }

                    for (int j = 0; j <= mex; j++)
                        fr[j] = (fr[j] * 2);

                    cout << inv << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
