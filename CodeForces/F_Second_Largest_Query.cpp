#include "bits/stdc++.h"
using namespace std;
const int inf = -1e8;
struct Node
{
    pair<int, int> L;
    pair<int, int> S;

    Node(int L, int L_count, int S, int S_count)
    {
        this->L.first = L;
        this->L.second = L_count;
        this->S.first = S;
        this->S.second = S_count;
    }
};

struct SegTree
{
    int size;
    vector<Node> tree;
    Node NEUTRAL = Node({inf, 0, inf, 0}); // neutral element for merge

    // merge two nodes
    // can be modified.
    Node merge(const Node &a, const Node &b)
    {
        if (a.L.first > b.L.first)
        {
            if (a.S.first > b.L.first)
                return Node(a.L.first, a.L.second, a.S.first, a.S.second);
            else if (a.S.first < b.L.first)
                return Node(a.L.first, a.L.second, b.L.first, b.L.second);
            else
                return Node(a.L.first, a.L.second, b.L.first, a.S.second + b.L.second);
        }
        else if (a.L.first < b.L.first)
        {
            if (b.S.first > a.L.first)
                return Node(b.L.first, b.L.second, b.S.first, b.S.second);
            else if (b.S.first < a.L.first)
                return Node(b.L.first, b.L.second, a.L.first, a.L.second);
            else
                return Node(b.L.first, b.L.second, a.L.first, b.S.second + a.L.second);
        }
        else // a.L.first == b.L.first
        {
            if (a.S.first > b.S.first)
                return Node(a.L.first, a.L.second + b.L.second, a.S.first, a.S.second);
            else if (a.S.first < b.S.first)
                return Node(a.L.first, a.L.second + b.L.second, b.S.first, b.S.second);
            else
                return Node(a.L.first, a.L.second + b.L.second, a.S.first, a.S.second + b.S.second);
        }
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
                tree[x] = Node({arr[lx], 1, inf, 0});
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
            tree[x] = Node({v, 1, inf, 0});
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
    for (auto &x : a)
    {
        cin >> x;
    }

    SegTree st;
    st.init(n);
    st.build(a);

    while (q--)
    {
        int k;
        cin >> k;
        if (k == 1)
        {
            int i, v;
            cin >> i >> v;
            i--; // 0 based indexing
            st.set(i, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--; // 0 based indexing, query -> [l,r]

            Node ans = st.query(l, r);
            cout << ans.S.second << "\n";
        }
    }

    return 0;
}