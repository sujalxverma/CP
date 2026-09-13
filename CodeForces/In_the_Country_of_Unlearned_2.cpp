#include "bits/stdc++.h"
using namespace std;

struct Node {
    int mini, maxi;
    Node(int a = 1e9, int b = -1e9) {
        mini = a;
        maxi = b;
    }
};

struct SegTree {
    int size;
    int real_size;
    vector<Node> tree;
    Node NEUTRAL; // neutral element for merge

    // merge two nodes
    // can be modified.
    Node merge(const Node &a, const Node &b) {
        return Node(
            min(a.mini, b.mini),
            max(a.maxi, b.maxi));
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
                tree[node] = Node(arr[lx], arr[lx]);
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
            tree[node] = Node(v, v);
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SegTree st;
    st.init(n);
    st.build(a);
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            int l, r;
            cin >> l >> r;
            auto ans = st.query(l - 1, r);
            if (ans.maxi == ans.mini) {
                cout << "draw\n";
            } else {
                cout << "wins\n";
            }

        } else {
            int idx, v;
            cin >> idx >> v;
            st.set(idx - 1, v);
        }
    }
}
