#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll inf = 1e12 + 1;

/*
1. Using BS on Answers.
2. Suppose m is the kth element.
3. Now in each iteration, the length is decreased by floor(len/y).
4. After completion, len > m. then reduce end, else increase begin.
*/


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y, k;
        cin >> x >> y >> k;
        ll s = 1;
        ll e = inf;
        ll ans = -1;
        while (s <= e)
        {
            ll m = s + (e - s) / 2;
            ll len = m - 1;
            for (int i = 0; i < x; i++)
            {
                len -= (len / y);
            }

            if (len + 1 > k)
            {
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        if (e == inf)
        {
            cout << "-1\n";
            continue;
        }
        cout << e << "\n";
    }
    return 0;
}