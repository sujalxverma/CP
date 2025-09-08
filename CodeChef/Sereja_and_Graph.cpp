#include "bits/stdc++.h"
using namespace std;
#define ll long long
ll a[105][105];
ll v[105];
ll d[105];
int main()
/*
    1. first create adjacency matrix for the undirected graph.
    2. Then store degree of each vertex in array d.
    3. for odd vertices, its not possible.
*/

{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll i, j;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                a[i][j] = 0, v[i] = 0, d[i] = 0;
        ll u, V;
        for (j = 1; j <= m; j++)
        {
            cin >> u >> V;
            a[u][V] = 1;
            a[V][u] = 1;
        }
        ll p = 0;
        for (i = 1; i <= n; i++)
        {
            p = 0;
            for (j = 1; j <= n; j++)
            {
                p += a[i][j];
            }
            d[i] = p;
        }
        if (n % 2 == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        //   for(i=1;i<=n;i++)
        //  cout<<d[i]<<" ";cout<<endl;
        ll c = 0;
        ll max;
        bool f;
        while (c != n)
        {
            max = 100000;
            ll k, x, y, z;
            f = 0;
            for (i = 1; i <= n; i++)
                if (!v[i] && (d[i] < max))
                {
                    k = i, max = d[i];
                }

            v[k] = 1;
            c++;
            max = 100000;
            for (i = 1; i <= n; i++)
                if (!v[i] && a[k][i] && (d[i] < max))
                {
                    x = i;
                    max = d[i];
                    f = 1;
                }
            if (!f)
                break;
            v[x] = 1;
            c++;
            for (i = 1; i <= n; i++)
            {
                if (a[k][i])
                {
                    d[i]--;
                    a[k][i] = 0;
                }
                if (a[x][i])
                {
                    d[i]--;
                    a[x][i] = 0;
                }
            }
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}