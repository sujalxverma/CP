#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<ll> a;

struct SegTree
{
    int size;
    vector<ll> tree;

    void init(int n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        tree.assign(2 * size, 0);
    }

    void build(int node, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)a.size()) // if lx lies inside array range.
            {
                tree[node] = a[lx];
                return;
            }
            return;
        }

        int mid = (lx + rx) / 2;

        build(2 * node + 1, lx, mid);
        build(2 * node + 2, mid, rx);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    // lx and rx lies within [0,size)
    void build()
    {
        build(0, 0, size);
    }

    void update(ll value, int idx, int node, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[node] = value;
            return;
        }
        int mid = (lx + rx) / 2;
        if (idx < mid)
        {
            update(value, idx, 2 * node + 1, lx, mid);
        }
        else
        {
            update(value, idx, 2 * node + 2, mid, rx);
        }

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void update(ll value, int idx)
    {
        update(value, idx, 0, 0, size);
    }

    ll query(int l, int r, int node, int lx, int rx)
    {
        // no overlaping, out of required range.
        if (lx >= r || rx <= l)
        {
            return 0;
        }
        if (l <= lx && rx <= r)
        {
            return tree[node];
        }

        int mid = (lx + rx) / 2;
        ll left = query(l, r, 2 * node + 1, lx, mid);
        ll right = query(l, r, 2 * node + 2, mid, rx);

        return left + right;
    }

    ll query(int l, int r)
    {
        return query(l, r, 0, 0, size);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (auto &x : a)
        cin >> x;

    // for (auto &x : a)
    //     cout << x << " ";

    SegTree st;
    st.init(n);
    st.build();

    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int idx;
            ll value;
            cin >> idx >> value;
            st.update(value, idx);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r) << "\n";
        }
    }

    return 0;
}