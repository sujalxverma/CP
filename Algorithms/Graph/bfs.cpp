
/*
   1. accepts adjacency vector as parameter.
   2. stores the bfs order in a vector.
   3. can be adjust accordingly as per problem.
*/
void bfs(vector<vector<int>> &graph)
{
    vector<bool> visited(graph.size(), false);
    vector<int> bfsOrder;
    queue<int> checker;

    for (int start = 0; start < graph.size(); ++start)
    {
        if (!visited[start])
        {
            checker.push(start);
            visited[start] = true;
            bfsOrder.push_back(start);

            while (!checker.empty())
            {
                int node = checker.front();
                checker.pop();

                for (int neighbor : graph[node])
                {
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        checker.push(neighbor);
                        bfsOrder.push_back(neighbor);
                    }
                }
            }
        }
    }
}
