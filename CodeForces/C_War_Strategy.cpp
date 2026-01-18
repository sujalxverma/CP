#include "bits/stdc++.h"
using namespace std;
using ll = long long;

/*
1. First, i try to solve it using binary search, but i was wrongly assuming, that soldier do not increase
    in base camp. This fails.
2. So, i somehow figured out the editorial approach, but what i was doing, i was trying to forumulate it.
3. In editorial, it gradually increase sides, and it is amazing.
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;

        ll a = 0;
        ll b = 0;
        bool f = true;
        if (k - 1 < n - k)
        {
            k = n - k + 1;
        }
        while ((a + b + max(a, b) - 1) <= m)
        {

            if (f)
            {
                if ((a < k - 1) && ((a + 1 + b + max(a + 1, b) - 1 <= m)))
                {
                    a++;
                }
                else
                {
                    break;
                }

                f = false;
            }
            else
            {
                if ((b < n - k) && ((a + b + 1 + max(a, b + 1) - 1 <= m)))
                {
                    b++;
                }
                // else{
                //     break;
                // }
                f = true;
            }
        }
        cout << a + b + 1 << "\n";
    }
    return 0;
}