#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<ll> a;

struct SegTree
{
    int size;
    vector<pair<ll, ll>> tree; // {value , count}

    void init(int n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        tree.assign(2 * size, {1e18, 0});
    }

    pair<ll, ll> merge(const pair<ll, ll> &a, const pair<ll, ll> &b)
    {
        if (a.first == b.first)
        {
            return {a.first, a.second + b.second};
        }
        if (a.first < b.first)
        {
            return a;
        }
        else
        {
            return b;
        }
    }

    void build(int node, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)a.size()) // if lx lies inside array range.
            {
                tree[node] = {a[lx], 1};
                return;
            }
            return;
        }

        int mid = (lx + rx) / 2;

        build(2 * node + 1, lx, mid);
        build(2 * node + 2, mid, rx);

        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
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
            tree[node] = {value, 1};
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

        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(ll value, int idx)
    {
        update(value, idx, 0, 0, size);
    }

    pair<ll, ll> query(int l, int r, int node, int lx, int rx)
    {
        // no overlaping, out of required range.
        if (lx >= r || rx <= l)
        {
            return {1e18, 1};
        }
        if (l <= lx && rx <= r)
        {
            return tree[node];
        }

        int mid = (lx + rx) / 2;
        pair<ll, ll> left = query(l, r, 2 * node + 1, lx, mid);
        pair<ll, ll> right = query(l, r, 2 * node + 2, mid, rx);

        return merge(left, right);
    }

    pair<ll, ll> query(int l, int r)
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
            auto ans = st.query(l, r);
            cout << ans.first << " " << ans.second << "\n";
        }
    }

    return 0;
}