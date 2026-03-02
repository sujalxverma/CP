#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
vector<int> v;

void dfs(int node, vector<vector<int>> &g) {
  v[node] = 1;
  for (auto &u : g[node]) {
    if (v[u] == 0) {
      dfs(u, g);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto start = high_resolution_clock::now();

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (m != n - 1) {
    cout << "NO\n";
    return 0;
  }

  v.assign(n + 1, 0);
  int cnt = 0;

  for (int i = 1; i <= n; i++) {
    if (v[i] == 0) {
      cnt++;
      dfs(i, g);
    }
  }

  if (cnt == 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << "Time taken: " << duration.count() << " microseconds\n";

  return 0;
}