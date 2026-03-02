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
    string s;
    cin >> s;
    vector<int> a(10);

    for (int i = 0; i < 10; i++) {
      a[s[i] - '0']++;
    }
    vector<int> ans(10, -1);
    for (int i = 0; i < 10; i++) {
      if (a[9 - i] >= 1) {
        ans[i] = 9 - i;
        a[9 - i]--;
      }
    }

    vector<int> f;
    for (int i = 0; i < 10; i++) {
      while (a[i] > 0) {
        f.push_back(i);
        a[i]--;
      }
    }

    for (int i = 0; i < 10; i++) {
      if (ans[i] == -1) {
        auto idx = lower_bound(begin(f), end(f), 9 - i) - begin(f);
        ans[i] = f[idx];
        f[idx] = -1;
        sort(begin(f), end(f));
      }
    }
    for (int i = 0; i < 10; i++) {
      cout << ans[i];
    }
    cout << "\n";
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  //   cerr << "Time taken: " << duration.count() << " microseconds\n";

  return 0;
}