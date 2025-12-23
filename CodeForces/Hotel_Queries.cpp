#include "bits/stdc++.h"
using namespace std;

// iterative segment tree.

struct SegTree {
    int size;
    vector<int> tree;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, 0);
    }

    void build(const vector<int>& a) {
        // insert leaves
        for (int i = 0; i < (int)a.size(); i++) {
            tree[size + i] = a[i];
        }
        // build parents
        for (int i = size - 1; i >= 1; i--) {
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
        }
    }

    int query(int req) {
        if (tree[1] < req) return -1; // no hotel can satisfy

        int idx = 1;
        // descend to leaf
        while (idx < size) {
            if (tree[2 * idx] >= req)
                idx = 2 * idx;
            else
                idx = 2 * idx + 1;
        }

        // update leaf
        tree[idx] -= req;
        int pos = idx - size;

        // update parents
        idx >>= 1;
        while (idx >= 1) {
            tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
            idx >>= 1;
        }

        return pos;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    SegTree st;
    st.init(n);
    st.build(a);

    for (int i = 0; i < m; i++) {
        int res = st.query(b[i]);
        if (res == -1)
            cout << "0 ";
        else
            cout << res + 1 << " ";
    }
    cout << "\n";

    return 0;
}
