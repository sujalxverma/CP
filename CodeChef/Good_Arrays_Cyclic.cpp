#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rep2(i, a, b) for (long long i = a; i < b; i++)
typedef unordered_map<int, int> umap;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define even(a) (((a) % 2) == 0 ? 1 : 0)
#define rev(v) reverse(v.begin(), v.end())
#define sorting(v) sort(v.begin(), v.end())
#define line cout << "\n"
#define contains(vec, x) (std::find((vec).begin(), (vec).end(), (x)) != (vec).end())
#define containsBS(vec, x) (std::binary_search((vec).begin(), (vec).end(), (x)))
#define zerobits(x) __builtin_ctzll(x)
#define setbits(x) __builtin_popcount(x)     // Count of set bits in int
#define setbitsll(x) __builtin_popcountll(x) // Count of set bits in long long
#define leadingzero(x) __builtin_clz(x)      // Leading zeros (int)
#define trailingzero(x) __builtin_ctz(x)     // Trailing zeros (int)
#define parity(x) __builtin_parity(x)        // 1 if odd number of set bits, else 0

const ll MOD = 1e9+7;
//------------------------------------------------------------------------------------------------------------//
//                                          Here you go
ll n;
ll arr[101][101];
ll DP[101][101];

ll dp(ll i, ll elements)
{
    if (elements == 0)
        return 1;
    if (DP[i][elements] != -1)
        return DP[i][elements];
    ll ans = 0;
    for (ll j = 0; j < n; j++)
    {
        if (arr[i][j] && arr[i + n / 2][j])
        {
            ans += dp(i + 1, elements - 1);
            ans %= MOD;
        }
    }
    DP[i][elements] = ans;
    return ans;
}
void solve()
{

    cin >> n;
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            DP[i][j] = -1;
        }
    }
    ll tot = 1;
    for (ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ll ct = 0;
        for (ll j = 0; j < n; j++)
        {
            if (s[j] == '1')
                arr[i][j] = 1;
            else
                arr[i][j] = 0;

            ct += arr[i][j];
        }

        tot *= ct;
        tot %= MOD;
    }
    cout << (MOD + tot - dp(0, n / 2)) % MOD << endl;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}