#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        p[i].first = i;
        p[i].second = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a > b){
            swap(a,b);
        }
        p[b].second = max(a, p[b].second);
    }

    // how much left we can go from r.
    vector<int> dp(n + 1, 0);
    long long ans = 1;   // FIXED
    dp[1] = 1;
    for (int r = 2; r <= n; r++)
    {
        dp[r] = max(p[r].second + 1, dp[r - 1]);
        ans += (r - dp[r] + 1);
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
