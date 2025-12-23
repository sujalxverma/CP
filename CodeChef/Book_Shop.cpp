#include "bits/stdc++.h"
using namespace std;

int f(vector<pair<int, int>> &p, int t)
{

    int n = p.size();
    vector<int> dp(t + 1, 0);
    for (int price = 0; price <= t; price++)
    {
        if (p[0].first <= price)
        {
            dp[price] = p[0].second;
        }
    }

    vector<int> prev = dp;

    for (int i = 1; i < n; i++)
    {
        for (int pr = 1; pr <= t; pr++)
        {
            int nottake = prev[pr];
            int take = 0;
            if (p[i].first <= pr)
            {
                take = p[i].second + prev[pr - p[i].first];
            }

            dp[pr] = max(take, nottake);
        }
        prev = dp;
    }

    return dp[t];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> p(n); // price ,pages
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].second;
    }

    int ans = f(p, t);
    cout << ans << "\n";
    return 0;
}