#include "bits/stdc++.h"
using namespace std;

/*
If, x >= 4*gcd , then it can be split into 3 numbers. which will not affect overall gcd.

*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> mp;
        for (auto &x : a)
        {
            cin >> x;
            mp[x]++;
        }
        sort(a.begin(), a.end());
        int ans = 1;
        for (int g = 2; g <= n; g++)
        {
            auto idx = lower_bound(a.begin(), a.end(), 4 * g);
            if (idx == a.end())
            {
                if (mp[2 * g] + mp[3 * g] + mp[g] >= n - k)
                {
                    ans = g;
                }
            }
            else
            {
                if (n - (idx - a.begin()) + mp[2 * g] + mp[3 * g] + mp[g] >= n - k)
                {
                    ans = g;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}