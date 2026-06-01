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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // FIX 1: Use an array of vectors for queries since `l` is strictly < n.
    // This is O(1) lookup and extremely fast.
    vector<vector<pair<int, int>>> p(n);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        p[l].push_back({r, i});
    }

    // FIX 2: Precompute the next occurrences to completely avoid stacks.
    vector<int> nxt(n, -1);
    map<int, int> last_pos; // map is safer than unordered_map here to avoid hash collisions

    for (int i = n - 1; i >= 0; i--) {
        if (last_pos.count(a[i])) {
            nxt[i] = last_pos[a[i]];
        }
        last_pos[a[i]] = i;
    }

    SegTree s;
    s.init(n);

    // Initialize segment tree with only the first occurrence of each distinct number
    for (auto const &[val, pos] : last_pos) {
        s.set(pos, 1);
    }

    vector<int> ans(q, 0);

    for (int L = 0; L < n; L++) {
        // Answer all queries starting at index L
        for (auto &y : p[L]) {
            ans[y.second] = s.query(L, y.first + 1).val;
        }

        // Remove the current element from the active set
        s.set(L, 0);

        // If this element appears again later in the array, mark its next occurrence
        if (nxt[L] != -1) {
            s.set(nxt[L], 1);
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
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