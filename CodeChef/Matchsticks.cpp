#include "bits/stdc++.h"
using namespace std;

/*
1. Use Segment tree to store minValue and maxValue of every segment.
2. Then take minValue of [l,r] as prer query, it will burn first.
3. In [l,r] the longest burn matchstick will be the segment max.
4. So total time = (minValue + max({max from remaining segment , ([l,r]maxValue - [l,r]minValue )/2   }) );
*/

struct Node
{
    int minValue; // change type as needed
    int maxiValue;

    Node(int mini, int maxi)
    {
        minValue = mini;
        maxiValue = maxi;
    }
};

struct SegTree
{
    int size;
    int real_size;
    vector<Node> tree;
    Node NEUTRAL = Node(1e9, 0); // neutral element for merge

    // merge two nodes
    // can be modified.
    Node merge(const Node &a, const Node &b)
    {
        return Node(min(a.minValue, b.minValue), max(a.maxiValue, b.maxiValue));
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
                tree[x] = Node(arr[lx], arr[lx]);
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    SegTree st;
    st.init(n);
    st.build(a);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r; // already 0 based indexing.
        int minvalue = st.query(l, r + 1).minValue;
        double halfmax = (st.query(l, r + 1).maxiValue - minvalue) / (2.0);

        double best = max({(double)st.query(0, l).maxiValue,
                           (double)st.query(r + 1, n).maxiValue,
                           halfmax});

        double ans = minvalue + best;
        cout << fixed << setprecision(1) << ans << "\n";
    }
    return 0;
}