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
        int n;
        cin >> n;
        vector<ll> a(n);
        ll odd = 0;
        ll even = 0;
        map<ll, ll> mp;
        for (auto &x : a)
        {
            cin >> x;
            if (x & 1)
                odd++;
            else
                even++;
            mp[x]++;
        }

        // remove all , a^a = 0.
        ll sub = 0;
        for (auto &it : mp)
        {
            if (it.second <= 1)
                continue;
            sub += (it.second * (it.second - 1)) / 2;
        }

        // remove a^b = 2.
        for (int i = 0; i < n; i++)
        {
            if (!mp.count(a[i] ^ 2))
                continue;
            sub += (mp[(a[i] ^ 2)] * mp[a[i]]);
            mp[a[i]] = 0;
        }

        cout << (even * (even - 1)) / 2 + (odd * (odd - 1)) / 2 - sub << "\n";
    }
    return 0;
}