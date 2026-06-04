// VERMA
#include "bits/stdc++.h"
#include <numeric>
#include <random>
using namespace std;
using ll = long long;

constexpr ll MOD = 1'000'000'007;
constexpr ll INF = 1'000'000'000;
constexpr ll LINF = (ll)4e18; // wider than 1e18 for safety

#define yes cout << "YES\n";
#define no cout << "NO\n";

// Bit helpers (careful with types)
// #define BITHELPER
#ifdef BITHELPER
static inline ll setbits(unsigned ll x) { return __builtin_popcount(x); }
static inline ll setbitsll(unsigned long long x) { return __builtin_popcountll(x); }
static inline ll leadingzero(unsigned ll x) { return __builtin_clz(x); }
static inline ll trailingzero(unsigned ll x) { return __builtin_ctz(x); }
static inline ll parity(unsigned ll x) { return __builtin_parity(x); }
#endif

#define COMBINATORICS
#ifdef COMBINATORICS
struct Combinatorics {
    static constexpr long long MOD = 1'000'000'007;
    vector<long long> fact, invFact;

    long long modpow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    Combinatorics(ll n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);

        fact[0] = 1;
        for (ll i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n] = modpow(fact[n], MOD - 2);

        for (ll i = n; i > 0; i--)
            invFact[i - 1] = invFact[i] * i % MOD;
    }

    long long factorial(ll n) {
        return fact[n];
    }

    long long nCr(ll n, ll r) {
        if (r < 0 || r > n)
            return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    long long nPr(ll n, ll r) {
        if (r < 0 || r > n)
            return 0;
        return fact[n] * invFact[n - r] % MOD;
    }

    long long catalan(ll n) {
        return nCr(2 * n, n) * modpow(n + 1, MOD - 2) % MOD;
    }

    long long starsBars(ll k, ll n) {
        return nCr(k + n - 1, n - 1);
    }
};
#endif

// #define SEGMENTTREE
#ifdef SEGMENTTREE
struct Node {
    long long val;

    Node(long long v = 0) {
        val = v;
    }
};

struct SegTree {
    ll size;
    ll real_size;
    vector<Node> tree;
    Node NEUTRAL = Node(0);

    Node merge(const Node &a, const Node &b) {
        return Node(a.val + b.val);
    }

    void init(ll n) {
        real_size = n;
        size = 1;
        while (size < n)
            size <<= 1;
        tree.assign(2 * size, NEUTRAL);
    }

    void build(vector<ll> &arr, ll node, ll lx, ll rx) {
        if (rx - lx == 1) {
            if (lx < (ll)arr.size())
                tree[node] = Node(arr[lx]);
            return;
        }

        ll mid = (lx + rx) / 2;
        build(arr, 2 * node + 1, lx, mid);
        build(arr, 2 * node + 2, mid, rx);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void build(vector<ll> &arr) {
        build(arr, 0, 0, size);
    }

    void set(ll i, ll v, ll node, ll lx, ll rx) {
        if (rx - lx == 1) {
            tree[node] = Node(v);
            return;
        }

        ll mid = (lx + rx) / 2;
        if (i < mid)
            set(i, v, 2 * node + 1, lx, mid);
        else
            set(i, v, 2 * node + 2, mid, rx);

        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
    }

    Node query(ll l, ll r, ll node, ll lx, ll rx) {
        if (rx <= l || r <= lx)
            return NEUTRAL;
        if (l <= lx && rx <= r)
            return tree[node];

        ll mid = (lx + rx) / 2;
        Node left = query(l, r, 2 * node + 1, lx, mid);
        Node right = query(l, r, 2 * node + 2, mid, rx);
        return merge(left, right);
    }

    Node query(ll l, ll r) {
        return query(l, r, 0, 0, size);
    }
};
#endif
Combinatorics ck(2e5 + 20);
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(begin(a), end(a));
    // if (a[n / 2] == 0) {
    //     cout << "0\n";
    //     return;
    // }
    if (k == 1) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                cnt++;
            }
        }
        cout << cnt << "\n";
        return;
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] != 0) {
            ll l = i;
            ll r = n - 1 - i;
            if (l >= k / 2 && r >= k / 2) {
                ans += (ck.nCr(l, k / 2) % MOD * ck.nCr(r, k / 2) % MOD) % MOD;
            }
        }
    }
    cout << ans % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}