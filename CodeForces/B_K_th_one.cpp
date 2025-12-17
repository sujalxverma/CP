#include "bits/stdc++.h"
using namespace std;

struct SegmentTree
{
    int size;
    vector<long long> sums;

    void init(int n)
    {
        size = 1;
        while (size < n)
            size <<= 1;
        sums.assign(2 * size, 0LL);
    }

    void build(vector<long long> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)a.size())
                sums[x] = a[lx];
            return;
        }

        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void build(vector<long long> &a)
    {
        build(a, 0, 0, size);
    }

    void set(int i, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            sums[x] = !sums[x];
            return;
        }

        int m = (lx + rx) / 2;
        if (i < m)
            set(i, 2 * x + 1, lx, m);
        else
            set(i, 2 * x + 2, m, rx);

        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(int i)
    {
        set(i, 0, 0, size);
    }

    long long sum(int x, int l, int r, int lx, int rx)
    {
        if (rx <= l || r <= lx)
            return 0LL;

        if (l <= lx && rx <= r)
            return sums[x];

        int m = (lx + rx) / 2;
        long long s1 = sum(2 * x + 1, l, r, lx, m);
        long long s2 = sum(2 * x + 2, l, r, m, rx);
        return s1 + s2;
    }

    long long sum(int l, int r)
    {
        return sum(0, l, r, 0, size);
    }

    int kthone(int k, int x, int lx, int rx)
    {
        if (rx - lx == 1)
            return lx;

        int m = (lx + rx) / 2;

        if (sums[2 * x + 1] > k)
            return kthone(k, 2 * x + 1, lx, m);
        else
            return kthone(k - sums[2 * x + 1], 2 * x + 2, m, rx);
    }

    int kthone(int k)
    {
        if (sums[0] <= k)
            return -1; // not found
        return kthone(k, 0, 0, size);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    SegmentTree st;
    st.init(n);
    st.build(a);

    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int i;

            cin >> i;
            st.set(i);
        }
        else
        {
            int k;
            cin >> k;
            cout << st.kthone(k) << "\n"; // [l, r)
        }
    }
    return 0;
}
