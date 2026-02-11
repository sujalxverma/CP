#include "bits/stdc++.h"
using namespace std;
vector<int> a;
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
        vector<int> dp(n + 1, 1e9);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            dp[a[i]] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            if (dp[i] == 1)
                continue;
            int num = i;
            for (int j = 1; j * j <= num; j++)
            {
                if (num % j == 0)
                {
                    dp[i] = min(dp[i], dp[j] + dp[num / j]);
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