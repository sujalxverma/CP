
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



// converting binary tree to undirected graph
void convertToGraph(TreeNode *root, int k)
{
    if (!root) return;

    unordered_map<int, vector<int>> g;
    queue<pair<TreeNode *, int>> q;
    q.push({root, -1});
    // Build the undirected graph
    while (!q.empty())
    {
        auto val = q.front();
        q.pop();
        auto node = val.first;
        auto parent = val.second;

        if (parent != -1)
            g[node->data].push_back(parent);
        if (node->left)
        {
            g[node->data].push_back(node->left->data);
            q.push({node->left, node->data});
        }
        if (node->right)
        {
            g[node->data].push_back(node->right->data);
            q.push({node->right, node->data});
        }
    }
    // Print the graph
    for (auto &kv : g)
    {
        cout << kv.first << " : ";
        for (int neighbor : kv.second)
        {
            cout << neighbor << " ";
        }
        cout << "\n";
    }
}

// parents of a node in tree.
unordered_map<TreeNode *, TreeNode *> parentNodes(TreeNode *root)
{
    unordered_map<TreeNode *, TreeNode *> parent;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        if (node->left)
        {
            q.push(node->left);
            parent[node->left] = node;
        }
        if (node->right)
        {
            q.push(node->right);
            parent[node->right] = node;
        }
    }
    return parent;
}