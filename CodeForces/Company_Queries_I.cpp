#include "bits/stdc++.h"
using namespace std;
int n, q;
vector<vector<int>> g;
vector<vector<int>> up; // sparse table

// dfs call to fill up[node][0] = parent(node);
void dfs(int u, int p) {
    up[u][0] = p;
    for (int &v : g[u]) {
        if (v == p)
            continue;
        dfs(v, u);
    }
}

int kthAncestor(int v, int k) {
    for (int i = floor(log2(n)); i >= 0; i--) {
        if ((1 << i) & k) { // or if(k >= (1<<i))
            v = up[v][i];
            // k = k - (1 << i); when if(k >= (1<<i)) used.
            if (v == -1) {
                return -1;
            }
        }
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    g.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    up.assign(n + 1, vector<int>(floor(log2(n)) + 2, -1));
    dfs(1, -1);
    for (int col = 1; col < floor(log2(n)) + 1; col++) {
        for (int row = 1; row <= n; row++) {
            if (up[row][col - 1] == -1) {
                up[row][col] = -1;
            } else {
                up[row][col] = up[up[row][col - 1]][col - 1];
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int node, k;
        cin >> node >> k;
        cout << kthAncestor(node, k) << "\n";
    }
    return 0;

    
}