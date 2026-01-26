#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<ll> a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        a.resize(n);
        b.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                a[i] = max(a[i], b[i]);
            }
            else
            {
                a[i] = max({a[i], b[i], a[i + 1]});
            }
        }

        vector<ll> s(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            s[i] = s[i - 1] + a[i-1];
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << s[r] - s[l - 1] << " ";
        
        }
        cout<<"\n";

    }
    return 0;
}