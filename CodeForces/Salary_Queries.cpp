#include "bits/stdc++.h"
using namespace std;

unordered_map<int, int> mp;
vector<int> arr;
vector<int> compressedValues;
struct Node
{
    int val; // change type as needed

    Node(int v)
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
                tree[x] = Node(0);
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
    void setValue(int i, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = Node(1 + tree[x].val);
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid)
            setValue(i, 2 * x + 1, lx, mid);
        else
            setValue(i, 2 * x + 2, mid, rx);

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void setValue(int i)
    {
        setValue(i, 0, 0, size);
    }

    // point update : remove value.
    void removeValue(int i, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = Node(tree[x].val - 1);
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid)
            removeValue(i, 2 * x + 1, lx, mid);
        else
            removeValue(i, 2 * x + 2, mid, rx);

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void removeValue(int i)
    {
        removeValue(i, 0, 0, size);
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
    vector<int> allValues;
    // vector<int>arr(n);
    // arr.resize(n);
    mp.reserve(allValues.size());
    mp.max_load_factor(0.7);

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        arr.push_back(k);
        allValues.push_back(k);
    }
    vector<tuple<char, int, int>> tp;
    while (q--)
    {

        char c;
        cin >> c;
        if (c == '?')
        {
            int a, b;
            cin >> a >> b;
            allValues.push_back(a);
            allValues.push_back(b);
            tp.push_back({c, a, b});
        }
        else
        {
            int a, b;
            cin >> a >> b;
            allValues.push_back(a);
            allValues.push_back(b);
            tp.push_back({c, a, b});
        }
    }

    sort(allValues.begin(), allValues.end());
    allValues.erase(unique(allValues.begin(), allValues.end()), allValues.end());

    // map<int,int>mp;
    compressedValues.resize(n);
    for (size_t i = 0; i < allValues.size(); ++i)

    {
        mp[allValues[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        compressedValues[i] = mp[arr[i]];
    }
    // for (auto x : compressedValues)
    // {
    //     cout << x << "\n";
    // }
    SegTree st;
    st.init(allValues.size());
    // st.build(allValues);

    for (int i = 0; i < n; i++)
    {
        st.setValue(compressedValues[i]);
    }

    for (auto x : tp)
    {
        auto [ch, a, b] = x;
        if (ch == '!')
        {
            int k = a - 1; // convert to 0-based
            int newSalary = b;

            st.removeValue(compressedValues[k]);
            compressedValues[k] = mp[newSalary];
            st.setValue(compressedValues[k]);
        }
        else
        {
            auto ans = st.query(mp[a], mp[b] + 1);
            cout << ans.val << "\n";

            // These lines are much faster.
            // int L = lower_bound(allValues.begin(), allValues.end(), a) - allValues.begin();
            // int R = upper_bound(allValues.begin(), allValues.end(), b) - allValues.begin();

            // auto ans = st.query(L, R);
            // cout << ans.val << "\n";
        }
    }

    return 0;
}