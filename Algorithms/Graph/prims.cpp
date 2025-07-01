

/*
    1. minSpanningTree(graph,max_node+1);
    2. Yes, Prim's algorithm with a priority queue is designed so that smaller weights overshadow larger ones,
       ensuring you always process the smallest available edge to an unvisited node first.
*/
void minSpanningTree(vector<vector<pair<int, int>>> &adj, int max_node)
{
    vector<bool> inMST(max_node, false);
    vector<int> key(max_node, INT_MAX); // Minimum weight to connect to MST
    vector<int> parent(max_node, -1);   // Store MST edges

    // Min-heap: {weight, node, parent}
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    // Start from node 0
    pq.push({0, 0, -1});
    key[0] = 0;

    while (!pq.empty())
    {
        auto [weight, u, par] = pq.top();
        pq.pop();

        if (inMST[u])
            continue;
        inMST[u] = true;
        parent[u] = par;

        for (auto [v, w] : adj[u])
        {
            if (!inMST[v] && w < key[v])
            {
                key[v] = w;
                pq.push({w, v, u});
            }
        }
    }
}
