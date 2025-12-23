#include "bits/stdc++.h"
using namespace std;

/*
    Computes gcd using Euclidean algorithm.
    gcd(a, b) = gcd(b, a % b)
*/
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

/*
    Each segment tree node stores:
    1) gcdValue : gcd of the entire segment
    2) count    : how many elements in this segment
                  are exactly equal to gcdValue
*/
struct Node
{
    int gcdValue;
    int count;

    // Constructor
    Node(int g, int c)
    {
        gcdValue = g;
        count = c;
    }
};

/*
    Segment Tree to answer range queries:
    For a given range [l, r), we want:
      - gcd of the range
      - number of elements equal to that gcd
*/
struct SegTree
{
    int size;
    vector<Node> tree;

    /*
        Neutral element:
        gcd(0, x) = x
        count = 0 because no actual elements are represented
    */
    Node NEUTRAL = Node(0, 0);

    /*
        Merge two nodes a and b.

        Steps:
        1) Compute gcd of both segments.
        2) Decide how many elements in the merged segment
           are equal to this gcd.

        Important cases:
        - If both segments already have the same gcd,
          their counts add up.
        - If only one side has gcd equal to merged gcd,
          only that side contributes.
        - Otherwise, no element is equal to merged gcd.
    */
    Node merge(const Node &a, const Node &b)
    {
        int g = gcd(a.gcdValue, b.gcdValue);

        // Both segments fully match the merged gcd
        if (g == a.gcdValue && g == b.gcdValue)
        {
            return Node(g, a.count + b.count);
        }

        // Only left segment contributes
        if (g == a.gcdValue)
        {
            return Node(g, a.count);
        }

        // Only right segment contributes
        if (g == b.gcdValue)
        {
            return Node(g, b.count);
        }

        // No element equals the merged gcd
        return Node(g, 0);
    }

    /*
        Initialize segment tree size to power of two
        and fill with neutral nodes.
    */
    void init(int n)
    {
        size = 1;
        while (size < n)
            size <<= 1;
        tree.assign(2 * size, NEUTRAL);
    }

    /*
        Build segment tree recursively.
        Leaf node:
            - gcd = value at index
            - count = 1
    */
    void build(vector<int> &arr, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)arr.size())
                tree[x] = Node(arr[lx], 1);
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

    /*
        Range query on interval [l, r)

        Cases:
        1) No overlap → return NEUTRAL
        2) Fully inside → return stored node
        3) Partial overlap → merge left & right
    */
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

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Build segment tree
    SegTree st;
    st.init(n);
    st.build(a);

    int q;
    cin >> q;

    /*
        For each query [l, r]:
        - total elements = (r - l)
        - st.query(l, r).count = number of elements
          equal to gcd of the range

        Answer:
        elements NOT equal to gcd
    */
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;  // convert to 0-based

        cout << (r - l) - st.query(l, r).count << "\n";
    }

    return 0;
}
