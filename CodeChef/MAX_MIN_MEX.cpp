#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll mod = 998244353;
vector<ll> a;


const int MAXN = 1e6 + 5;
const long long MOD = 1e9 + 7;

long long fact[MAXN], invfact[MAXN];

long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invfact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--)
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
}


// Calculate MEX for a range in a vector.
ll calculateMex(const std::vector<ll> &vec, ll start, ll end)
{
    std::unordered_set<ll> seen;
    // Insert elements from the subrange into the set
    for (ll i = start; i <= end && i < (ll)vec.size(); ++i)
    {
        if (vec[i] >= 0)
        {
            seen.insert(vec[i]);
        }
    }
    // Find the smallest non-negative integer not in the set
    ll mex = 0;
    while (seen.count(mex))
    {
        ++mex;
    }
    return mex;
}

void solve()
{
    ll n;
    cin >> n;
    a.resize(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    /*
    First element of R is always going to be 0.
    All elements of array a are distinct.
    Trying Brute Force.
    */

    sort(begin(a), end(a));
    map<ll, ll> mp;
    do
    {
        vector<ll> r(n, 0);
        ll maxi = a[0];
        ll mini = a[0];
        for (ll i = 1; i < n; i++)
        {
            maxi = max(maxi, a[i]);
            mini = min(mini, a[i]);
            r[i] = maxi - mini;
        }
        ll mex = calculateMex(r, 0, n - 1);
        mp[mex] = (mp[mex] % mod + 1) % mod;
    } while (next_permutation(begin(a), end(a)));
    ll ans = 0;
    ll maxi = 0;
    for (auto &[x, y] : mp)
    {
        if (x > maxi)
        {
            ans = y;
            maxi = x;
        }
    }
    cout <<maxi<<" "<< ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    precompute();
    while (t--)
    {
        solve();
    }
    return 0;
}