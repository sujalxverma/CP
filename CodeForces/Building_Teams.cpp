#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> color(n + 1, -1); // -1 = unvisited, 0/1 = teams
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : g[u]) {
                    if (color[v] == -1) {
                        color[v] = !color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (color[i] + 1) << " ";
    }
    cout << "\n";

    return 0;
}
