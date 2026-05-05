#include "bits/stdc++.h"
using namespace std;

int n, r1, r2;
vector<int> f(vector<vector<int>> &tree, int r) {
    vector<int> vis(n + 1, 0);
    queue<int> q;
    q.push(r);
    vector<int> ans(n + 1, 0);
    ans[r] = -1;
    while (!q.empty()) {
        int u = q.front();
        vis[u] = 1;
        q.pop();

        for (int v : tree[u]) {
            if (!vis[v]) {
                q.push(v);
                ans[v] = u;
            }
        }
    }
    return ans;
}

int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r1 >> r2;
    vector<vector<int>> tree(n + 1);
    vector<int> pr(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i != r1) {
            cin >> pr[i];
            tree[i].push_back(pr[i]);
            tree[pr[i]].push_back(i);
        }
    }

    vector<int> v = f(tree, r2);
    for (int i = 1; i <= n; i++) {
        if (i != r2) {
            cout << v[i] << " ";
        }
    }
    return 0;
}