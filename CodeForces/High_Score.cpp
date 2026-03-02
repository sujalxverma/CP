#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

using ll = long long;
const ll inf = -(1LL << 60);

vector<ll> bfs(vector<vector<ll>> &g, ll node) {
  ll n = g.size();
  vector<ll> ans(n, 0);
  queue<ll> q;
  q.push(node);
  vector<ll> v(n, 0);
  v[node] = 1;
  ans[node] = 1;
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (auto &k : g[u]) {
      if (v[k] == 0) {
        ans[k] = 1;
        v[k] = 1;
        q.push(k);
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto start = high_resolution_clock::now();

  ll n, m;
  cin >> n >> m;
  vector<tuple<ll, ll, ll>> edges;
  vector<vector<ll>> graph(n + 1);
  vector<vector<ll>> revgraph(n + 1);

  for (ll i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
    graph[u].push_back(v);
    revgraph[v].push_back(u);
  }

  //   sort(edges.begin(), edges.end());
  vector<ll> d(n + 1, inf);
  d[1] = 0;
  for (ll j = 1; j <= n - 1; j++) {
    bool update = false;

    for (auto &[u, v, w] : edges) {

      if (d[u] != inf && d[u] + w > d[v]) {
        d[v] = d[u] + w;
        update = true;
      }
    }
    if (!update) {
      break;
    }
  }

  vector<ll> cycle(n + 1, 0);
  for (auto &[u, v, w] : edges) {

    if (d[u] != inf && d[u] + w > d[v]) {
      cycle[v] = 1;
    }
  }

  vector<ll> source = bfs(graph, 1);
  vector<ll> target = bfs(revgraph, n);

  for (ll i = 1; i <= n; i++) {
    if (cycle[i] && source[i] && target[i]) {
      cout << "-1\n";
      return 0;
    }
  }

  cout << d[n] << "\n";

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << "Time taken: " << duration.count() << " microseconds\n";

  return 0;
}