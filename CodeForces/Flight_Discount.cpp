#include "bits/stdc++.h"
using namespace std;

using ll = long long;
const ll inf = 1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(2, inf));
    priority_queue<
        tuple<ll, ll, ll>,
        vector<tuple<ll, ll, ll>>,
        greater<tuple<ll, ll, ll>>
    > pq;

    dp[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty())
    {
        auto [d, u, used] = pq.top();
        pq.pop();

        if (d != dp[u][used]) continue;

        for (auto &[v, w] : g[u])
        {
            // normal edge
            if (dp[u][used] + w < dp[v][used])
            {
                dp[v][used] = dp[u][used] + w;
                pq.push({dp[v][used], v, used});
            }

            // use discount
            if (used == 0)
            {
                if (dp[u][0] + w / 2 < dp[v][1])
                {
                    dp[v][1] = dp[u][0] + w / 2;
                    pq.push({dp[v][1], v, 1});
                }
            }
        }
    }

    cout << dp[n][1] << "\n";
    return 0;
}
