#include "bits/stdc++.h"
using namespace std;
struct Node {
    int ones = 0;
    int len = 0;
    Node(int o, int l) {
        ones = o;
        len = l;
    }
};

struct SegTree {
    int size;
    int real_size;
    vector<Node> tree;
    vector<char> marked;
    vector<long long> lazy; // lazy array for range add
    Node NEUTRAL = Node({0, 0});

    // merge function (sum)
    Node merge(const Node &a, const Node &b) {
        int total = a.ones + b.ones;
        int suffix = b.len;
    }

    void init(int n) {
        real_size = n;
        size = 1;
        while (size < n)
            size <<= 1;

        tree.assign(2 * size, NEUTRAL);
        lazy.assign(2 * size, 0LL);
        marked.assign(2 * size, false); // false -> no pending operation
    }

    // build
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

    // apply lazy value to node
    void apply(int node, int lx, int rx, long long v) {
        tree[node].val += (rx - lx) * v; // update segment sum
        lazy[node] += v;
        marked[node] = true;
    }

    // push lazy to children
    void push(int node, int lx, int rx) {
        if (!marked[node] || rx - lx == 1)
            return;

        int mid = (lx + rx) / 2;

        apply(2 * node + 1, lx, mid, lazy[node]);
        apply(2 * node + 2, mid, rx, lazy[node]);

        lazy[node] = 0;
        marked[node] = false;
    }

    // range add [l, r)
    void update(int l, int r, long long v, int node, int lx, int rx) {
        if (rx <= l || r <= lx)
            return;

        if (l <= lx && rx <= r) {
            apply(node, lx, rx, v);
            return;
        }

        push(node, lx, rx);

        int mid = (lx + rx) / 2;
        update(l, r, v, 2 * node + 1, lx, mid);
        update(l, r, v, 2 * node + 2, mid, rx);

        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int l, int r, long long v) {
        update(l, r, v, 0, 0, size);
    }

    // range query [l, r)
    Node query(int l, int r, int node, int lx, int rx) {
        if (rx <= l || r <= lx)
            return NEUTRAL;

        if (l <= lx && rx <= r)
            return tree[node];

        push(node, lx, rx);

        int mid = (lx + rx) / 2;
        Node left = query(l, r, 2 * node + 1, lx, mid);
        Node right = query(l, r, 2 * node + 2, mid, rx);

        return merge(left, right);
    }

    Node query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n, 0);

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x == 0) {
        }
        if (x == 1) {
        }
        if (x == 2) {
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}