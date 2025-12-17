#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct item {
    ll seg, pref, suf, sum;
};

struct SegTree {
    int size;
    vector<item> tree;

    item NEUTRAL = {0, 0, 0, 0};

    item merge(item a, item b) {
        return {
            max({a.seg, b.seg, a.suf + b.pref}),
            max(a.pref, a.sum + b.pref),
            max(b.suf, b.sum + a.suf),
            a.sum + b.sum
        };
    }

    item make_item(ll v) {
        return {
            max(v, 0LL),
            max(v, 0LL),
            max(v, 0LL),
            v
        };
    }

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, NEUTRAL);
    }

    void build(vector<ll>& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size())
                tree[x] = make_item(a[lx]);
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        tree[x] = merge(tree[2*x+1], tree[2*x+2]);
    }

    void build(vector<ll>& a) {
        build(a, 0, 0, size);
    }

    void set(int i, ll v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = make_item(v);
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2*x+1, lx, m);
        else
            set(i, v, 2*x+2, m, rx);

        tree[x] = merge(tree[2*x+1], tree[2*x+2]);
    }

    void set(int i, ll v) {
        set(i, v, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    SegTree st;
    st.init(n);
    st.build(a);

    // before any operations
    cout << st.tree[0].seg << "\n";

    while (m--) {
        int i;
        ll v;
        cin >> i >> v;
        st.set(i, v);
        cout << st.tree[0].seg << "\n";
    }

    return 0;
}
