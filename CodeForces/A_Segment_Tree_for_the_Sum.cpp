#include "bits/stdc++.h"
using namespace std;
#define int long long

struct SegTree {
    // everything is public by default.
    vector<int> tree;
    int size;
    const int NEUTRAL = 0;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        tree.assign(2 * size, NEUTRAL);
    }

    void build(vector<int> &a, int x, int l, int r) {
        if (r - l == 1) {
            if (l < (int)a.size()) {
                tree[x] = a[l];
            }
            return;
        }
        int m = (l + r) / 2;
        build(a, 2 * x + 1, l, m);
        build(a, 2 * x + 2, m, r);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
    void build(vector<int> &a) {
        build(a, 0, 0, size);
    }

    void set(int x, int idx, int v, int l, int r) {
        if (r - l == 1) {
            tree[x] = v;
            return;
        }
        int m = (l + r) / 2;
        if (idx < m) {
            set(2 * x + 1, idx, v, l, m);
        } else {
            set(2 * x + 2, idx, v, m, r);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2]; // postorder update
        // first complete child, then parent.
    }
    void set(int idx, int v) {
        set(0, idx, v, 0, size);
    }
    int query(int x, int l, int r, int lx, int rx) {
        if (l <= lx && rx <= r) {
            return tree[x]; // tree[x] -> [lx,rx)
        }
        if (rx <= l || r <= lx) {
            return NEUTRAL;
        }
        int m = (lx + rx) / 2;
        int left = query(2 * x + 1, l, r, lx, m);
        int right = query(2 * x + 2, l, r, m, rx);
        return left + right;
    }
    int query(int l, int r) {
        return query(0, l, r, 0, size); // l,r -> query range
                                        // lx,rx -> range cover by node x.
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    SegTree st;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    st.init(n);
    st.build(a);
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            int idx, v;
            cin >> idx >> v;
            st.set(idx, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r) << "\n";
        }
    }
    return 0;
}