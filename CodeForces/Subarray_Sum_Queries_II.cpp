#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct Node {
    ll sum, pref, suf, best;
};

struct SegTree {
    int n;
    vector<Node> st;

    Node NEUTRAL = {0, 0, 0, 0};

    Node merge(const Node &a, const Node &b) {
        return {
            a.sum + b.sum,
            max(a.pref, a.sum + b.pref),
            max(b.suf, b.sum + a.suf),
            max({a.best, b.best, a.suf + b.pref})
        };
    }

    Node make_node(ll x) {
        return {x, max(x, 0LL), max(x, 0LL), max(x, 0LL)};
    }

    void build(int idx, int l, int r, const vector<ll> &a) {
        if (r - l == 1) {
            st[idx] = make_node(a[l]);
            return;
        }
        int m = (l + r) / 2;
        build(2*idx, l, m, a);
        build(2*idx+1, m, r, a);
        st[idx] = merge(st[2*idx], st[2*idx+1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) return NEUTRAL;
        if (ql <= l && r <= qr) return st[idx];
        int m = (l + r) / 2;
        return merge(
            query(2*idx, l, m, ql, qr),
            query(2*idx+1, m, r, ql, qr)
        );
    }

    SegTree(const vector<ll> &a) {
        n = a.size();
        st.resize(4*n);
        build(1, 0, n, a);
    }

    ll get(int l, int r) {
        return query(1, 0, n, l, r).best;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    SegTree st(a);

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l; // convert to 0-based
        cout << st.get(l, r) << "\n";
    }
}
