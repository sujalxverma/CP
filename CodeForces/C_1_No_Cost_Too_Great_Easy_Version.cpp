#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
const int MAXN = 300005;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto start = high_resolution_clock::now();

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int o = 0;
    int e = 0;

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 0) {
        e++;
      } else {
        o++;
      }
    }

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
    }
    // all b[i] = 1, no need to take input.
    if (e >= 2) {
      cout << "0\n";
      continue;
    }
    vector<int> f(MAXN, 0);
    for (int i = 0; i < n; i++) {
      if (a[i] == 1)
        continue;
      for (int j = 2; j <= a[i]; j++) {
        if (a[i] % j == 0) {
          f[j]++;
          while (a[i] % j == 0) {
            a[i] = a[i] / j;
          }
        }
      }
    }

    int cnt = 0;
    for (int i = 1; i < MAXN; i++) {
      cnt = max(cnt, f[i]);
    }

    if (e == 1) {
      if (cnt >= 2) {
        cout << "0\n";
      } else {
        cout << "1\n";
      }
      continue;
    }
    if (e == 0) {
      if (cnt >= 2) {
        cout << "0\n";
      } else {
        cout << "2\n";
      }
      continue;
    }
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << "Time taken: " << duration.count() << " microseconds\n";

  return 0;
}