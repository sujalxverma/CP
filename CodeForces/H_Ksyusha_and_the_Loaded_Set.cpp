// VERMA
#include "bits/stdc++.h"
#include <numeric>
#include <random>
using namespace std;
using ll = long long;

constexpr long long MOD = 1'000'000'007;
constexpr long long INF = 1'000'000'000;
constexpr ll LINF = (ll)4e18;

#define yes cout << "YES\n";
#define no cout << "NO\n";

// Bit helpers
// #define BITHELPER
#ifdef BITHELPER
static inline long long setbits(unsigned long long x) { return __builtin_popcount(x); }
static inline long long setbitsll(unsigned long long x) { return __builtin_popcountll(x); }
static inline long long leadingzero(unsigned long long x) { return __builtin_clz(x); }
static inline long long trailingzero(unsigned long long x) { return __builtin_ctz(x); }
static inline long long parity(unsigned long long x) { return __builtin_parity(x); }
#endif

#define SEGMENTTREE
#ifdef SEGMENTTREE
struct Node {
    long long p, s, sum, len;
    Node(long long p, long long s, long long sum, long long len) {
        this->p = p;
        this->s = s;
        this->sum = sum;
        this->len = len;
    }
};

struct SegTree {
    long long size;
    long long real_size;
    vector<Node> tree;
    Node NEUTRAL = Node(1, 1, 1, 1);

    Node merge(const Node &a, const Node &b) {
        long long maxp = (a.p == a.len ? a.p + b.p : a.p);
        long long maxs = (b.s == b.len ? b.s + a.s : b.s);
        // 'sum' represents the max contiguous zeroes anywhere in this range
        long long mx = max({a.sum, b.sum, a.s + b.p});
        return Node(maxp, maxs, mx, a.len + b.len);
    }

    void build(long long node, long long lx, long long rx) {
        if (rx - lx == 1) {
            tree[node] = Node(1, 1, 1, 1); // Initially, every number is absent (a zero)
            return;
        }
        long long mid = (lx + rx) / 2;
        build(2 * node + 1, lx, mid);
        build(2 * node + 2, mid, rx);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void init(long long n) {
        real_size = n;
        size = 1;
        while (size < n)
            size <<= 1;
        // Just allocate space, don't use NEUTRAL here
        tree.assign(2 * size, Node(0, 0, 0, 0));
        build(0, 0, size); // Build the actual lengths and zeroes
    }

    void set(long long i, long long v, long long node, long long lx, long long rx) {
        if (rx - lx == 1) {
            if (v == 1) {
                tree[node] = Node(0, 0, 0, 1); // element is added.
            } else {
                tree[node] = Node(1, 1, 1, 1); // element is removed.
            }
            return;
        }

        long long mid = (lx + rx) / 2;
        if (i < mid)
            set(i, v, 2 * node + 1, lx, mid);
        else
            set(i, v, 2 * node + 2, mid, rx);

        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void set(long long i, long long v) {
        set(i, v, 0, 0, size);
    }

    long long query(long long node, long long lx, long long rx, long long k) {
        if (rx - lx == 1) {
            return lx;
        }
        long long m = (lx + rx) / 2;
        // present entirely in left child;
        if (tree[2 * node + 1].sum >= k) {
            return query(2 * node + 1, lx, m, k);
        }
        // present b/w left and right child, combined.
        if (tree[2 * node + 1].s + tree[2 * node + 2].p >= k) {
            return m - tree[2 * node + 1].s;
        }

        // on right side.
        return query(2 * node + 2, m, rx, k);
    }

    long long query(long long k) {
        if (tree[0].sum < k)
            return -1; // Failsafe
        return query(0, 0, size, k);
    }
};
#endif

void solve() {
    long long n;
    cin >> n;
    long long MAXN = 2e6 + 10;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegTree s;
    s.init(MAXN);
    s.set(0, 1);
    for (long long i = 0; i < n; i++) {
        s.set(a[i], 1);
    }
    long long q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        if (c == '+') {
            long long v;
            cin >> v;
            s.set(v, 1);
        }
        if (c == '-') {
            long long v;
            cin >> v;
            s.set(v, -1);
        }
        if (c == '?') {
            // finding atleast k leftmost zeroes.
            long long k;
            cin >> k;
            cout << s.query(k) << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}