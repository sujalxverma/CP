#include "bits/stdc++.h"
using namespace std;

struct Node
{
    vector<int> val;

    Node(vector<int> v)
    {

        val = v;
    }
};

struct SegTree
{
    int size;
    vector<Node> tree;
    Node NEUTRAL = Node({}); // neutral element for merge, array containing zero element.

    // merge two nodes
    // can be modified.
    Node merge(const Node &a, const Node &b)
    {
        int i = 0;
        int j = 0;
        vector<int> v;
        while (i < (int)a.val.size() && j < (int)b.val.size())
        {
            if (a.val[i] <= b.val[j])
            {
                v.push_back(a.val[i]);
                i++;
            }
            else
            {
                v.push_back(b.val[j]);
                j++;
            }
        }

        if (i < (int)a.val.size())
        {
            while (i < (int)a.val.size())
            {
                v.push_back(a.val[i]);
                i++;
            }
        }
        if (j < (int)b.val.size())
        {
            while (j < (int)b.val.size())
            {
                v.push_back(b.val[j]);
                j++;
            }
        }
        // simply merge sort.
        return v;
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
                tree[x] = Node({arr[lx]});
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

    // range query [l, r)
    // int x -> current node of the tree.
    int query(int l, int r, int k, int x, int lx, int rx)
    {
        if (rx <= l || r <= lx)
            return 0;

        if (l <= lx && r >= rx)
        {
            auto it = upper_bound(tree[x].val.begin(), tree[x].val.end(), k) - tree[x].val.begin();
            return ((int)tree[x].val.size() - it);
        }

        int mid = (lx + rx) / 2;
        int left = query(l, r, k, 2 * x + 1, lx, mid);
        int right = query(l, r, k, 2 * x + 2, mid, rx);
        return left + right;
    }

    int query(int l, int r, int k)
    {
        return query(l, r, k, 0, 0, size);
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
        cin >> x;

    SegTree st;
    st.init(n);
    st.build(a);

    int q;
    cin >> q;

    while (q--)
    {
        int i, j, k;
        cin >> i >> j >> k;
        i--;

        int ans = st.query(i, j, k);
        cout << ans << "\n";
    }

    return 0;
}