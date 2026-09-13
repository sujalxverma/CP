// VERMA
#include "bits/stdc++.h"
#include <numeric>
#include <random>
using namespace std;
using ll = long long;

constexpr int MOD = 1'000'000'007;
constexpr int INF = 1'000'000'000;
constexpr ll LINF = (ll)4e18;

#define yes cout << "YES\n";
#define no cout << "NO\n";

// Bit helpers
// #define BITHELPER
#ifdef BITHELPER
static inline int setbits(unsigned int x) { return __builtin_popcount(x); }
static inline int setbitsll(unsigned long long x) { return __builtin_popcountll(x); }
static inline int leadingzero(unsigned int x) { return __builtin_clz(x); }
static inline int trailingzero(unsigned int x) { return __builtin_ctz(x); }
static inline int parity(unsigned int x) { return __builtin_parity(x); }
#endif

#define SEGMENTTREE
#ifdef SEGMENTTREE
struct Node {
    vector<int> v;
    Node(vector<int> v) {
        this->v = v;
    }
};

struct SegTree {
    int size;
    int real_size;
    vector<Node> tree;
    Node NEUTRAL = Node({});

    Node merge(const Node &a, const Node &b) {
        int i = 0;
        int j = 0;
        vector<int> c;
        while (i < (int)a.v.size() && j < (int)b.v.size()) {
            if (a.v[i] <= b.v[j]) {
                c.push_back(a.v[i]);
                i++;
            } else {
                c.push_back(b.v[j]);
                j++;
            }
        }
        while (i < (int)a.v.size()) {
            c.push_back(a.v[i]);
            i++;
        }
        while (j < (int)b.v.size()) {
            c.push_back(b.v[j]);
            j++;
        }
        return Node(c);
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
                tree[node] = Node({arr[lx]});
            return;
        }

        int mid = (lx + rx) / 2;
        build(arr, 2 * node + 1, lx, mid);
        build(arr, 2 * node + 2, mid, rx);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void build(vector<int> &arr) {
        build(arr, 0, 0, size);
    }

    void set(int i, int v, int node, int lx, int rx) {
        if (rx - lx == 1) {
            tree[node] = Node({v});
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid)
            set(i, v, 2 * node + 1, lx, mid);
        else
            set(i, v, 2 * node + 2, mid, rx);

        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int query(int l, int r, int x, int node, int lx, int rx) {
        if (rx <= l || r <= lx) {
            return 0;
        }
        if (l <= lx && rx <= r) {
            return (int)tree[node].v.size() - (upper_bound(begin(tree[node].v), end(tree[node].v), x) - begin(tree[node].v));
        }
        int m = (lx + rx) / 2;
        return +query(l, r, x, 2 * node + 2, m, rx);
    }

    int query(int l, int r, int x) {
        return query(l, r, x, 0, 0, size);
    }
};
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegTree s;
    s.init(n);
    query(l, r, x, 2 * node + 1, lx, m)
        s.build(a);
    int q;
    cin >> q;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;
        cout << s.query(l, r + 1, x) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}