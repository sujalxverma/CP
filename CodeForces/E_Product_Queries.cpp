#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<ll> a;
/*
1. Use of DP.
2. Say, create a DP of size n [1 to n].
3. For all values which are <= n, and present in array, then mark it as 1. Means they can be computed 
   only using 1 number, which is itself.
4. For all values which are left, mark them INF.
5. Now start iterating from 1 to n.
6. For all factors of num (1 <= num <= n).
7. say if, factor =  k divides num, then its counter part  = (num/k), can be used as product to form num.
8. it means dp[num] = min(dp[num] , 1 + dp[num/k]).
9. Why this formula ? But we have to also check that factor k exist in array.
10. So, simply replace formula with: dp[num] = min(dp[num] , dp[k] + dp[num/k]).
11. if k exist, then dp[k] != INF, same for dp[num/k].
*/
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
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        vector<ll> dp(n + 1, 1e9);
        for (int i = 1; i <= n; i++)
        {
            if (a[i] <= n)
            {
                dp[a[i]] = 1;
            }
        }

        for (int i = 1; i <= n; i++)
        {

            ll num = i;
            if (dp[num] == 1)
            {
                continue;
            }
            for (int j = 1; j * j <= num; j++)
            {
                if (num % j == 0)
                {
                    dp[num] = min(dp[num], dp[j] + dp[num / j]);
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {

            cout << (dp[i] == 1e9 ? -1 : dp[i]) << " ";
        }
        cout << "\n";
    }
    return 0;
}