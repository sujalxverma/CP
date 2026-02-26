#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<ll> a;
int n;
ll x;

namespace BinarySearch
{
    bool f(ll mid)
    {
        ll water = 0;
        for (int i = 1; i <= n; i++)
        {
            water += max(0LL, mid - a[i]);
            if(water > x){
                return false;
            }
        }

        if (water <= x)
        {
            return true;
        }
        return false;
    }
}

using namespace BinarySearch;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> x;
        a.resize(n + 1);
        for (auto i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        ll s = 0;
        ll e = 1e18;
        ll ans = 0;
        while (s <= e)
        {
            ll mid = s + (e - s) / 2;

            if (f(mid))
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}