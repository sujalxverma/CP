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
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> f(1e6 + 3, 0);
  int l = 0;
  int ans = 1e9;
  for (int r = 0; r < n; r++) {
    f[a[r]]++;
    if (f[a[r]] > 1) {
      ans = min(ans, r - l + 1);
      while (l < r) {
        f[a[l]]--;
        l++;
        if (f[a[l - 1]] == 1) {
          ans = min(r - l + 2, ans);
          break;
        }
      }
    }
  }

  cout << (ans == 1e9 ? -1 : ans) << "\n";
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << "Time taken: " << duration.count() << " microseconds\n";

  return 0;
}