/*
 * Tarjan's Algo to find SCC in graph.
 * One DFS call only.
 * Also important fact that, Tarjan's component order is itself reverse order of
 * toposort, so we can simply reverse condensed graph, ans use DP on DAGs directly.
 */

const int inf = 1e9;
int n, m;
vector<vector<int>> g; // graph
vector<int> coins;     // some value
vector<int> scc;       // SCC
vector<int> low, disc; // low[u] = inf , disc[u] = inf
vector<int> onstack;
stack<int> st;
int timer = 0;
int comp = 1;
void tarjan(int u)
{
    low[u] = disc[u] = timer;
    timer = timer + 1;
    st.push(u);
    onstack[u] = 1;
    for (int &v : g[u])
    {
        if (disc[v] == inf)
        {
            tarjan(v);
            low[u] = min(low[u], low[v]); // we want best low answer from child.
        }
        else if (onstack[v])
        {
            low[u] = min(low[u], disc[v]); // but if child already visited, means we found back edge, so we compare
                                           // low[u] with disc[v].
        }
    }
    if (low[u] == disc[u])
    {
        while (!st.empty() && st.top() != u)
        {
            scc[st.top()] = comp;
            onstack[st.top()] = 0;
            st.pop();
        }
        scc[u] = comp;
        comp = comp + 1;
        onstack[u] = false;
        st.pop();
    }
}