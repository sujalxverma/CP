#include "bits/stdc++.h"
using namespace std;

// no need of push function.
// every logic is [l,r)

struct SegTree
{

    long long size;
    vector<long long> tree, lazy;

    void init(long long n)
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
    void build(vector<long long> &a, long long node, long long lx, long long rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (long long)a.size())
            {
                tree[node] = a[lx];

            }
            return ;

        }

        long long mid = (lx + rx) / 2;
        build(a, 2 * node + 1, lx, mid);
        build(a, 2 * node + 2, mid, rx);
    }

    void build(vector<long long> &a)
    {
        build(a, 0, 0, size);
    }

    // update
    // [start , end)
    void update(long long value, long long start, long long end, long long node, long long lx, long long rx)
    {
        if (end <= lx || rx <= start)
        {
            return;
            // out of range.
        }

        if (start <= lx && rx <= end)
        {
            // can update this range.
            lazy[node] = max(value , lazy[node]);
            return;
        }

        long long mid = (lx + rx) / 2;

        update(value, start, end, 2 * node + 1, lx, mid);
        update(value, start, end, 2 * node + 2, mid, rx);
    }

    void update(long long value, long long start, long long end)
    {
        update(value, start, end, 0, 0, size);
    }

    long long query(long long idx, long long node, long long lx, long long rx)
    {
        if (rx - lx == 1)
        {
            return max(tree[node] , lazy[node]);
        }

        long long mid = (lx + rx) / 2;
        if (idx < mid)
        {
            return max(query(idx, 2 * node + 1, lx, mid) , lazy[node]);
        }
        else
        {
            return max(query(idx, 2 * node + 2, mid, rx) , lazy[node]);
        }
    }

    long long query(long long idx)
    {
        return query(idx, 0, 0, size);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, q;
    cin >> n >> q;
    vector<long long> a(n,0);
    // for (long long i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }

    SegTree st;
    st.init(n);
    // st.build(a);

    while (q--)
    {
        long long type;
        cin >> type;
        if (type == 1)
        {
            long long l, r, v;
            cin >> l >> r >> v;
            st.update(v, l, r);
        }
        else
        {
            long long idx;
            cin >> idx;
            cout << st.query(idx) << "\n";
        }
    }
    return 0;
}