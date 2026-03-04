#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto start = high_resolution_clock::now();

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] >= a[i + 1]) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << "Time taken: " << duration.count() << " microseconds\n";

  return 0;
}