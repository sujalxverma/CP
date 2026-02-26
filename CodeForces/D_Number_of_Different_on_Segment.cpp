#include "bits/stdc++.h"
using namespace std;
vector<int> f(41, -1);

struct Node
{
    int count = 0;
    int fr[41] = {0};
};

struct SegTree
{
    int size;
    int real_size;
    vector<Node> tree;

    // merge two nodes
    // can be modified.
    Node NEUTRAL;
    // memset(NEUTRAL.fr, 0, sizeof NEUTRAL.fr);
    // NEUTRAL.count = 0;
    Node merge(const Node &a, const Node &b)
    {
        Node result;
        result.count = 0;
        memset(result.fr, 0, sizeof result.fr);
        for (int i = 1; i <= 40; i++)
        {
            result.fr[i] = a.fr[i] + b.fr[i];
        }
        for (int i = 1; i <= 40; i++)
        {
            if (result.fr[i] <= 0)
                continue;
            result.count++;
        }

        return result;
    }

    // initialize tree
    void init(int n)
    {
        real_size = n;
        size = 1;
        while (size < n)
            size <<= 1;
        tree.assign(2 * size, NEUTRAL);
    }

    // build from array
    void build(vector<int> &arr, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)arr.size())
            {
                Node r;
                r.fr[arr[lx]] = 1;
                r.count = 1;
                tree[x] = r;
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, mid);
        build(arr, 2 * x + 2, mid, rx);

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(vector<int> &arr)
    {
        build(arr, 0, 0, size);
    }

    // point update: set position i to value v
    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            memset(tree[x].fr, 0, sizeof tree[x].fr);
            tree[x].fr[v]++;
            tree[x].count = 1;
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid)
            set(i, v, 2 * x + 1, lx, mid);
        else
            set(i, v, 2 * x + 2, mid, rx);

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    // range query [l, r), to include r => [l,r+1)
    // int x -> current node of the tree.
    Node query(int l, int r, int x, int lx, int rx)
    {
        if (rx <= l || r <= lx)
            return NEUTRAL;
        if (l <= lx && rx <= r)
            return tree[x];

        int mid = (lx + rx) / 2;
        Node left = query(l, r, 2 * x + 1, lx, mid);
        Node right = query(l, r, 2 * x + 2, mid, rx);
        return merge(left, right);
    }

    Node query(int l, int r)
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
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    SegTree st;
    st.init(n);
    st.build(a);

    while (q--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            auto ans = st.query(l, r + 1);
            cout << ans.count << "\n";
        }
        else
        {
            int i, v;
            cin >> i >> v;
            i--;
            st.set(i, v);
        }
    }

    return 0;
}