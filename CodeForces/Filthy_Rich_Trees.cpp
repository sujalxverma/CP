#include "bits/stdc++.h"
using namespace std;

// Fixed Fast I/O for __int128
inline __int128 read128() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != EOF) {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

__int128 n, q;
vector<vector<__int128>> g;
vector<__int128> v;
vector<__int128> dp;
vector<__int128> subtree;
vector<__int128> idx;

__int128 dfs(__int128 u, __int128 p) {
    dp.push_back(u);
    __int128 ans = 1;
    for (__int128 &v_node : g[u]) {
        if (v_node == p)
            continue;
        ans += dfs(v_node, u);
    }
    subtree[u] = ans;
    return ans;
}

struct Node {
    __int128 val;
    Node(__int128 v_val = 1) {
        val = v_val;
    }
};

struct SegTree {
    __int128 size;
    __int128 real_size;
    vector<Node> tree;
    Node NEUTRAL = Node(1);

    Node merge(const Node &a, const Node &b) {
        return Node(a.val * b.val);
    }

    void init(__int128 n_size) {
        real_size = n_size;
        size = 1;
        while (size < n_size)
            size *= 2;
        tree.assign(2 * size, NEUTRAL);
    }

    void build(vector<__int128> &arr, __int128 node, __int128 lx, __int128 rx) {
        if (rx - lx == 1) {
            if (lx < (__int128)arr.size())
                tree[node] = Node(arr[lx]);
            return;
        }
        __int128 mid = (lx + rx) / 2;
        build(arr, 2 * node + 1, lx, mid);
        build(arr, 2 * node + 2, mid, rx);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void build(vector<__int128> &arr) {
        build(arr, 0, 0, size);
    }

    void set(__int128 i, __int128 val_to_set, __int128 node, __int128 lx, __int128 rx) {
        if (rx - lx == 1) {
            tree[node] = Node(val_to_set);
            return;
        }

        __int128 mid = (lx + rx) / 2;
        if (i < mid)
            set(i, val_to_set, 2 * node + 1, lx, mid);
        else
            set(i, val_to_set, 2 * node + 2, mid, rx);

        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void set(__int128 i, __int128 val_to_set) {
        set(i, val_to_set, 0, 0, size);
    }

    Node query(__int128 l, __int128 r, __int128 node, __int128 lx, __int128 rx) {
        if (rx <= l || r <= lx)
            return NEUTRAL;
        if (l <= lx && rx <= r)
            return tree[node];

        __int128 mid = (lx + rx) / 2;
        Node left = query(l, r, 2 * node + 1, lx, mid);
        Node right = query(l, r, 2 * node + 2, mid, rx);
        return merge(left, right);
    }

    Node query(__int128 l, __int128 r) {
        return query(l, r, 0, 0, size);
    }
};

int main() {
    // Fast I/O configuration
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    n = read128();
    if (n <= 0)
        return 0;

    g.resize(n + 1);
    v.resize(n, 1);
    idx.resize(n + 1);
    subtree.resize(n + 1, 0);

    for (__int128 i = 1; i <= n - 1; i++) {
        __int128 u = read128();
        __int128 v_node = read128();
        g[u].push_back(v_node);
        g[v_node].push_back(u);
    }

    dfs(1, -1);
    for (__int128 i = 0; i < n; i++) {
        idx[dp[i]] = i;
    }

    SegTree st;
    st.init(n);
    st.build(v);

    q = read128();

    // Setup output precision for floating-point answers
    cout << fixed << setprecision(9);

    while (q--) {
        __int128 x = read128();
        __int128 u = read128();
        __int128 k = read128();

        if (x == 1) {
            v[idx[u]] = k;
            st.set(idx[u], k);
        } else {
            __int128 ans1 = st.query(idx[u], idx[u] + subtree[u]).val;
            __int128 ans2 = st.query(idx[k], idx[k] + subtree[k]).val;

            // Cast __int128 to double to perform floating-point division
            double d1 = (double)ans1;
            double d2 = (double)ans2;

            if (d2 == 0.0) {
                cout << 1e9 << "\n";
            } else {
                double result = d1 / d2;
                if (result > 1e9) {
                    cout << 1e9 << "\n";
                } else {
                    cout << result << "\n";
                }
            }
        }
    }
    return 0;
}