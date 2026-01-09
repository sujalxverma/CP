#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll inf = 1e9;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    // 65

    vector<string> s(n);
    vector<vector<ll>> dp(n, vector<ll>(26, 0)); // creates 2D matrix.
    vector<ll> sum(26);                          // total occurence of each alphabet.
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (ll i = 0; i < n; i++)
    {

        for (ll j = 0; j < (ll)s[i].length(); j++)
        {

            dp[i][s[i][j] - 'A']++;
        }
    }
    for (int j = 0; j < 26; j++)
    {
        for (int i = 0; i < n; i++)
        {
            sum[j] += dp[i][j];
        }
    }

    for (ll i = 0; i < n; i++)
    {

        ll r = -1e9;
        bool f = false;
        for (ll j = 0; j < 26; j++)
        {
            if (dp[i][j] == sum[j] && sum[j] == 0)
                continue;
            if (dp[i][j] == sum[j] && dp[i][j] > 0)
            {
                cout << "-1 ";
                f = true;
                break;
            }

            ll value_ceil = (dp[i][j] + (sum[j] - dp[i][j]) - 1)/(sum[j] - dp[i][j]);
            // r = max(r, ((sum[j] - 1) / (sum[j] - dp[i][j])));
            r = max(r,value_ceil);
        }
        if (f)
            continue;
        cout << max(m - r, -1LL) << " ";
    }
    cout << "\n";

    return 0;
}