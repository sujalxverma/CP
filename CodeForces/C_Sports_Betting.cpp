#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve() {
  int n;
  cin >> n;
  map<int, int> mp;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
    mp[x]++;
  }

  if (n == 1) {
    no;
    return;
  }

  for (auto &[x, y] : mp) {
    if (y >= 4) {
      yes;
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto start = high_resolution_clock::now();

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << "Time taken: " << duration.count() << " microseconds\n";

  return 0;
}