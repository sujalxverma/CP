#include "bits/stdc++.h"
using namespace std;
#define int long long
int n, q;
vector<int> a;
vector<vector<int>> g;
vector<int> dp, dp2;
vector<int> subtree;
vector<int> idx;
int dfs(int u, int p) {
    dp.push_back(a[u]);
    dp2.push_back(u);
    int ans = 1;
    for (int &v : g[u]) {
        if (p == v)
            continue;
        ans += dfs(v, u);
    }
    subtree[u] = ans;
    return ans;
}

struct Node {
    long long val; // change type as needed

    Node(long long v = 0) {
        val = v;
    }
};

struct SegTree {
    int size;
    int real_size;
    vector<Node> tree;
    Node NEUTRAL = Node(0); // neutral element for merge

    // merge two nodes
    // can be modified.
    Node merge(const Node &a, const Node &b) {
        return Node(a.val + b.val); // example: sum segment tree
    }

    // initialize tree
    void init(int n) {
        real_size = n;
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(2 * size, NEUTRAL);
    }

    // build from array
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

    // point update: set position i to value v
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

    // range query [l, r), to include r => [l,r+1)
    // int x -> current node of the tree.
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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    g.resize(n + 1);
    a.resize(n + 1);
    idx.resize(n + 1);
    subtree.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int _ = dfs(1, -1);
    for (int i = 0; i < n; i++) {
        idx[dp2[i]] = i;
    }

    SegTree st;
    st.init(n);
    st.build(dp);

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            int u, v;
            cin >> u >> v; // change node u value to v.
            a[u] = v;
            st.set(idx[u], v);
        } else {
            int v;
            cin >> v;
            int size = subtree[v];
            cout << st.query(idx[v], idx[v] + size).val << "\n";
        }
    }

    return 0;
}