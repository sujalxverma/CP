#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<ll> a, b, c;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, h;
        cin >> n >> m >> h;
        a.resize(n);
        b.resize(m);
        c.resize(m);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            ll u, v;
            cin >> u >> v;
            b[i] = u;
            c[i] = v;
        }
        vector<ll> copied = a;
        if (n == 1)
        {
            for (int i = 0; i < m; i++)
            {
                int idx = b[i] - 1;
                a[idx] += c[i];
                if (a[idx] > h)
                {
                    a[idx] = copied[0];
                }
            }
            for (auto &x : a)
            {
                cout << x << " ";
            }
            cout << "\n";
            continue;
        }
        //
        // int idx = -1;

        vector<int> reset(n, 0);
        int r = 0;
        for (int i = 0; i < m; i++)
        {
            int idx = b[i] - 1;
            if (r > reset[idx])
            {
                a[idx] = copied[idx];
                a[idx] += c[i];
                reset[idx] = r;
                if (a[idx] > h)
                {
                    r++;
                }
            }
            else
            {
                // a[idx] = copied[idx];
                a[idx] += c[i];
                reset[idx] = r;
                if (a[idx] > h)
                {
                    r++;
                }
            }
        }
        for(int i = 0; i < n ; i++){
            if(reset[i] < r){
                cout<<copied[i]<<" ";
                continue;
                
            }
            cout<<a[i]<<" ";
        }
        cout << "\n";
    }
    return 0;
}