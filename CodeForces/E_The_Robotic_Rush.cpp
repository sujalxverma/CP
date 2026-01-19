#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<ll> a;
vector<ll> b;
const ll inf = -1e18;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        a.resize(n);
        b.resize(m);
        set<ll> pos;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
            pos.insert(b[i]);
        }
        string s;
        cin >> s;

        for (int i = 0; i < k; i++)
        {
            if (s[i] == 'L')
            {
                int count = 0;
                for (int j = 0; j < n; j++)
                {
                    if (a[j] == inf)
                    {
                        continue; // ignore
                    }
                    else
                    {
                        a[j] -= 1;
                    }
                }
                // check which survive
                for (int j = 0; j < n; j++)
                {
                    if (a[j] == inf)
                        continue;
                    if (pos.find(a[j]) != pos.end())
                    {
                        a[j] = inf;
                    }
                    else
                    {
                        count++;
                    }
                }

                cout << count << " ";
            }
            else
            {
                int count = 0;
                for (int j = 0; j < n; j++)
                {
                    if (a[j] == inf)
                    {
                        continue;
                    }
                    else
                    {
                        a[j] += 1;
                    }
                }
                // check which survive
                for (int j = 0; j < n; j++)
                {
                    if (a[j] == inf)
                        continue;
                    if (pos.find(a[j]) != pos.end())
                    {
                        a[j] = inf;
                    }
                    else
                    {
                        count++;
                    }
                }

                cout << count << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}