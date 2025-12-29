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

struct SegTree
{
    int size;
    vector<Node> tree;
    Node NEUTRAL = Node(0); // neutral element for merge

    // merge two nodes
    // can be modified.
    Node merge(const Node &a, const Node &b)
    {
        return Node(a.val + b.val); // example: sum segment tree
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
    // void build(vector<int> &arr, int x, int lx, int rx)
    // {
    //     if (rx - lx == 1)
    //     {
    //         if (lx < (int)arr.size())
    //             tree[x] = Node(arr[lx]);
    //         return;
    //     }

    //     int mid = (lx + rx) / 2;
    //     build(arr, 2 * x + 1, lx, mid);
    //     build(arr, 2 * x + 2, mid, rx);
    //     tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    // }

    // void build(vector<int> &arr)
    // {
    //     build(arr, 0, 0, size);
    // }

    // point update: set position i to value v
    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = Node(1);
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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    // compressrion.
    vector<ll> b = a;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end()); // compressed.

    vector<pair<ll, ll>> p(n, {0, 0});
    SegTree st;
    st.init((int)a.size());

    for (int i = 0; i < n; i++)
    {
        auto idx = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        ll val = st.query(idx + 1, a.size()).val;

        st.set(idx, 1);
        p[i].first = val;
    }

    SegTree st2;
    st2.init((int)a.size());
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        auto idx = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        ll val = st2.query(0, idx).val;
        st2.set(idx, 1);
        p[n - 1 - i].second = val;
    }

    ll ans = 0;
    for (auto x : p)
    {
        ans += (x.first * x.second);
    }
    cout << ans << "\n";

    return 0;
}