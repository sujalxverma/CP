

#include "bits/stdc++.h"
using namespace std;
#define long long
int n, q;
vector<vector<int>> g;
int timer = 0;
vector<int> tin;
vector<int> order;
vector<int> depth;
vector<int> dis;
const int inf = 1e18;
void dfs(int u, int p, int d, int distance) {
    dis[u] = distance;
    tin[u] = order.size(); // first occurrence in Euler tour
    order.push_back(u);
    depth.push_back(d);

    for (int v : g[u]) {
        if (v == p)
            continue;
        dfs(v, u, d + 1, distance + 1);
        order.push_back(u);
        depth.push_back(d);
    }
}

struct Node {
    long long val; // change type as needed
    int idx;
    Node(long long v = 0, int idx = 0) {
        val = v;
        this->idx = idx;
    }
};

struct SegTree {
    int size;
    int real_size;
    vector<Node> tree;
    Node NEUTRAL = Node(inf, 0); // neutral element for merge

    // merge two nodes
    // can be modified.
    Node merge(const Node &a, const Node &b) {
        if (a.val <= b.val) {
            return a;
        }
        return b;
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
                tree[node] = Node(arr[lx], lx);
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
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dis.resize(n + 1);
    tin.resize(n + 1, 0);
    dfs(1, 1, 0, 0);
    SegTree st;
    st.init((int)depth.size());
    st.build(depth);
    for (int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        if (tin[u] > tin[v]) {
            swap(u, v);
        }
        int idx = st.query(tin[u], tin[v] + 1).idx;
        cout << dis[u] + dis[v] - 2 * dis[order[idx]] << "\n";
    }
    return 0;
}
