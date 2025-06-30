
// uses PQ.
void dijkstra(vector<vector<pair<int, int>>> &graph, int source)
{
    vector<int> distance(graph.size(), INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    distance[source] = 0;

    vector<int> prev(graph.size(), -1);

    while (!pq.empty())
    {
        auto values = pq.top();
        pq.pop();
        int node = values.second;
        int steps = values.first;

        if (steps > distance[node])
            continue; // This ensures you only process a node if you're visiting it with the currently shortest known distance.

        for (auto val : graph[node])
        {
            int neighbor = val.first;
            int dist = val.second;
            if (distance[neighbor] > dist + distance[node])
            {
                distance[neighbor] = dist + distance[node];
                prev[neighbor] = node;
                pq.push({distance[neighbor], neighbor});
            }
        }
    }
}
/*
      1. If any node is not reachable from source, then its distance value is INT_MAX.
      2. prev , at every index it stores from which node it came from with short distance, for source, it is -1.
      3. Exactly! If you stop as soon as you pop the target node from the priority queue in Dijkstra's algorithm,
         you are guaranteed to have found the shortest distance to that target.
         There is no possibility that a shorter path will be discovered afterward.
      4. We can use set instead of PQ, b/c in set we can remove outdated pair if we got a shorter distance for the node.
         We cannot remove outdated pair in PQ.
  */


// uses Set instead of PQ.
void dijkstra(const vector<vector<pair<int, int>>> &graph, int source)
{
    int n = graph.size();
    vector<int> distances(n, INT_MAX);
    vector<int> predecessors(n, -1);

    // Set stores pairs of (distance, node), sorted by distance.
    set<pair<int, int>> active_nodes;

    distances[source] = 0;
    active_nodes.insert({0, source});

    while (!active_nodes.empty())
    {
        auto [current_distance, current_node] = *active_nodes.begin();
        active_nodes.erase(active_nodes.begin());

        // If this distance is not up to date, skip
        if (current_distance > distances[current_node])
            continue;

        for (const auto &edge : graph[current_node])
        {
            int neighbor = edge.first;
            int weight = edge.second;

            int new_distance = current_distance + weight;
            if (new_distance < distances[neighbor])
            {
                // Remove the old distance entry if it exists
                if (distances[neighbor] != INT_MAX)
                {
                    active_nodes.erase({distances[neighbor], neighbor});
                }
                distances[neighbor] = new_distance;
                predecessors[neighbor] = current_node;
                active_nodes.insert({new_distance, neighbor});
            }
        }
    }

    // distances[] now contains shortest distances from source
    // predecessors[] can be used to reconstruct paths
}
