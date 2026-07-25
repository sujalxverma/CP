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