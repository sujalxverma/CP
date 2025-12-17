#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int INF = 1e9 + 7;
struct SegmentTree
{

    int size;
    vector<pair<int, int>> tree;

    // pair<int, int> merge(pair<int, int> a, pair<int, int> b)
    // {
    //     if (a.first < b.first)
    //         return a;
    //     if (b.first < a.first)
    //         return b;
    //     return {a.first, a.second + b.second};
    // }

    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(2 * size, {INF, 0});
    }

    void build(vector<int> &a, int x, int lx, int rx)
    {
        // [lx , rx)
        if (rx - lx == 1)
        {
            if (lx < (int)a.size())
            {
                tree[x] = {a[lx], 1};
            }
            return;
        }
        int m = lx + (rx - lx) / 2;

        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);

        if (tree[2 * x + 1].first > tree[2 * x + 2].first)
        {
            tree[x].first = tree[2 * x + 2].first;
            tree[x].second = tree[2 * x + 2].second;
        }
        else if (tree[2 * x + 1].first < tree[2 * x + 2].first)
        {
            tree[x].first = tree[2 * x + 1].first;
            tree[x].second = tree[2 * x + 1].second;
        }
        else
        {
            tree[x].first = tree[2 * x + 1].first;
            tree[x].second = tree[2 * x + 1].second + tree[2 * x + 2].second;
        }
    }

    void build(vector<int> &a)
    {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {

            tree[x].first = v;
            tree[x].second = 1;
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

        if (tree[2 * x + 1].first > tree[2 * x + 2].first)
        {
            tree[x].first = tree[2 * x + 2].first;
            tree[x].second = tree[2 * x + 2].second;
        }
        else if (tree[2 * x + 1].first < tree[2 * x + 2].first)
        {
            tree[x].first = tree[2 * x + 1].first;
            tree[x].second = tree[2 * x + 1].second;
        }
        else
        {
            tree[x].first = tree[2 * x + 1].first;
            tree[x].second = tree[2 * x + 1].second + tree[2 * x + 2].second;
        }
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    pair<int, int> minimumCount(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
        {
            // range exceeded the desired.
            return {1e9, 0};
        }
        if (lx >= l && rx <= r)
        {
            return {tree[x].first, tree[x].second};
        }
        int m = lx + (rx - lx) / 2;
        auto s1 = minimumCount(l, r, 2 * x + 1, lx, m);
        auto s2 = minimumCount(l, r, 2 * x + 2, m, rx);

        if (s1.first < s2.first)
        {
            return s1;
        }
        else if (s2.first < s1.first)
        {
            return s2;
        }
        else
        {
            return {s1.first, s1.second + s2.second};
        }
    }

    pair<int, int> minimumCount(int l, int r)
    {
        return minimumCount(l, r, 0, 0, size);
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
            cout << st.minimumCount(l, r).first << " " << st.minimumCount(l, r).second << "\n";
        }
    }

    return 0;
}