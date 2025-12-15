#include "bits/stdc++.h"
using namespace std;
using ll = long long;

static const long long MOD = 1000000007;
static const int MAXN = 10000;

vector<long long> fact(MAXN + 1), invfact(MAXN + 1);

long long modexp(long long base, long long exp)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

void precompute_factorials()
{
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    // Fermat inverse of factorial[MAXN]
    invfact[MAXN] = modexp(fact[MAXN], MOD - 2);

    // Compute inverse factorials downward
    for (int i = MAXN - 1; i >= 0; i--)
    {
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCk(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}
// C(i+1,k)−C(i,k)=C(i,k−1)
ll solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    ll ans = 0;
    ll count = 0;

    // for (ll i = k - 1; i < n; i++)
    // {
    //     ll range = nCk(i + 1, k);
    //     ll ways = (range - count + MOD) % MOD;
    //     ans = (ans + (a[i] % MOD) * ways) % MOD;
    //     count = range;

    // }
    for (ll i = k - 1; i < n; i++)
    {
        ans = (ans + (a[i] % MOD) * nCk(i, k - 1)) % MOD;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int m = 1;
    precompute_factorials();
    while (t--)
    {
        ll ans = solve();
        cout << "Case #" << m << ": " << ans << "\n";
        m++;
    }
    return 0;
}