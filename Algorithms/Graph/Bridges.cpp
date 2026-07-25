/*
 * DFS method to find bridges in the undirected graph.
 * This only works when we have offline edges, means we know complete graph
 * at start.
 * TC : O(n + m)
 */
/*
Note that this implementation malfunctions if the graph has multiple edges,
since it ignores them. Of course, multiple edges will never be a part of
the answer, so IS_BRIDGE can check additionally that the reported bridge
is not a multiple edge. Alternatively it's possible to pass to dfs the index
of the edge used to enter the vertex instead of the parent vertex
(and store the indices of all vertices).
*/
void IS_BRIDGE(int v, int to); // some function to process the found bridge
int n;                         // number of nodes
vector<vector<int>> adj;       // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v])
    {
        if (to == p && !parent_skipped)
        {
            parent_skipped = true;
            continue;
        }
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

// solves problem for multi edge, will simply work.
void dfs2(int v, int parent_edge = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;

    for (auto [to, id] : adj[v])
    {
        // Ignore only the exact edge we came through.
        if (id == parent_edge)
            continue;

        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs2(to, id);

            low[v] = min(low[v], low[to]);

            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges()
{
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
}

/*
 * We can also contruct the compressed bridge graph.
 * During adjacency list of og graph, put a mark, if this edge is bridge or not.
 * Initially all edges are marked 0.
 * Then during our dfs call if we found a bridge, simply mark that bridge true.
 * Then we can simply construct bridge graph.
 */
