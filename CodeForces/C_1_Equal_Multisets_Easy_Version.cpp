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

// #define SEGMENTTREE
#ifdef SEGMENTTREE
struct Node {
    long long val;
    Node(long long v = 0) {
        val = v;
    }
};

struct SegTree {
    int size;
    int real_size;
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

    void build(vector<int> &arr) {
        build(arr, 0, 0, size);
    }

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

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    Node query(int l, int r, int node, int lx, int rx) {
        if (rx <= l || r <= lx)
            return NEUTRAL;
        if (l <= lx && rx <= r)
            return tree[node];

        int mid = (lx + rx) / 2;
        Node left = query(l, r, 2 * node + 1, lx, mid);
        Node right = query(l, r, 2 * node + 2, mid, rx);
        return merge(left, right);
    }

    Node query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    vector<int> f(n + 2, -1);
    vector<vector<int>> idx(n + 2);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] > -1) {
            f[b[i]] = 1;
            idx[b[i]].push_back(i);
        }
    }
    int i = 0;
    int j = 0;
    while (i < n && j < n) {
        if (f[a[i]] == 1) {
            i++;
        } else if (f[a[i]] == -1) {
            if (b[j] == -1) {
                b[j] = a[i];
                idx[b[j]].push_back(j);
                i++;
                j++;
            } else {
                j++;
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << " " << b[i] << "\n";
    // }
    for (int i = 1; i <= n; i++) {
        if (idx[i].size() > 1) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i <= k - 1; i++) {
        int id = idx[a[i]][0];
        if (id >= 0 && id <= k - 1) {

        } else {
            cout << "NO\n";
            return;
        }
    }
    for (int i = n - 1; i >= n - k; i--) {
        int id = idx[a[i]][0];
        if (id <= n - 1 && id >= n - k) {

        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}