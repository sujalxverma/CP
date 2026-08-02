/*
* Binary Lifting is used to find the kth ancestor of node V, in logarithmic time.
* How it does that, every num can be expressed in this way :
        13 = 8 + 4 + 1 -> (1<<3) + (1<<2) + (1<<0).
* So we can split the k jumps into power of twos summation.
* So we use Sparse Table for pre calculation. -> up[][]
* First run DFS(u,p), to find up[u][0] = p, immediate parent, 1 jump.
* Now we have to greedily construct the sparse table.
* The contruction of ST is col major, col loop ,then row loop, ykiyk.
* Relation : up[v][i] = up[up[v][i-1]][i-1], Why ?
* To jump 2^j steps from v:
* 1. First jump 2^(j-1) steps (landing at up[v][j-1]).
* 2. Then jump another 2^(j-1) steps from there.
*
* Since 2^(j-1) + 2^(j-1) = 2^j, you have jumped the right distance.
* This is the same idea as repeated squaring in fast exponentiation:
* break the big jump into two equal halves.
* And check KthAncestor func, to get result. Reason -> Do it bro, understand yourself.
*/

int n, q;
vector<vector<int>> g;
vector<vector<int>> up; // sparse table

// dfs call to fill up[node][0] = parent(node);
void dfs(int u, int p)
{
    up[u][0] = p;
    for (int &v : g[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
    }
}

int kthAncestor(int v, int k)
{
    for (int i = floor(log2(n)); i >= 0; i--)
    {
        if ((1 << i) & k)
        { // or if(k >= (1<<i))
            v = up[v][i];
            // k = k - (1 << i); when if(k >= (1<<i)) used.
            if (v == -1)
            {
                return -1;
            }
        }
    }
    return v;
}
/*
 * Finding LCA of two nodes.
 * But first make both nodes at same level, its possible that node u is at depth 3 and
 * node 2 is at depth 6, so first jump node to depth 3.
 */
int LCA(int u, int v)
{
    if (u == v)
        return u;
    for (int i = floor(log2(n)); i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return (up[u][0] == -1 ? 1 : up[u][0]);
}

int main()
{
    up.assign(n + 1, vector<int>(floor(log2(n)) + 2, -1));
    dfs(1, -1);
    for (int col = 1; col < floor(log2(n)) + 1; col++)
    {
        for (int row = 1; row <= n; row++)
        {
            if (up[row][col - 1] == -1)
            {
                up[row][col] = -1;
            }
            else
            {
                up[row][col] = up[up[row][col - 1]][col - 1];
            }
        }
    }
}