// VERMA
#include "bits/stdc++.h"
#include <chrono>
#include <numeric>
#include <random>
using namespace std;

using ll = long long;
using ld = long double;

std::mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int MOD = 1'000'000'007;
constexpr int INF = 1'000'000'000;
constexpr ll LINF = (ll)4e18;

#define yes cout << "YES\n"
#define no cout << "NO\n"
static inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// #define BITHELPER
#ifdef BITHELPER
static inline int setbits(unsigned int x) { return __builtin_popcount(x); }
static inline int setbitsll(unsigned long long x) { return __builtin_popcountll(x); }
static inline int leadingzero(unsigned int x) { return __builtin_clz(x); }
static inline int trailingzero(unsigned int x) { return __builtin_ctz(x); }
static inline int parity(unsigned int x) { return __builtin_parity(x); }
#endif

// #define MATHS
#ifdef MATHS
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

static inline ll mod_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
#endif

// #define SEGMENTTREE
#ifdef SEGMENTTREE
struct Node {
    ll val;
    Node(ll v = 0) : val(v) {}
};

struct SegTree {
    int size, real_size;
    vector<Node> tree;
    Node NEUTRAL = Node(0);

    Node merge(const Node &a, const Node &b) {
        return Node(a.val + b.val);
    }

    void init(int n) {
        real_size = n;
        size = 1;
        while (size < n)
            size <<= 1;
        tree.assign(2 * size, NEUTRAL);
    }

    void build(vector<int> &arr, int node, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)arr.size())
                tree[node] = Node(arr[lx]);
            return;
        }
        int mid = (lx + rx) / 2;
        build(arr, 2 * node + 1, lx, mid);
        build(arr, 2 * node + 2, mid, rx);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void build(vector<int> &arr) { build(arr, 0, 0, size); }

    void set(int i, int v, int node, int lx, int rx) {
        if (rx - lx == 1) {
            tree[node] = Node(v);
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)
            set(i, v, 2 * node + 1, lx, mid);
        else
            set(i, v, 2 * node + 2, mid, rx);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void set(int i, int v) { set(i, v, 0, 0, size); }

    Node query(int l, int r, int node, int lx, int rx) {
        if (rx <= l || r <= lx)
            return NEUTRAL;
        if (l <= lx && rx <= r)
            return tree[node];
        int mid = (lx + rx) / 2;
        return merge(query(l, r, 2 * node + 1, lx, mid),
                     query(l, r, 2 * node + 2, mid, rx));
    }

    Node query(int l, int r) { return query(l, r, 0, 0, size); }
};
#endif

void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
}

int main() {
    fastio();
    auto begin = chrono::steady_clock::now();

    int T = 1;
    if (!(cin >> T))
        return 0;
    while (T--)
        solve();

    auto end = chrono::steady_clock::now();
    auto ns = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
    // cerr << "Time measured: " << (ns * 1e-9) << " seconds.\n";
    return 0;
}