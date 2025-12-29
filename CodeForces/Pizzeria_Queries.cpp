#include "bits/stdc++.h"
using namespace std;
using ll = long long;
struct Node
{
    long long val; // change type as needed

    Node(long long v = 0)
    {
        val = v;
    }
};

// left side
struct SegTree
{
    ll size;
    vector<Node> tree;
    Node NEUTRAL = Node(1e8); // neutral element for merge

    // merge two nodes
    // can be modified.
    Node merge(const Node &a, const Node &b)
    {
        return Node(min(a.val, b.val)); // example: sum segment tree
    }

    // initialize tree
    void init(ll n)
    {
        size = 1;
        while (size < n)
            size <<= 1;
        tree.assign(2 * size, NEUTRAL);
    }

    // build from array
    void build(vector<ll> &arr, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (ll)arr.size())
                tree[x] = Node(arr[lx] - (lx + 1));
            return;
        }

        ll mid = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, mid);
        build(arr, 2 * x + 2, mid, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(vector<ll> &arr)
    {
        build(arr, 0, 0, size);
    }

    // point update: set position i to value v
    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = Node(v - (lx + 1));
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid)
            set(i, v, 2 * x + 1, lx, mid);
        else
            set(i, v, 2 * x + 2, mid, rx);

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(ll i, ll v)
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

// right side
struct SegTree2
{
    ll size;
    vector<Node> tree;
    Node NEUTRAL = Node(1e8); // neutral element for merge

    // merge two nodes
    // can be modified.
    Node merge(const Node &a, const Node &b)
    {
        return Node(min(a.val, b.val)); // example: sum segment tree
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
    void build(vector<ll> &arr, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)arr.size())
                tree[x] = Node(arr[lx] + (lx + 1));
            return;
        }

        int mid = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, mid);
        build(arr, 2 * x + 2, mid, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(vector<ll> &arr)
    {
        build(arr, 0, 0, size);
    }

    // point update: set position i to value v
    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = Node(v + (lx + 1));
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid)
            set(i, v, 2 * x + 1, lx, mid);
        else
            set(i, v, 2 * x + 2, mid, rx);

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(ll i, ll v)
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

    vector<ll> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }

    SegTree st1;
    st1.init(n);
    st1.build(a);
    SegTree2 st2;
    st2.init(n);
    st2.build(a);

    while (q--)
    {
        int i;
        cin >> i;
        if (i == 1)
        {
            int l, v;
            cin >> l >> v;
            l--;
            a[l] = v;
            st1.set(l, v);
            st2.set(l, v);
        }

        else
        {
            int k;
            cin >> k;
            k--;
            cout << min({st1.query(0, k+1).val + k+1, st2.query(k , n).val - k-1}) << "\n";
        }
    }
    return 0;
}