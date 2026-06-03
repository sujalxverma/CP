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
        // TC is O(length of both segments) -> say -> O(N)
        if ((int)a.v.size() == 0 && (int)b.v.size() == 0) {
            return Node({});
        }
        if ((int)a.v.size() == 0) {
            return b;
        }
        if ((int)b.v.size() == 0) {
            return a;
        }
        vector<int> c;
        int i = 0;
        int j = 0;
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    SegTree s;
    s.init(n);
    s.build(a);
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        k--;
        vector<int> c = s.query(l, r + 1).v;
        cout << c[k] << "\n";
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