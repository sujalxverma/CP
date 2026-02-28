#include "bits/stdc++.h"
using namespace std;
const int inf = 1e9;
vector<int> a;
int n;
vector<int> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        a.resize(n);
        dp.assign(n + 2, inf);
        for (auto &x : a)
        {
            cin >> x;
            dp[x] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            if (dp[i] == 1)
            {

                continue;
            }

            for (int j = 1; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    dp[i] = min(dp[i], dp[i / j] + dp[j]);
                    // its possible that it requires, other numbers product to form j.
                    
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout << (dp[i] == inf ? -1 : dp[i]) << " ";
        }
        cout << "\n";
    }
    return 0;
}