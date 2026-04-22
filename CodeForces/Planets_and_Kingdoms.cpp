#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<vector<int>> g, rg;
/*
stack<int> nodes;
vector<int> vis;
vector<int> scc;
*/
int n, m;
vector<int> dic, low, inStack;
/*
KOSARAJU ALGORITHM THAT USES TWO DFS CALLS TO GET SCC OF EACH NODE.

void dfs1(int u) {
    vis[u] = 1;
    for (int &v : g[u]) {
        if (!vis[v]) {
            dfs1(v);
        }
    }

    nodes.push(u);
}

void dfs2(int u, int component) {
    vis[u] = 1;
    scc[u] = component;
    for (int &v : rg[u]) {
        if (!vis[v]) {
            dfs2(v, component);
        }
    }
}

void kosaraju() {
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs1(i);
        }
    }
    vis.assign(n + 1, 0);
    int counter = 1;
    while (!nodes.empty()) {
        int u = nodes.top();
        nodes.pop();
        if (vis[u] != 0) {
            continue;
        }
        dfs2(u, counter);
        counter++;
    }
}

*/

void dfs(int u, int time) {
    dic[u] = time;
    inStack[u] = 1;
    for (int &v : g[u]) {
        if ()
    }

    inStack[u] = 0;
}

void tarjan() {
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    g.resize(n + 1);
    rg.resize(n + 1);
    /*
    vis.assign(n + 1, 0);
    scc.assign(n + 1, -1);
    */
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    dic.resize(n + 1);
    low.resize(n + 1);
    inStack.assign(n + 1, 0);
    /*
    kosaraju();
    int k = 0;
    for (int i = 1; i <= n; i++) {
        k = max(k, scc[i]);
    }
    cout << k << "\n";
    for (int i = 1; i <= n; i++) {
        cout << scc[i] << " ";
    }
        */
}
