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
    long long max_val;
    Node(long long s = 0, long long m = 0) {
        sum = s;
        max_val = m;
    }
};

struct SegTree {
    long long size;
    long long real_size;
    vector<Node> tree;
    Node NEUTRAL = Node(0);

    Node merge(const Node &a, const Node &b) {
        return Node(a.sum + b.sum, max(a.max_val, b.max_val));
    }
    void init(long long n) {
        real_size = n;
        size = 1;
        while (size < n)
            size <<= 1;
        tree.assign(2 * size, NEUTRAL);
    }

    void build(vector<long long> &arr, long long node, long long lx, long long rx) {
        if (rx - lx == 1) {
            if (lx < (long long)arr.size())
                tree[node] = Node(arr[lx], arr[lx]);
            return;
        }

        long long mid = (lx + rx) / 2;
        build(arr, 2 * node + 1, lx, mid);
        build(arr, 2 * node + 2, mid, rx);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void build(vector<long long> &arr) {
        build(arr, 0, 0, size);
    }

    void update_range(long long l, long long r, long long node, long long lx, long long rx, const vector<long long> &factors) {

        if (rx <= l || r <= lx) {
            return;
        }

        if (tree[node].max_val <= 2) {
            return;
        }

        if (rx - lx == 1) {
            long long new_val = factors[tree[node].sum];
            tree[node] = Node(new_val, new_val);
            return;
        }

        long long mid = (lx + rx) / 2;
        update_range(l, r, 2 * node + 1, lx, mid, factors);
        update_range(l, r, 2 * node + 2, mid, rx, factors);

        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update_range(long long l, long long r, const vector<long long> &factors) {
        update_range(l, r, 0, 0, size, factors);
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
vector<long long> countFactors(long long N = 1000000) {
    vector<long long> factors(N + 1, 0);

    for (long long i = 1; i <= N; ++i) {
        for (long long j = i; j <= N; j += i) {
            factors[j]++;
        }
    }

    return factors;
}
void solve() {
    long long n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];

    vector<long long> factors = countFactors();

    SegTree st;
    st.init(n);
    st.build(a);

    while (q--) {
        long long type, l, r;
        cin >> type >> l >> r;
        l--;

        if (type == 1) {

            st.update_range(l, r, factors);
        } else {

            cout << st.query(l, r).sum << "\n";
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