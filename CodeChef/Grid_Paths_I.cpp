#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll f(vector<vector<char>> &g, ll row, ll col, vector<vector<ll>> &dp)
{

    if (g[row][col] == '*')
    {
        return 0;
    }

    if (row == g.size() - 1 && col == g[0].size() - 1)
    {
        return 1;
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col] % mod;
    }

    ll down = 0;
    ll right = 0;

    if (row < g.size() - 1)
    {
        down = f(g, row + 1, col, dp);
    }
    if (col < g[0].size() - 1)
    {
        right = f(g, row, col + 1, dp);
    }

    return dp[row][col] = (down + right) % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<vector<char>> g(n, vector<char>(n));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }

    if (g[0][0] == '*' || g[n - 1][n - 1] == '*')
    {
        cout << "0\n";
        return 0;
    }
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    ll ans = f(g, 0, 0, dp);
    cout << ans << "\n";
    return 0;
}