

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

// use of Toposort to detect cycle
bool dfsDetectCycle(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recStack, int node) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfsDetectCycle(graph, visited, recStack, neighbor)) {
                return true;
            }
        } else if (recStack[neighbor]) {
            // Back edge found
            return true;
        }
    }

    recStack[node] = false; // remove the node from recursion stack
    return false;
}

bool hasCycle(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false); // keeps track of nodes in the current DFS path

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfsDetectCycle(graph, visited, recStack, i)) {
                return true;
            }
        }
    }

    return false;
}