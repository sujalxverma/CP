
// create directed weighted graph.
vector<vector<pair<int, int>>> readDirectedWeightedGraph(int n) {
    vector<vector<pair<int, int>>> graph;

    // First, find max node index to size the graph
    int maxNode = 0;
    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        maxNode = max(maxNode, max(u, v));
    }

    // Resize graph to fit all nodes
    graph.resize(maxNode + 1);

    // Fill the graph
    for (auto [u, v, w] : edges) {
        graph[u].push_back({v, w});  // Directed edge from u to v
    }

    return graph;
}

// create directed graph, no weights.
vector<vector<int>> readDirectedGraph(int n) {
    vector<tuple<int, int>> edges;
    int maxNode = 0;

    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v; // edge from u → v
        edges.push_back({u, v});
        maxNode = max(maxNode, max(u, v));
    }

    vector<vector<int>> graph(maxNode + 1); // 0-based indexing (default)

    for (auto [u, v] : edges) {
        graph[u].push_back(v); // Directed edge
    }

    return graph;
}

// create weighted tree.
vector<vector<pair<int, int>>> build_tree(int n) {
    // Assuming nodes are 1-based and max node <= n+1 (or you can adjust)
    int max_node = n + 1;  
    vector<vector<pair<int,int>>> adj(max_node + 1);

    for (int i = 0; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected tree
    }
    return adj;
}