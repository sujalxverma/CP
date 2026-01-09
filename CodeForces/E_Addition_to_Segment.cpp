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
    int real_size ;
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
        real_size = n;
        size = 1;
        while (size < n)
            size <<= 1;
        tree.assign(2 * size, NEUTRAL);
    }

   

    // point update: set position i to value v
    void set(int l, int r, ll v, int x, int lx, int rx)
    {
        if (lx >= real_size) return;              
        if (rx <= l || r <= lx)
            return;

        if (l <= lx && rx <= r)
        {
            tree[x].val += v;
            return;
        }

        int m = (lx + rx) / 2;
        set(l, r, v, 2 * x + 1, lx, m);
        set(l, r, v, 2 * x + 2, m, rx);
    }

    void set(int l, int r, ll v)
    {
        set(l, r, v, 0, 0, size);
    }

    // range query [l, r)
    // int x -> current node of the tree.
    void query(int i, ll &ans, int x, int lx, int rx)
    {
        ans += tree[x].val; // ALWAYS add current node

        if (rx - lx == 1) // leaf
            return;

        int m = (lx + rx) / 2;
        if (i < m)
        {
            // go left
            query(i, ans, 2 * x + 1, lx, m);
        }
        else
        {
            query(i, ans, 2 * x + 2, m, rx);
        }
    }

    void query(int i, ll &ans)
    {
        query(i, ans, 0, 0, size);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    SegTree st;
    st.init(n);

    while (m--)
    {
        int i;
        cin >> i;
        if (i == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            // r++; // [l,r+1)
            st.set(l, r, x);
        }
        else
        {
            int i;
            cin >> i;
            ll ans = 0;
            st.query(i, ans);
            cout << ans << "\n";
        }
    }
    return 0;
}