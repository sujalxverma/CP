#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct SegmentTree
{

    int size;
    vector<ll> sums;
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        sums.assign(2 * size, 1000*1LL);
    }

    void build(vector<int> &a, int x, int lx, int rx)
    {
         // [lx , rx)
        if (rx - lx == 1)
        {
            if (lx < (int)a.size())
            {
                sums[x] = a[lx];
            }
            return;
        }
        int m = lx + (rx - lx) / 2;

        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);

        sums[x] = min(sums[2 * x + 1], sums[2 * x + 2]);
    }

    void build(vector<int> &a)
    {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            sums[x] = v;
            return;
        }
        int m = lx + (rx - lx) / 2;
        if (i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else
        {
            set(i, v, 2 * x + 2, m, rx);
        }
       sums[x] = min(sums[2 * x + 1], sums[2 * x + 2]);
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
        {
            return 1e9;
        }
        if (lx >= l && rx <= r)
        {
            return sums[x];
        }
        int m = lx + (rx - lx) / 2;
        ll s1 = sum(l, r, 2 * x + 1, lx, m);
        ll s2 = sum(l, r, 2 * x + 2, m, rx);

        return min(s1 , s2);
    }

    long long sum(int l, int r)
    {
        return sum(l, r, 0, 0, size);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    SegmentTree st;
    st.init(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        a[i] = v;
    }

    st.build(a);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            // set value.
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.sum(l, r) << "\n";
        }
    }

    return 0;
}