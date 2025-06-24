
/*
    1. Counts the number of cycles in Undirected Graph.
    2. Count only one cycle per component.
*/

bool cyclicGraph(const vector<vector<int>> &graph, int start, vector<int> &visited)
{
    queue<pair<int, int>> checker; // {parent, current}
    visited[start] = 1;
    checker.push({-1, start});

    while (!checker.empty())
    {
        auto [parent, current] = checker.front();
        checker.pop();

        for (const auto &neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = 1;
                checker.push({current, neighbor});
            }
            else if (neighbor != parent)
            {
                return true; // A cycle is found
            }
        }
    }

    return false;
}

void undirectedCyclic(const vector<vector<int>> &graph)
{
    vector<int> visited(graph.size(), 0);
    int count = 0;

    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited[i])
        {
            if (cyclicGraph(graph, i, visited))
            {
                count++;
            }
        }
    }

    if (count > 0)
    {
        cout << "Number of components with cycles: " << count << endl;
    }
    else
    {
        cout << "There is no cycle" << endl;
    }
}