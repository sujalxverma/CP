#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Node {
    long long mini, maxi;
    Node(long long maxi, long long mini) {
        this->maxi = maxi;
        this->mini = mini;
    }
};

struct SegTree {
    long long size;
    long long real_size;

    vector<Node> tree;
    Node NEUTRAL = Node(-1e18, -1e18); // neutral element for merge

    // merge two nodes
    // can be modified.
    Node merge(const Node &a, const Node &b) {
        long long maxi, mini;
        // if (a.maxi > b.maxi && a.mini > b.maxi) {
        //   return a;
        // }
        // if (a.maxi < b.maxi && a.maxi < b.mini) {
        //   return b;
        // }
        maxi = max(a.maxi, b.maxi);
        mini = max({a.mini, b.mini, (maxi == a.maxi ? b.maxi : a.maxi)});
        return Node(maxi, mini);
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
    void build(vector<long long> &arr, long long node, long long lx,
               long long rx) {
        if (rx - lx == 1) {
            if (lx < (long long)arr.size())
                tree[node] = Node(arr[lx], arr[lx]);
            return;
        }

        long long mid = (lx + rx) / 2;
        build(arr, 2 * node + 1, lx, mid);
        build(arr, 2 * node + 2, mid, rx);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void build(vector<long long> &arr) { build(arr, 0, 0, size); }

    // point update: set position i to value v
    void set(long long i, long long v, long long node, long long lx,
             long long rx) {
        if (rx - lx == 1) {
            tree[node] = Node(v, v);
            return;
        }

        long long mid = (lx + rx) / 2;
        if (i < mid)
            set(i, v, 2 * node + 1, lx, mid);
        else
            set(i, v, 2 * node + 2, mid, rx);

        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void set(long long i, long long v) { set(i, v, 0, 0, size); }

    // range query [l, r), to include r => [l,r+1)
    // long long x -> current node of the tree.
    Node query(long long l, long long r, long long node, long long lx,
               long long rx) {
        if (rx <= l || r <= lx)
            return NEUTRAL;
        if (l <= lx && rx <= r)
            return tree[node];

        long long mid = (lx + rx) / 2;
        Node left = query(l, r, 2 * node + 1, lx, mid);
        Node right = query(l, r, 2 * node + 2, mid, rx);
        return merge(left, right);
    }

    Node query(long long l, long long r) { return query(l, r, 0, 0, size); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    long long n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    SegTree st;
    st.init(n);
    st.build(a);
    long long q;
    cin >> q;

    while (q--) {
        char type;
        cin >> type;
        if (type == 'U') {
            long long l, v;
            cin >> l >> v;
            l--;
            st.set(l, v);
        } else {
            long long l, r;
            cin >> l >> r;
            l--;
            r--;
            auto ans = st.query(l, r);
            cout << ans.maxi + ans.mini << "\n";
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}