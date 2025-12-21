#include "bits/stdc++.h"
using namespace std;
const int inf = 1e9;

struct Node
{
    int val; // change type as needed
    int count;

    Node(int v, int c)
    {
        val = v;
        count = c;
    }
};

struct SegTree
{
    int size;
    vector<Node> tree;
    Node NEUTRAL = Node(inf, 0); // neutral element for merge

    // merge two nodes
    // can be modified.
    Node merge(const Node &a, const Node &b)
    {

        if (a.val < b.val)
        {
            return a;
        }
        else if (a.val > b.val)
        {
            return b;
        }
        return {a.val, a.count + b.count};
    }

    // initialize tree
    void init(int n)
    {
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
                tree[x] = Node(arr[lx], 1);
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
            tree[x] = Node(v, 1);
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

    // range query [l, r)
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
    for (int i = 0; i < n; i++)
        cin >> a[i];

    SegTree st;
    st.init(n);
    st.build(a);

    while (q--)
    {
        int k;
        cin >> k;
        if (k == 1)
        {
            // update
            int a, b;
            cin >> a >> b;
            st.set(a, b);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            auto ans = st.query(a, b);
            cout << ans.val << " " << ans.count << "\n";
        }
    }
    return 0;
}