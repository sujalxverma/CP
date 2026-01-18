// in terms of edges.
// height of a tree
int height(const vector<vector<int>> &g, int node)
{
    int maxheight = 0;

    for (int v : g[node])
    {
        maxheight = max(maxheight, height(g, v));
    }

    return maxheight + (g[node].empty() ? 0 : 1);
}

/*
========================  TREE DIAMETER : TWO-DFS LOGIC  ========================

ASSUMPTIONS
-----------
1) The graph is a TREE:
   - Connected
   - Acyclic
   - Undirected (or directed but treated as undirected for diameter)

2) Distance is measured as the number of EDGES between nodes.

3) Because it is a tree, there exists EXACTLY ONE simple path between any
   two nodes. This uniqueness is critical for correctness.

-------------------------------------------------------------------------------

ALGORITHM
---------
Step 1:
    Pick any arbitrary node u (e.g., node 0).

Step 2:
    Run DFS/BFS from u and compute distances to all nodes.
    Let v be the node with maximum distance from u.

Step 3:
    Run DFS/BFS again, this time starting from v.
    Let g be the node with maximum distance from v.

Step 4:
    The path length dist(v, g) is the DIAMETER of the tree.
    The path v → g itself is a diameter path.

-------------------------------------------------------------------------------

WHY THIS WORKS (CORE LOGIC)
--------------------------

KEY LEMMA:
    For any node u in a tree, at least one endpoint of the tree's diameter
    is farthest from u.

Explanation:
    Let (a, b) be the diameter of the tree (longest path).
    Consider any arbitrary node u.

    Because paths in a tree are unique, the path from u to the diameter
    intersects the diameter at exactly one node x.

        a ----------- x ----------- b
                        |
                        u

    Distances:
        dist(u, a) = dist(u, x) + dist(x, a)
        dist(u, b) = dist(u, x) + dist(x, b)

    Since (a, b) is the longest path in the tree, either:
        dist(x, a) >= dist(x, b)
        OR
        dist(x, b) > dist(x, a)

    Therefore, one of the diameter endpoints (a or b) is always the
    farthest node from u.

    This guarantees that the node v found in Step 2 is an endpoint of
    some diameter.

-------------------------------------------------------------------------------

WHY THE SECOND DFS GIVES THE DIAMETER
------------------------------------

- After Step 2, v is guaranteed to be a diameter endpoint.
- The farthest node from a diameter endpoint must be the opposite endpoint.
- If a longer path existed, v would not be an endpoint of a diameter,
  contradicting the lemma.

Hence:
    dist(v, g) = diameter of the tree.

-------------------------------------------------------------------------------

IMPORTANT NOTES
---------------
- This method works ONLY for trees.
- It does NOT work for graphs with cycles.
- Time complexity: O(N)
- Space complexity: O(N)
- This is optimal.

-------------------------------------------------------------------------------

INTUITION
---------
- First DFS finds an "extreme" of the tree.
- Second DFS finds the opposite extreme.
- The distance between two extremes is the diameter.

===============================================================================
*/

int treeDiameter(const vector<vector<int>> &g)
{
    int n = g.size();

    // local DFS lambda: finds farthest node and distance from a start
    auto dfs = [&](int start)
    {
        vector<int> dist(n, -1);
        stack<int> st;
        st.push(start);
        dist[start] = 0;

        int farthestNode = start;

        while (!st.empty())
        {
            int u = st.top();
            st.pop();

            for (int v : g[u])
            {
                if (dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    st.push(v);
                    if (dist[v] > dist[farthestNode])
                    {
                        farthestNode = v;
                    }
                }
            }
        }
        return pair<int, int>{farthestNode, dist[farthestNode]};
    };

    // 1st DFS from arbitrary node (0)
    int v = dfs(0).first;

    // 2nd DFS from v gives the diameter
    int diameter = dfs(v).second;

    return diameter; // number of edges
}

/*
SEGMENT TREE
0-BASED INDEXING.

Possible results of query,
    1. Exactly matches / completely inside the range.
    2. Partial overlap.
    3. Neither overlap nor matches.


| Symbol     | Meaning                                             |
| ---------- | --------------------------------------------------- |
| [l, r)   | **Query range** (what the user asked for)           |
| [lx, rx) | **Node range** (what this node covers)              |
| x        | Index of the current node in the segment tree array |

*/
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
    int real_size;
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

    // build from array
    void build(vector<int> &arr, int x, int lx, int rx)
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

    void build(vector<int> &arr)
    {
        build(arr, 0, 0, size);
    }

    // point update: set position i to value v
    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = Node(v);
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

// Iterative Segment Tree.
/* ===== CHANGE THIS NODE AS PER PROBLEM ===== */
struct Node
{
    int val;

    Node(int v = 0) : val(v) {}
};

/* ===== SEGMENT TREE ===== */
struct SegTree
{
    int size;
    vector<Node> tree;

    // Neutral element (identity for merge)
    Node NEUTRAL = Node(0);

    // Merge function
    Node merge(const Node &a, const Node &b)
    {
        return Node(max(a.val, b.val)); // example: max segment tree
    }

    // Initialize with n elements
    void init(int n)
    {
        size = 1;
        while (size < n)
            size <<= 1;
        tree.assign(2 * size, NEUTRAL);
    }

    // Build from array (0-based)
    void build(const vector<int> &a)
    {
        for (int i = 0; i < (int)a.size(); i++)
        {
            tree[size + i] = Node(a[i]);
        }
        for (int i = size - 1; i >= 1; i--)
        {
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
        }
    }

    // Point update: a[pos] = val (0-based)
    void set_val(int pos, int val)
    {
        int idx = size + pos;
        tree[idx] = Node(val);
        idx >>= 1;
        while (idx >= 1)
        {
            tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
            idx >>= 1;
        }
    }

    // Range query on [l, r) (0-based, half-open)
    // range query [l, r), to include r => [l,r+1)
    Node query(int l, int r)
    {
        Node left_res = NEUTRAL;
        Node right_res = NEUTRAL;

        l += size;
        r += size;

        while (l < r)
        {
            if (l & 1)
            {
                left_res = merge(left_res, tree[l]);
                l++;
            }
            if (r & 1)
            {
                r--;
                right_res = merge(tree[r], right_res);
            }
            l >>= 1;
            r >>= 1;
        }
        return merge(left_res, right_res);
    }
};

// Lazy Propogation Segment Tree.
// sum query for range and updatation.
struct SegTree
{
    int n;
    vector<long long> tree, lazy;

    SegTree(int n)
    {
        this->n = n;
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    // Build from initial array
    void build(int node, int start, int end, const vector<long long> &a)
    {
        if (start == end)
        {
            tree[node] = a[start];
            return;
        }

        int mid = (start + end) / 2;
        build(node * 2, start, mid, a);
        build(node * 2 + 1, mid + 1, end, a);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void push(int node, int start, int end)
    {
        if (lazy[node] != 0)
        {
            tree[node] += (end - start + 1) * lazy[node];

            if (start != end)
            { // have children
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }

            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, long long val)
    {
        push(node, start, end);

        if (r < start || end < l)
            return;

        if (l <= start && end <= r)
        {
            lazy[node] += val;
            push(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        update(node * 2, start, mid, l, r, val);
        update(node * 2 + 1, mid + 1, end, l, r, val);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    long long query(int node, int start, int end, int l, int r)
    {
        push(node, start, end);

        if (r < start || end < l)
            return 0;

        if (l <= start && end <= r)
            return tree[node];

        int mid = (start + end) / 2;
        return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
    }
};

// Sparse Table
// Min-sparse-table

#include <bits/stdc++.h>
using namespace std;

/*
  Sparse Table for Range Minimum Query (RMQ)

  Preprocessing: O(n log n)
  Query time:    O(1)
  Space:         O(n log n)

  Works only for static arrays.
*/

struct SparseTable
{
    int n, LOG;
    vector<vector<int>> st; // st[k][i] = min on range [i, i + 2^k - 1]
    vector<int> log2val;    // precomputed floor(log2(i))

    SparseTable(const vector<int> &a)
    {
        n = (int)a.size();
        LOG = 32 - __builtin_clz(n);

        st.assign(LOG, vector<int>(n));
        log2val.assign(n + 1, 0);

        build_logs();
        build_table(a);
    }

    void build_logs()
    {
        for (int i = 2; i <= n; i++)
            log2val[i] = log2val[i / 2] + 1;
    }

    void build_table(const vector<int> &a)
    {
        // base layer (k = 0)
        for (int i = 0; i < n; i++)
            st[0][i] = a[i];

        // build higher layers
        for (int k = 1; k < LOG; k++)
        {
            for (int i = 0; i + (1 << k) <= n; i++)
            {
                st[k][i] = min(st[k - 1][i],
                               st[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    // Query minimum on range [l, r] (0-indexed, inclusive), may contain overlap.
    int query(int l, int r) const
    {
        int len = r - l + 1;
        int k = log2val[len];
        return min(st[k][l],
                   st[k][r - (1 << k) + 1]);
    }               

    int query(int l, int r) const
    {
        int p = log2(r - l + 1);
        int ans = 1e9;
        int len = r - l + 1;
        // No overlap
        for (int i = p; i >= 0; i--)
        {
            if ((1 << i) <= len)
            {
                ans = min(ans, st[i][l]);
                len -= (1 << i);
                l += (1 << i);
            }
        }
        cout << ans << "\n";
    }

    // No overlap
};
