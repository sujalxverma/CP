#include "bits/stdc++.h"
using namespace std;
const int inf = 1e9;
vector<int> a;
struct Node
{
    int first_0;
    int last_0;
    int best_0;
    int first_1;
    int last_1;
    int best_1;
    int count_1;
    int count_0;

    Node(int first_0, int last_0, int best_0, int count_0,
         int first_1, int last_1, int best_1, int count_1)

    {
        this->first_0 = first_0;
        this->last_0 = last_0;
        this->best_0 = best_0;
        this->count_0 = count_0;
        this->first_1 = first_1;
        this->last_1 = last_1;
        this->best_1 = best_1;
        this->count_1 = count_1;
    }
};

struct SegTree
{
    int size;
    int real_size;
    vector<Node> tree;
    Node NEUTRAL = Node(
        -1, -1, inf, 0, // 0s
        -1, -1, inf, 0  // 1s
    );
    // neutral element for merge

    // merge two nodes
    // can be modified.
    Node merge(const Node &a, const Node &b)
    {
        int count_0 = a.count_0 + b.count_0;
        int count_1 = a.count_1 + b.count_1;

        int first_0 = (a.first_0 != -1 ? a.first_0 : b.first_0);
        int last_0 = (b.last_0 != -1 ? b.last_0 : a.last_0);
        int first_1 = (a.first_1 != -1 ? a.first_1 : b.first_1);
        int last_1 = (b.last_1 != -1 ? b.last_1 : a.last_1);

        int best_0 = min(a.best_0, b.best_0);
        if (a.last_0 != -1 && b.first_0 != -1)
            best_0 = min(best_0, b.first_0 - a.last_0);

        int best_1 = min(a.best_1, b.best_1);
        if (a.last_1 != -1 && b.first_1 != -1)
            best_1 = min(best_1, b.first_1 - a.last_1);

        return Node(first_0, last_0, best_0, count_0,
                    first_1, last_1, best_1, count_1);
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

    // build from array
    void build(vector<int> &arr, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)arr.size())
                if (arr[lx] == 0)
                {
                    tree[x] = Node(
                        lx, lx, inf, 1, // 0s
                        -1, -1, inf, 0  // 1s
                    );
                }
                else
                {
                    tree[x] = Node(
                        -1, -1, inf, 0, // 0s
                        lx, lx, inf, 1  // 1s
                    );
                }

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
    // range query [l, r), to include r => [l,r+1)
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        a.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        SegTree st;
        st.init(n);
        st.build(a);
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            // 0 based indexing.
            Node ans = st.query(l, r + 1);
            if (ans.count_0 %3 != 0 || ans.count_1 % 3 != 0)
            {
                cout << "-1\n";
            }
            else 
            {
                cout << (ans.best_0) * ((ans.count_0 - 2)) + (ans.best_1) * ((ans.count_1 - 2)) << "\n";
            }
        }
    }

    return 0;
}