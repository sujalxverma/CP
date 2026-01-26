#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // using SQRT Decomposition.
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll blocks = floor(sqrt(n));
    ll len = (n + blocks - 1) / blocks;
    vector<ll> st(len);

    for (ll i = 0; i < n; i++)
    {
        st[i / blocks] += a[i];
    }
    // for(int i = 0 ; i < blocks  ; i ++){
    //     cout<<st[i]<<"\n";
    // }

    // return 0;
    while (q--)
    {
        int k;
        cin >> k;
        if (k == 1)
        {
            // update
            ll idx, val;
            cin >> idx >> val;
            idx--;
            ll prev_value = a[idx];
            a[idx] = val;
            st[idx / blocks] += (a[idx] - prev_value);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            l--;
            r--;
            ll sum = 0;
            for (ll i = l; i <= r;)
            {
                if (i % blocks == 0 && i + blocks - 1 <= r)
                {
                    sum += st[i / blocks];
                    i += blocks;
                }
                else
                {
                    sum += a[i];
                    i++;
                }
            }
            cout << sum << "\n";
        }
    }
    return 0;
}