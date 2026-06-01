#include "bits/stdc++.h"
using namespace std;
vector<long long> idx;
struct Node {
    long long mask; // change type as needed

    Node(long long v) {
        mask = v;
    }
};

struct SegTree {
    long long size;
    long long real_size;
    vector<Node> tree;
    Node NEUTRAL = Node(0); // neutral element for merge

    // merge two nodes
    // can be modified.
    Node merge(const Node &a, const Node &b) {
        return Node(a.mask | b.mask);
    }

    // initialize tree
    void init(long long n) {
        real_size = n;
        size = 1;
        while (size < n)
            size <<= 1;
        tree.assign(2 * size, NEUTRAL);
    }

    // build from array
    void build(vector<long long> &arr, long long node, long long lx, long long rx) {
        if (rx - lx == 1) {
            if (lx < (long long)arr.size())
                tree[node] = Node(1 << (idx[upper_bound(begin(idx), end(idx), arr[lx]) - begin(idx) - 1]));
            return;
        }

        long long mid = (lx + rx) / 2;
        build(arr, 2 * node + 1, lx, mid);
        build(arr, 2 * node + 2, mid, rx);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void build(vector<long long> &arr) {
        build(arr, 0, 0, size);
    }

    // range query [l, r), to include r => [l,r+1)
    // long long x -> current node of the tree.
    Node query(long long l, long long r, long long node, long long lx, long long rx) {
        if (rx <= l || r <= lx)
            return NEUTRAL;
        if (l <= lx && rx <= r)
            return tree[node];

        long long mid = (lx + rx) / 2;
        Node left = query(l, r, 2 * node + 1, lx, mid);
        Node right = query(l, r, 2 * node + 2, mid, rx);
        return merge(left, right);
    }

    Node query(long long l, long long r) {
        return query(l, r, 0, 0, size);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, q;
    cin >> n >> q;
    vector<long long> a(n);

    for (long long i = 0; i < n; i++) {
        cin >> a[i];
        idx.push_back(a[i]);
    }
    sort(begin(idx), end(idx));
    idx.erase(unique(begin(idx), end(idx)), end(idx));
    SegTree st;
    st.init(n);
    st.build(a);

    while (q--) {
        long long l, r;
        cin >> l >> r;
        l--;
        auto x = st.query(l, r).mask;
        cout << __builtin_popcount(x) << "\n";
    }
    return 0;
}