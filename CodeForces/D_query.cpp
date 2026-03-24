#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Node {
    unordered_set<int> s; // change type as needed

    Node(unordered_set<int> st) {
        s = st;
    }
};

struct SegTree {
    int size;
    int real_size;
    vector<Node> tree;
    Node NEUTRAL = Node({}); // neutral element for merge

    // merge two nodes
    // can be modified.
    Node merge(const Node &a, const Node &b) {
        unordered_set<int> st;
        st.insert(a.s.begin(), a.s.end());
        st.insert(b.s.begin(), b.s.end());

        return Node(st); // example: sum segment tree
    }

    // initialize tree
    void init(int n) {
        real_size = n;
        size = 1;
        while (size < n)
            size <<= 1;
        tree.assign(2 * size, NEUTRAL);
    }

    // build from array
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t = 1;
    while (t--) {
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
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            cout << (int)st.query(l, r + 1).s.size() << "\n";
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}
