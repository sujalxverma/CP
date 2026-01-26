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
    ll size;
    ll real_size;
    vector<Node> tree;
    Node NEUTRAL = Node(0); // neutral element for merge

    // merge two nodes
    // can be modified.
    Node merge(const Node &a, const Node &b)
    {
        return Node(a.val + b.val); // example: sum segment tree
    }

    // initialize tree
    void init(ll n)
    {
        real_size = n;
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
                tree[x] = Node(arr[lx]);
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
            tree[x] = Node(v);
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

    // range query [l, r), to include r => [l,r+1)
    // ll x -> current node of the tree.
    Node query(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (rx <= l || r <= lx)
            return NEUTRAL;
        if (l <= lx && rx <= r)
            return tree[x];

        ll mid = (lx + rx) / 2;
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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    SegTree st;
    st.init(n);
    st.build(a);
    while (m--)
    {
        ll q;
        cin >> q;
        if (q == 1)
        {
            ll i;
            cin >> i;
            i--;
            ll v1 = a[i];
            ll v2 = a[i + 1];
            a[i] = v2;
            a[i + 1] = v1;
            st.set(i, v2);
            st.set(i + 1, v1);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            l--;
            r--;
            // if( l == r){
            //     cout<<a[l]<<"\n";
            //     continue;
            // }
            cout << st.query(l, r + 1).val << "\n";
        }
    }
    return 0;
}