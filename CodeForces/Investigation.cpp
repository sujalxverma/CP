#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
const long long mod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto start = high_resolution_clock::now();

  long long n, m;
  cin >> n >> m;
  vector<vector<pair<long long, long long>>> g(n + 1);
  for (long long i = 0; i < m; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w}); // Directed Graph
  }

  // USE OF DIJKSTRA ALGORITHM.
  vector<long long> dist(n + 1, 1e18);
  vector<long long> ways(n + 1, 0);
  vector<long long> maxPath(n + 1, 0);
  vector<long long> minPath(n + 1, 0);
  dist[1] = 0;
  ways[1] = 1; // atleast there is 1 way possible.
  minPath[1] = 0;
  maxPath[1] = 0;

  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      pq;
  pq.push({0, 1});

  while (!pq.empty()) {
    auto [d, node] = pq.top();
    pq.pop();
    /*
    auto &[d, node, cnt] = pq.top();
    pq.pop();
    Don't use this line, becuase after poping, the refrence also vanishes away.
    */
    if (dist[node] < d)
      continue;

    for (auto &[v, w] : g[node]) {
      if (dist[v] > d + w) {
        dist[v] = d + w;
        pq.push({dist[v], v});
        ways[v] = (ways[node] % mod);
        maxPath[v] = 1 + maxPath[node];
        minPath[v] = 1 + minPath[node];
      } else if (dist[v] == w + dist[node]) {
        // new path unlocked.
        ways[v] = (ways[v] % mod + ways[node] % mod) % mod;
        maxPath[v] = max(maxPath[v], 1 + maxPath[node]);
        minPath[v] = min(minPath[v], 1 + minPath[node]);
      }
    }
  }

  cout << dist[n] << " " << ways[n] << " " << minPath[n] << " " << maxPath[n]
       << "\n";

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << "Time taken: " << duration.count() << " microseconds\n";

  return 0;
}