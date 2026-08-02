#include "bits/stdc++.h"
using namespace std;
int n, q;
vector<vector<int>> g;
vector<vector<int>> up; // sparse table
vector<int> depth;
// dfs call to fill up[node][0] = parent(node);
void dfs(int u, int p, int d) {
    up[u][0] = p;
    depth[u] = d;
    for (int &v : g[u]) {
        if (v == p)
            continue;
        dfs(v, u, d + 1);
    }
}
int LCA(int u, int v) {
    if (u == v)
        return u;
    for (int i = floor(log2(n)); i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return (up[u][0] == -1 ? 1 : up[u][0]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    g.resize(n + 1);
    depth.resize(n + 1);
    vector<int> d(n + 1);
    d[1] = 1;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        d[i] = x;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    up.assign(n + 1, vector<int>(floor(log2(n)) + 2, -1));
    dfs(1, -1, 0);
    for (int col = 1; col < floor(log2(n)) + 1; col++) {
        for (int row = 1; row <= n; row++) {
            if (up[row][col - 1] == -1) {
                up[row][col] = -1;
            } else {
                up[row][col] = up[up[row][col - 1]][col - 1];
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        int d1 = depth[u];
        int d2 = depth[v];
        if (d1 < d2) {
            int cnt = d2 - d1;
            for (int i = floor(log2(n)); i >= 0; i--) {
                if (cnt & (1 << i))
                    v = up[v][i]; // lift v
            }
        } else {
            int cnt = d1 - d2;
            for (int i = floor(log2(n)); i >= 0; i--) {
                if (cnt & (1 << i))
                    u = up[u][i]; // lift u
            }
        }
        cout << LCA(u, v) << "\n";
    }
    return 0;
}

// #include "bits/stdc++.h"
// using namespace std;
// #define int long long

// int n, q;
// vector<vector<int>> g;

// vector<int> first;
// vector<int> depth;
// vector<int> euler;

// void dfs(int u, int p, int d) {
//     first[u] = euler.size();

//     euler.push_back(u);
//     depth.push_back(d);

//     for (int v : g[u]) {
//         if (v == p)
//             continue;
//         dfs(v, u, d + 1);
//         euler.push_back(u);
//         depth.push_back(d);
//     }
// }

// struct Node {
//     int dep;
//     int node;

//     Node(int d = (int)1e18, int u = -1) {
//         dep = d;
//         node = u;
//     }
// };

// struct SegTree {
//     int size;
//     vector<Node> tree;

//     Node merge(Node a, Node b) {
//         if (a.dep <= b.dep)
//             return a;
//         return b;
//     }

//     void init(int n) {
//         size = 1;
//         while (size < n)
//             size <<= 1;

//         tree.assign(2 * size, Node());
//     }

//     void build(int x, int lx, int rx) {
//         if (rx - lx == 1) {
//             if (lx < (int)euler.size())
//                 tree[x] = Node(depth[lx], euler[lx]);
//             return;
//         }

//         int mid = (lx + rx) / 2;

//         build(2 * x + 1, lx, mid);
//         build(2 * x + 2, mid, rx);

//         tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
//     }

//     void build() {
//         build(0, 0, size);
//     }

//     Node query(int l, int r, int x, int lx, int rx) {
//         if (rx <= l || r <= lx)
//             return Node();

//         if (l <= lx && rx <= r)
//             return tree[x];

//         int mid = (lx + rx) / 2;

//         return merge(
//             query(l, r, 2 * x + 1, lx, mid),
//             query(l, r, 2 * x + 2, mid, rx));
//     }

//     Node query(int l, int r) {
//         return query(l, r, 0, 0, size);
//     }
// };

// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n >> q;

//     g.resize(n);
//     first.resize(n);

//     for (int i = 1; i < n; i++) {
//         int p;
//         cin >> p;
//         p--;

//         g[p].push_back(i);
//         g[i].push_back(p);
//     }

//     dfs(0, -1, 0);

//     SegTree st;
//     st.init(euler.size());
//     st.build();

//     while (q--) {
//         int u, v;
//         cin >> u >> v;
//         u--;
//         v--;

//         int l = first[u];
//         int r = first[v];

//         if (l > r)
//             swap(l, r);

//         cout << st.query(l, r + 1).node + 1 << '\n';
//     }
// }