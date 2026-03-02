#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto start = high_resolution_clock::now();

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(begin(a), end(a));
    /*
    Bars can open b/w [n-k , n].
    */
    // if (k == n - 2) {
    //   cout << a[n - 1] - a[0] + 1 << "\n";
    //   continue;
    // }
    if (n % 2 == 1) {
      int i = n / 2;
      int j = n / 2;

      if (k % 2 == 1) {
        i--;
        j++;
        k--;
      }
      int cnt = a[j] - a[i] + 1;
      while (k > 0) {
        i--;
        k--;
        if (k > 0) {
          j++;
          cnt = max(cnt, a[j] - a[i] + 1);
          k--;
        }
      }

      cout << cnt << "\n";
      continue;

    } else {
      int i = n / 2;
      int j = n / 2 + 1;
      int cnt = a[j] - a[i] + 1;
      while (k > 0) {
        i--;
        k--;
        if (k > 0) {
          j++;
          cnt = max(cnt, a[j] - a[i] + 1);
          k--;
        }
      }
      cout << cnt << "\n";
      continue;
    }
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << "Time taken: " << duration.count() << " microseconds\n";

  return 0;
}