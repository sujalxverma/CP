#include "bits/stdc++.h"
using namespace std;
#define int long long
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, int> mp;
    int c = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                mp[i]++;
                n = n / i;
            }
        }
    }
    if (n > 1)
    {
        mp[n]++;
    }
    int ans = 0;
    for (auto [x, y] : mp)
    {
        for (int i = 1; i <= 1000; i++)
        {
            if (i <= y)
            {
                ans++;
                y -= i;
            }
            else
            {
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}