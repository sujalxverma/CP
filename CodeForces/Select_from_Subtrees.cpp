#include "bits/stdc++.h"
using namespace std;

using ll = long long;

const ll MOD = 998244353;
const int MAXD = 1e6;

vector<ll> s, t, c, d;
vector<vector<ll>> g;

ll mod_pow(ll a, ll b) {
    ll res = 1;

    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

vector<ll> fact(MAXD + 1), inv_fact(MAXD + 1);

void precompute() {
    fact[0] = 1;

    for (int i = 1; i <= MAXD; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    inv_fact[MAXD] = mod_pow(fact[MAXD], MOD - 2);

    for (int i = MAXD - 1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr_large(ll n, ll r) {
    if (r < 0 || r > n)
        return 0;

    ll num = 1;

    for (ll i = 0; i < r; i++) {
        num = (num * ((n - i) % MOD)) % MOD;
    }

    return (num * inv_fact[r]) % MOD;
}

void dfs(ll u) {
    for (auto &v : g[u]) {
        dfs(v);

        s[u] += s[v];
        t[u] += t[v];
    }

    s[u] += c[u];
    t[u] += d[u];
}

ll ans = 1;

void dfs2(ll u) {
    if (s[u] < t[u]) {
        ans = 0;
        return;
    }

    ans = (ans * nCr_large(s[u] + d[u] - t[u], d[u])) % MOD;

    for (auto &v : g[u]) {
        dfs2(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int n;
    cin >> n;

    g.resize(n + 1);
    c.resize(n + 1);
    d.resize(n + 1);
    s.resize(n + 1);
    t.resize(n + 1);

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;

        g[p].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    dfs(1);
    dfs2(1);

    cout << ans << '\n';
}