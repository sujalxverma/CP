#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int open = 0;
    int close = 0;
    int matched = 0;
};

struct SegTree
{
    int size;
    vector<Node> tree;
    Node NEUTRAL;

    inline Node merge(const Node &a, const Node &b)
    {
        int newMatched = min(a.open, b.close);
        return {
            a.open + b.open - newMatched,
            a.close + b.close - newMatched,
            a.matched + b.matched + newMatched
        };
    }

    void init(int n)
    {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, NEUTRAL);
    }

    void build(const string &s, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)s.size())
            {
                if (s[lx] == '(') tree[x].open = 1;
                else tree[x].close = 1;
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(s, 2 * x + 1, lx, mid);
        build(s, 2 * x + 2, mid, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(const string &s)
    {
        build(s, 0, 0, size);
    }

    Node query(int l, int r, int x, int lx, int rx)
    {
        if (rx <= l || r <= lx) return NEUTRAL;
        if (l <= lx && rx <= r) return tree[x];

        int mid = (lx + rx) / 2;
        return merge(
            query(l, r, 2 * x + 1, lx, mid),
            query(l, r, 2 * x + 2, mid, rx)
        );
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

    int q;
    cin >> q;

    SegTree st;
    st.init(s.size());
    st.build(s);

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << st.query(l - 1, r).matched * 2 << "\n";
    }
}
