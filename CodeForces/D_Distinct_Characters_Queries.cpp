#include "bits/stdc++.h"
using namespace std;

/*
Only occurence matters, so we use bitmasking.
*/

struct Node
{
   int mask;

    Node(int mask)
    {
        this->mask = mask;
    }
};

struct SegTree
{
    int size;
    vector<Node> tree;
    Node NEUTRAL = Node(0); // empty set

    Node merge(const Node &a, const Node &b)
    {
        int mask = (a.mask | b.mask);

        return Node(mask);
    }

    void init(int n)
    {
        size = 1;
        while (size < n)
            size <<= 1;
        tree.assign(2 * size, NEUTRAL);
    }

    void build(string &arr, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)arr.size())
            {
               
                tree[x] = Node(1<<(arr[lx]-'a')); // FIXED
            }

            return;
        }

        int mid = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, mid);
        build(arr, 2 * x + 2, mid, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(string &arr)
    {
        build(arr, 0, 0, size);
    }

    // point update
    void set(int i, char v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {

           tree[x] = Node(1<<(v-'a'));

            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid)
            set(i, v, 2 * x + 1, lx, mid);
        else
            set(i, v, 2 * x + 2, mid, rx);

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, char v)
    {
        set(i, v, 0, 0, size);
    }

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

    string s;
    cin >> s;

    SegTree st;
    st.init((int)s.size());
    st.build(s);

    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int pos;
            char c;
            cin >> pos >> c;
            --pos; // assuming 1-based input
            st.set(pos, c);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            --l; // assuming 1-based input
            Node ans = st.query(l, r);
            cout<<__builtin_popcount(ans.mask)<<"\n";
        }
    }

    return 0;
}
