#include "bits/stdc++.h"
using namespace std;
using ll = long long ;
struct Node
{
    ll sum;
    ll maxSum;
    Node(ll s, ll mx)
    {
        sum = s;
        maxSum = mx;
    }
};

struct SegTree
{
    ll size;
    vector<Node> tree;
    Node NEUTRAL = Node(0LL, 0LL); // neutral element for merge

    // merge two nodes
    // can be modified.
    Node merge(const Node &a, const Node &b)
    {
        return Node((a.sum + b.sum), max({a.maxSum, (a.sum + b.maxSum)})); // example: sum segment tree
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
            if (lx < (int)arr.size())
                tree[x] = Node(arr[lx], arr[lx]);
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
            tree[x] = Node(v, v);
            return;
        }

        ll mid = (lx + rx) / 2;
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
    Node query(ll l, ll r, ll x, ll lx, ll rx)
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

    Node query(ll l, ll r)
    {
        return query(l, r, 0, 0, size);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    SegTree st;
    st.init(n);
    st.build(a);

    while (q--)
    {
        ll i;
        cin >> i;
        if (i == 1)
        {
            ll l, v;
            cin >> l >> v;
            l--;
            st.set(l, v);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            l--;
            cout << max(0LL,st.query(l, r).maxSum) << "\n";
        }
    }

    return 0;
}