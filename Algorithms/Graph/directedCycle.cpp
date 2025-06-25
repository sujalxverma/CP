

/*
    1. Detects a cycle in a directed graph.
*/

void cycle(vector<vector<int>> &graph, vector<int> &visited, vector<int> &path, int node,int &cycles)
{
    visited[node] = 1;
    path[node] = 1;
    for (auto neighbor : graph[node])
    {
        if (visited[neighbor] == -1)
        {
            cycle(graph, visited, path, neighbor,cycles);
        }
        else{
            if(path[neighbor] == 1){
                cycles++;
            }
        }
    }
    path[node] = 0;
}

void directedCycle(vector<vector<int>> &graph)
{
    vector<int> visited(graph.size(), -1);
    vector<int> path(graph.size(), 0);
    int cycles = 0;
    // starting with first node.
    for (int i = 0; i < graph.size(); i++)
    {
        if (visited[i] == -1)
        {
            cycle(graph,visited,path,i,cycles);
        }
    }
}