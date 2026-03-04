#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

const long long inf = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto start = high_resolution_clock::now();

  long long n;
  cin >> n;
  //   vector<vector<long long>> path(n + 1, vector<long long>(n + 1));
  vector<vector<long long>> g(n + 1, vector<long long>(n + 1, inf));

  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      cin >> g[i][j];
    }
  }
  //   g = path;

  vector<long long> nodes(n); // vertex removals.
  for (long long i = 0; i < n; i++) {
    cin >> nodes[i];
  }
  vector<long long> active(n + 1, 0);
  vector<long long> ans(n + 1);
  for (long long i = n - 1; i >= 0; i--) {

    long long k = nodes[i];
    active[k] = 1;
    // for (long long j = 1; j <= n; j++) {
    //   g[j][k] = path[j][k];
    //   g[k][j] = path[k][j];
    // }   NO NEED, AS OUR FLOYD WARSHALL WILL ONLY CONSIDER ACTIVE NODE TO
    // UPDATE.

    long long sum = 0;

    for (long long i = 1; i <= n; i++) {
      if (g[i][k] == inf)
        continue;
      for (long long j = 1; j <= n; j++) {
        if (g[k][j] == inf)
          continue;
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }

    for (long long j = 1; j <= n; j++) {
      for (long long l = 1; l <= n; l++) {
        if (!active[j] || !active[l])
          continue;
        sum += g[j][l];
      }
    }

    ans[i + 1] = sum;
  }
  for (long long i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << "Time taken: " << duration.count() << " microseconds\n";

  return 0;
}