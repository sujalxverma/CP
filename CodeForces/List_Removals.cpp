#include "bits/stdc++.h"
using namespace std;
vector<int> a;
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
    void build(vector<int> &arr, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)arr.size())
                tree[x] = Node(1);
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
    void set(int offset, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = Node(0);
            return;
        }

        int mid = (lx + rx) / 2;
        if (offset <= tree[2 * x + 1].val)
        {

            set(offset, 2 * x + 1, lx, mid);
        }
        else
        {

            set(offset - tree[2 * x + 1].val, 2 * x + 2, mid, rx);
        }
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int offset)
    {
        set(offset, 0, 0, size);
    }

    // int x -> current node of the tree.
    int query(int offset, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            // tree[x] = Node(0);
            return a[lx];
        }

        int mid = (lx + rx) / 2;
        if (offset <= tree[2 * x + 1].val)
        {
            tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
            return query(offset, 2 * x + 1, lx, mid);
        }
        else
        {
            tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
            return query(offset - tree[2 * x + 1].val, 2 * x + 2, mid, rx);
        }
    }

    int query(int offset)
    {
        return query(offset, 0, 0, size);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> b(n);
    a.resize(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    for (auto &x : b)
    {
        cin >> x;
    }

    SegTree sg;
    sg.init(n);
    sg.build(a);

    for (auto &x : b)
    {
        cout << sg.query(x) << " ";
        sg.set(x);
    }

    return 0;
}