#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
using ll = long long ;
struct Node
{
    int val; // change type as needed
    // will store number of increasing subsequence.

    Node(int v = 0)
    {
        val = v;
    }
};

struct SegTree
{
    int size;
    vector<Node> tree;
    Node NEUTRAL = Node(0); // neutral element for merge

    // merge two nodes
    // can be modified.
    Node merge(const Node &a, const Node &b)
    {
        return Node((a.val + b.val )%mod); // example: sum segment tree
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
                tree[x] = Node(0); // at this point, 0 increasing susequences.
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
            // tree[x] = Node(v); Wrong, it rewrites the value, if it was already found, add to it, not overwrite.
            tree[x] = Node((v + tree[x].val)%mod);
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

    Node query(int l, int r) // [l,r)
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
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        a[i] = b[i] = k;
    }
    sort(begin(a), end(a));
    a.erase(unique(a.begin(), a.end()), a.end()); // compression of indices.

    SegTree st;
    st.init((int)a.size());
    st.build(a);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int value = b[i];

        int idx = lower_bound(begin(a), end(a), value) - a.begin();

        int l = 0;
        int r = idx;

        int count = (st.query(l, r).val + 1) % mod;
        ans  = (ans + count)%mod;
        st.set(r, count);
    }
    cout << ans << "\n";

    return 0;
}