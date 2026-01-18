#include "bits/stdc++.h"
using namespace std;
using ll = long long;

/*
1. For a fixed value of k^x , we have range that satisfies this condition.
2. We can find this high and low.
3. So, ans += high - low + 1
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        ll ans = 0;
        ll value = 1;
        for (ll i = 0; i <= 32; i++)
        {
            // k^i * x = y.
            // find smallest and largest x, which statisfies the condition.
            if(value > r2){
                break;
            }
           
            
            ll lower = (l2 + value - 1) / value;
            ll upper = r2 / value;
            ll low = max(lower, l1);
            ll high = min(upper, r1);
            if (low <= high)
            {
                ans += high - low + 1;
            }

             value *= k;
        }

        cout << ans << "\n";
    }
    return 0;
}