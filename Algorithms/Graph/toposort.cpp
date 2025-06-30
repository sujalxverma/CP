

// Toposort using stack and DFS.
void dfsTopoSort(vector<vector<int>> &graph, vector<bool> &visited, stack<int> &container, int start)
{
    visited[start] = true;
    for (auto node : graph[start])
    {
        if (!visited[node])
        {
            dfsTopoSort(graph, visited, container, node);
        }
    }
    container.push(start);
}

void toposort(vector<vector<int>> &graph)
{
    vector<bool> visited(graph.size(), false);
    vector<int> toposortOrder;
    stack<int> container;
    // works for multiple comonenets.
    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited[i])
        {
            dfsTopoSort(graph, visited, container, i);
        }
    }

    while (!container.empty())
    {
        toposortOrder.push_back(container.top());
        container.pop();
    }
}

// Kahn Algorithm

void kahnAlgo(vector<vector<int>> graph, vector<int> incoming_edges)
{
    // this code is for a single connected graph, if there are multiple
    // components, adjust accordingly.
    vector<int> edges = incoming_edges;
    queue<int> checker;
    vector<int> top_sort;
    for (int i = 0; i < edges.size(); i++)
    {
        if (edges[i] == 0)
        {
            checker.push(i);
            top_sort.push_back(i);
        }
    }

    while (!checker.empty())
    {
        auto node = checker.front();
        checker.pop();
        for (auto neighbour : graph[node])
        {
            edges[neighbour]--;
            if (edges[neighbour] == 0)
            {
                checker.push(neighbour);
                top_sort.push_back(neighbour);
            }
        }
    }
}

/*
    Now, if you want to find the existence of a cycle, you can use toposort (Kahn Algorithm), and if the size of order vector is
    less than the number of nodes, then there is a cycle.
*/