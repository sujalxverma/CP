#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct Node
{
    ll val; // stores AND value of the segment
    Node(ll v = 0)
    {
        val = v;
    }
};

struct SegTree
{
    int size;
    vector<Node> tree;

    // Correct neutral element for AND (all bits set)
    Node NEUTRAL = Node((1LL << 31) - 1);

    Node merge(const Node &a, const Node &b)
    {
        return Node(a.val & b.val);
    }

    void init(int n)
    {
        size = 1;
        while (size < n)
            size <<= 1;
        tree.assign(2 * size, NEUTRAL);
    }

    void build(vector<ll> &arr, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)arr.size())
                tree[x] = Node(arr[lx]);
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

    ll n, k;
    cin >> n >> k;

    vector<vector<ll>> p(31, vector<ll>(n + 1, 0));
    vector<tuple<ll, ll, ll>> tp;

    while (k--)
    {
        ll l, r, q;
        cin >> l >> r >> q;
        l--;
        r--;
        tp.push_back({l, r, q});

        for (int i = 0; i < 31; i++)
        {
            if ((1LL << i) & q)
            {
                p[i][l]++;
                p[i][r + 1]--;
            }
        }
    }

    for (int i = 0; i < 31; i++)
    {
        for (int j = 1; j < n; j++)
        {
            p[i][j] += p[i][j - 1];
        }
    }

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        ll num = 0;
        for (int j = 0; j < 31; j++)
        {
            if (p[j][i] > 0)
                num |= (1LL << j);
        }
        a[i] = num;
    }

    SegTree st;
    st.init(n);
    st.build(a);

    for (auto &[l, r, q] : tp)
    {
        // IMPORTANT: query [l, r+1)
        if (st.query(l, r + 1).val != q)
        {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for (auto &x : a)
        cout << x << " ";
    cout << "\n";

    return 0;
}
