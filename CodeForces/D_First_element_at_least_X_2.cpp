#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int INF = 1e9 + 7;

/*
Check the chldren, not the node itself.
*/
struct SegmentTree
{

    int size;
    vector<pair<int, int>> tree;
    // {maxValue , its index}

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
        tree.assign(2 * size, {-1e8, -1});
    }

    void build(vector<int> &a, int x, int lx, int rx)
    {
        // [lx , rx)
        if (rx - lx == 1)
        {
            if (lx < (int)a.size())
            {
                tree[x] = {a[lx], lx};
            }
            return;
        }
        int m = lx + (rx - lx) / 2;

        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);

        if (tree[2 * x + 1].first < tree[2 * x + 2].first)
        {
            tree[x].first = tree[2 * x + 2].first;
            tree[x].second = tree[2 * x + 2].second;
        }
        else if (tree[2 * x + 1].first > tree[2 * x + 2].first)
        {
            tree[x].first = tree[2 * x + 1].first;
            tree[x].second = tree[2 * x + 1].second;
        }
        else
        {
            tree[x].first = tree[2 * x + 1].first;
            tree[x].second = tree[2 * x + 1].second;
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
            tree[x].second = lx;
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

        if (tree[2 * x + 1].first < tree[2 * x + 2].first)
        {
            tree[x].first = tree[2 * x + 2].first;
            tree[x].second = tree[2 * x + 2].second;
        }
        else if (tree[2 * x + 1].first > tree[2 * x + 2].first)
        {
            tree[x].first = tree[2 * x + 1].first;
            tree[x].second = tree[2 * x + 1].second;
        }
        else
        {
            tree[x].first = tree[2 * x + 1].first;
            tree[x].second = tree[2 * x + 1].second;
        }
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    int minIdx(int v, int l, int x, int lx, int rx)
    {

        if (rx <= l)
            return -1;
        if (tree[x].first < v)
            return -1;

        if (rx - lx == 1)
            return lx;

        int m = (lx + rx) / 2;

        int left = minIdx(v, l, 2 * x + 1, lx, m);
        if (left != -1)
            return left;  
        // if after going left still we do not found idx, then we go to right.
        return minIdx(v, l, 2 * x + 2, m, rx);
    }

    int minIdx(int v, int l)
    {
        if (tree[0].first < v)
        {
            return -1;
        }
        return minIdx(v, l, 0, 0, size);
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
            int v;
            cin >> v;
            int l;
            cin >> l;
            cout << st.minIdx(v, l) << "\n";
        }
    }

    return 0;
}