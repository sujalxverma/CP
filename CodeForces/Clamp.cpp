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
    long long sum;
    long long cnt;
    Node(long long sum, long long cnt) {
        this->sum = sum;
        this->cnt = cnt;
    }
};

struct SegTree {
    long long size;
    long long real_size;
    vector<Node> tree;
    Node NEUTRAL = Node(0, 0);

    Node merge(const Node &a, const Node &b) {
        return Node(a.sum + b.sum, a.cnt + b.cnt);
    }

    void init(long long n) {
        real_size = n;
        size = 1;
        while (size < n)
            size <<= 1;
        tree.assign(2 * size, NEUTRAL);
    }

    // void build(vector<long long> &arr, long long node, long long lx, long long rx) {
    //     if (rx - lx == 1) {
    //         if (lx < (long long)arr.size())
    //             tree[node] = Node(arr[lx]);
    //         return;
    //     }

    //     long long mid = (lx + rx) / 2;
    //     build(arr, 2 * node + 1, lx, mid);
    //     build(arr, 2 * node + 2, mid, rx);
    //     tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    // }

    // void build(vector<long long> &arr) {
    //     build(arr, 0, 0, size);
    // }

    void set(long long i, long long v, long long node, long long lx, long long rx) {
        if (rx - lx == 1) {
            tree[node].cnt += v;
            tree[node].sum = tree[node].cnt ? (i * tree[node].cnt) : 0;
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

    Node query(long long l, long long r, long long node, long long lx, long long rx) {
        if (rx <= l || r <= lx)
            return NEUTRAL;
        if (l <= lx && rx <= r)
            return tree[node];

        long long mid = (lx + rx) / 2;
        Node left = query(l, r, 2 * node + 1, lx, mid);
        Node right = query(l, r, 2 * node + 2, mid, rx);
        return merge(left, right);
    }

    Node query(long long l, long long r) {
        return query(l, r, 0, 0, size);
    }
};
#endif

void solve() {
    long long n, q;
    cin >> n >> q;
    vector<long long> a(n);

    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        a[i] = x;
    }
    SegTree s;
    long long MAXN = 5e5 + 2;
    s.init(MAXN);
    for (long long i = 0; i < n; i++) {
        s.set(a[i], 1);
    }
    while (q--) {
        long long x;
        cin >> x;
        if (x == 1) {
            long long l, v;
            cin >> l >> v;
            l--;
            s.set(a[l], -1);
            a[l] = v;
            s.set(a[l], 1);

        } else {
            long long l, r;
            cin >> l >> r;

            if (l <= r) {
                auto v1 = l * s.query(0, l).cnt;
                auto v2 = r * s.query(r + 1, MAXN).cnt;
                auto v3 = s.query(l, r + 1).sum;
                cout << v1 + v2 + v3 << "\n";
            } else {
                cout << l * n << "\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}