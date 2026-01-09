#include "bits/stdc++.h"
using namespace std;
using ll = long long;

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
        int bits = floor(log2(m)) + 1;
        set<ll> s;
        s.insert(n);
        for (int i = 0; i < bits; i++)
        {
            if (!((1LL << i) & n))
            {
                // unset bit.
                ll val = (1LL << i) | n;
                s.insert(val);
            }
        }

        int ans = 0;
        for (auto &x : s)
        {
            if (x <= m)
            {
                ans++;
            }
        }
        if (ans <= 1)
        {
            cout << "-1\n";
        }
        else
        {
            cout << ans << "\n";
            for (auto &x : s)
            {
                if (x > m)
                    continue;
                cout << x << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}