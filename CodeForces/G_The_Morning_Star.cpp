#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<pair<long long, long long>> p(n);
        map<long long, long long> mp_x;
        map<long long, long long> mp_y;
        map<long long, long long> mp_slope_pos;
        map<long long, long long> mp_slope_neg;
        for (auto &[x, y] : p)
        {
            cin >> x >> y;
            mp_x[x]++;
            mp_y[y]++;
            mp_slope_pos[x - y]++;
            mp_slope_neg[x + y]++;
        }

        long long ans = 0;
        for (auto &[x, y] : mp_x)
        {
            ans += 1LL*(y * (y - 1));
        }
        for (auto &[x, y] : mp_y)
        {
           ans += 1LL*(y * (y - 1));
        }
        for (auto &[x, y] : mp_slope_pos)
        {
            ans += 1LL*(y * (y - 1));
        }
        for (auto &[x, y] : mp_slope_neg)
        {
            ans += 1LL*(y * (y - 1));
        }

        cout << ans << "\n";
    }
    return 0;
}