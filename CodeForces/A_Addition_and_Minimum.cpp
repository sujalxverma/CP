#include "bits/stdc++.h"
using namespace std;

struct Node
{
    long long val; // stores sum of segment

    Node(long long v = 0)
    {
        val = v;
    }
};

struct SegTree
{
    int size;
    int real_size;
    vector<Node> tree;
    vector<char> marked;
    vector<long long> lazy; // lazy array for range add
    Node NEUTRAL = Node(0);

    // merge function (sum)
    Node merge(const Node &a, const Node &b)
    {
        return Node(min(a.val , b.val));
    }

    void init(int n)
    {
        real_size = n;
        size = 1;
        while (size < n)
            size <<= 1;

        tree.assign(2 * size, NEUTRAL);
        lazy.assign(2 * size, 0LL);
        marked.assign(2 * size, false);
    }

    // build
    void build(vector<int> &arr, int node, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)arr.size())
                tree[node] = Node(arr[lx]);
            return;
        }

        int mid = (lx + rx) / 2;
        build(arr, 2 * node + 1, lx, mid);
        build(arr, 2 * node + 2, mid, rx);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void build(vector<int> &arr)
    {
        build(arr, 0, 0, size);
    }

    // apply lazy value to node
    void apply(int node, int lx, int rx, long long v)
    {
        tree[node].val +=  v; // update segment sum
        lazy[node] += v;
        marked[node] = true;
    }

    // push lazy to children
    void push(int node, int lx, int rx)
    {
        if (!marked[node] || rx - lx == 1)
            return;

        int mid = (lx + rx) / 2;

        apply(2 * node + 1, lx, mid, lazy[node]);
        apply(2 * node + 2, mid, rx, lazy[node]);

        lazy[node] = 0;
        marked[node] = false;
    }

    // range add [l, r)
    void update(int l, int r, long long v, int node, int lx, int rx)
    {
        if (rx <= l || r <= lx)
            return;

        if (l <= lx && rx <= r)
        {
            apply(node, lx, rx, v);
            return;
        }

        push(node, lx, rx);

        int mid = (lx + rx) / 2;
        update(l, r, v, 2 * node + 1, lx, mid);
        update(l, r, v, 2 * node + 2, mid, rx);

        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int l, int r, long long v)
    {
        update(l, r, v, 0, 0, size);
    }

    // range query [l, r)
    Node query(int l, int r, int node, int lx, int rx)
    {
        if (rx <= l || r <= lx)
            return Node(1e18);

        if (l <= lx && rx <= r)
            return tree[node];

        push(node, lx, rx);

        int mid = (lx + rx) / 2;
        Node left = query(l, r, 2 * node + 1, lx, mid);
        Node right = query(l, r, 2 * node + 2, mid, rx);

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

    long long n, q;
    cin >> n >> q;
    // vector<long long> a(n, 0);
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
            st.update(l, r, v);
        }
        else
        {
            int l,r;
            cin >> l >> r;
            cout<<st.query(l , r).val<<"\n";
        }
    }
    return 0;
}