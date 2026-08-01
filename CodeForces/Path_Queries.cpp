#include "bits/stdc++.h"
using namespace std;
#define int long long
// make everything 0-based indexing.
int n, q;
vector<vector<int>> g;
vector<int> a;
vector<int> tin;
vector<int> tout;
int timer = 0;
vector<int> v;
void dfs(int u, int p) {
    tin[u] = timer;
    v.push_back(a[u]);
    timer++;
    for (int &k : g[u]) {
        if (k == p)
            continue;
        dfs(k, u);
    }
    v.push_back(-a[u]);
    tout[u] = timer;
    timer++;
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
    Node merge(const Node &a, const Node &b) {
        return Node(a.val + b.val); // example: sum segment tree
    }
    void init(int n) {
        real_size = n;
        size = 1;
        while (size < n)
            size *= 2;
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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    tin.resize(n);
    tout.resize(n);
    g.resize(n);
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);

    int m = (int)v.size();
    SegTree st;
    st.init(m);
    st.build(v);

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            int u, val;
            cin >> u >> val;
            u--;
            st.set(tin[u], val);
            st.set(tout[u], -val);
        } else {
            int f;
            cin >> f;
            f--;
            cout << st.query(0, tin[f] + 1).val << "\n";
        }
    }

    return 0;
}