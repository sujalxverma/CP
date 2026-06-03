// VERMA
#include "bits/stdc++.h"
#include <numeric>
#include <random>
using namespace std;
using ll = long long;

constexpr ll MOD = 1'000'000'007;
constexpr ll INF = 1'000'000'000;
constexpr ll LINF = (ll)4e18;

#define yes cout << "YES\n";
#define no cout << "NO\n";

// Bit helpers
// #define BITHELPER
#ifdef BITHELPER
static inline ll setbits(unsigned ll x) { return __builtin_popcount(x); }
static inline ll setbitsll(unsigned long long x) { return __builtin_popcountll(x); }
static inline ll leadingzero(unsigned ll x) { return __builtin_clz(x); }
static inline ll trailingzero(unsigned ll x) { return __builtin_ctz(x); }
static inline ll parity(unsigned ll x) { return __builtin_parity(x); }
#endif

#define SEGMENTTREE
#ifdef SEGMENTTREE
struct Node {
    vector<ll> sum, v;
    Node(vector<ll> val) {
        v = val;
        sum.resize((ll)v.size());
        sum[0] = v[0];
        for (ll i = 1; i < (ll)v.size(); i++) {
            sum[i] = sum[i - 1] + v[i];
        }
    }
};

struct SegTree {
    ll size;
    ll real_size;
    vector<Node> tree;
    Node NEUTRAL = Node({0});

    Node merge(const Node &a, const Node &b) {
        ll i = 0;
        ll j = 0;
        vector<ll> c;
        while (i < (ll)a.v.size() && j < (ll)b.v.size()) {
            if (a.v[i] <= b.v[j]) {
                c.push_back(a.v[i]);
                i++;
            } else {
                c.push_back(b.v[j]);
                j++;
            }
        }
        while (i < (ll)a.v.size()) {
            c.push_back(a.v[i]);
            i++;
        }
        while (j < (ll)b.v.size()) {
            c.push_back(b.v[j]);
            j++;
        }
        return Node(c);
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
                tree[node] = Node({arr[lx]});
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

    ll query(ll l, ll r, ll x, ll node, ll lx, ll rx) {
        if (rx <= l || r <= lx) {
            return 0;
        }
        if (l <= lx && rx <= r) {
            ll idx = (upper_bound(begin(tree[node].v), end(tree[node].v), x) - begin(tree[node].v));
            if (idx - 1 >= 0) {
                return tree[node].sum[idx - 1];
            }
            return 0;
        }
        ll m = (lx + rx) / 2;
        return query(l, r, x, 2 * node + 1, lx, m) + query(l, r, x, 2 * node + 2, m, rx);
    }

    ll query(ll l, ll r, ll x) {
        return query(l, r, x, 0, 0, size);
    }
};
#endif

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegTree s;
    s.init(n);
    s.build(a);

    ll q;
    cin >> q;
    while (q--) {
        ll l, r, x;
        cin >> l >> r >> x;
        l--;
        cout << s.query(l, r, x) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}