#include "bits/stdc++.h"
using namespace std;

// no need of push function.
// every logic is [l,r)

struct SegTree
{

    int size;
    vector<int> tree, lazy;

    void init(int n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        tree.assign(2 * size, 0);
        lazy.assign(2 * size, 0);
    }

    // build.
    void build(vector<int> &a, int node, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)a.size())
            {
                tree[node] = a[lx];

            }
            return ;

        }

        int mid = (lx + rx) / 2;
        build(a, 2 * node + 1, lx, mid);
        build(a, 2 * node + 2, mid, rx);
    }

    void build(vector<int> &a)
    {
        build(a, 0, 0, size);
    }

    // update
    // [start , end)
    void update(int value, int start, int end, int node, int lx, int rx)
    {
        if (end <= lx || rx <= start)
        {
            return;
            // out of range.
        }

        if (start <= lx && rx <= end)
        {
            // can update this range.
            lazy[node] += value;
            return;
        }

        int mid = (lx + rx) / 2;

        update(value, start, end, 2 * node + 1, lx, mid);
        update(value, start, end, 2 * node + 2, mid, rx);
    }

    void update(int value, int start, int end)
    {
        update(value, start, end, 0, 0, size);
    }

    int query(int idx, int node, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            return tree[node] + lazy[node];
        }

        int mid = (lx + rx) / 2;
        if (idx < mid)
        {
            return query(idx, 2 * node + 1, lx, mid) + lazy[node];
        }
        else
        {
            return query(idx, 2 * node + 2, mid, rx) + lazy[node];
        }
    }

    int query(int idx)
    {
        return query(idx, 0, 0, size);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n,0);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }

    SegTree st;
    st.init(n);
    // st.build(a);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            st.update(v, l, r);
        }
        else
        {
            int idx;
            cin >> idx;
            cout << st.query(idx) << "\n";
        }
    }
    return 0;
}