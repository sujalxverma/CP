#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto start = high_resolution_clock::now();

  int t;
  cin >> t;
  vector<__int128> f(101, 1);
  for (__int128 i = 2; i <= 101; i++) {
    f[i] = f[i - 1] * i;
  }

  while (t--) {
    __int128 n;
    cin >> n;
    cout << f[n] << "\n";
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << "Time taken: " << duration.count() << " microseconds\n";

  return 0;
}