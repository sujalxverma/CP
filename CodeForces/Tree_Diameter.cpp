#include "bits/stdc++.h"
using namespace std;

// 0 based.
int treeDiameter(const vector<vector<int>>& g) {
    int n = g.size();

    // local DFS lambda: finds farthest node and distance from a start
    auto dfs = [&](int start) {
        vector<int> dist(n, -1);
        stack<int> st;
        st.push(start);
        dist[start] = 0;

        int farthestNode = start;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            for (int v : g[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    st.push(v);
                    if (dist[v] > dist[farthestNode]) {
                        farthestNode = v;
                    }
                }
            }
        }
        return pair<int,int>{farthestNode, dist[farthestNode]};
    };

    // 1st DFS from arbitrary node (0)
    int v = dfs(0).first;

    // 2nd DFS from v gives the diameter
    int diameter = dfs(v).second;

    return diameter; // number of edges
}


// 2 DFS diameter algo requires undirected tree.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>>g(n); // 1 based

    for(int i = 0; i < n-1 ; i++){
        int a,b;
        cin >> a >> b;
        --a; --b;
g[a].push_back(b);
g[b].push_back(a);

    }

    int dia = treeDiameter(g);

    cout<<dia<<"\n";

    return 0;
}