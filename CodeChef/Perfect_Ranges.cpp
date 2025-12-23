#include "bits/stdc++.h"
using namespace std;

long long f(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    vector<vector<long long>> dp(n, vector<long long>(2, 0));

    dp[0][0] = 1;
    dp[0][1] = 0;

    long long ans = 1;

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = 1;
        dp[i][1] = 0;

        if (a[i] > b[i - 1])
        {
            dp[i][0] += dp[i - 1][0] + dp[i - 1][1];
        }
        else if (a[i] > a[i - 1])
        {
            dp[i][0] += dp[i - 1][0];
            if (b[i] > b[i - 1])
                dp[i][1] += dp[i - 1][1];
        }
        else
        {
            if (b[i] > a[i - 1])
                dp[i][1] += dp[i - 1][0];
            if (b[i] > b[i - 1])
                dp[i][1] += dp[i - 1][1];
        }

        ans += dp[i][0] + dp[i][1];
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
            swap(a[i], b[i]);
    }

    cout << f(a, b) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
