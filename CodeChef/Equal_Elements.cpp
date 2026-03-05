#include "bits/stdc++.h"

#include <chrono>
#include <vector>

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
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    set<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {

      int s1 = (int)s.size();
      s.insert(a[i]);
      int s2 = (int)s.size();
      if (s1 == s2) {
        ans += 2;
        s.clear();
      }
    }
    cout << ans << "\n";
    /*
    int n;
    cin >> n;
    std::vector<int> a(n + 1), previdx(n + 1, 0), ans(n + 1, 0), freq(n + 1, 0);

    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    int maxi = 0;
    freq[a[1]] = 1;
    ans[1] = 0;
    previdx[a[1]] = 1;

    for (int i = 2; i <= n; i++) {
      freq[a[i]]++;
      if (freq[a[i]] == 1) {
        // discovered first time.
        ans[i] = maxi;
        previdx[a[i]] = i;
      } else if (freq[a[i]] % 2 == 1) {
        freq[a[i]] = 1;
        if (ans[previdx[a[i]]] < maxi) {
          ans[i] = maxi;
        } else {
          ans[i] = ans[previdx[a[i]]];
        }
        // ans[i] = max(ans[previdx[a[i]]], maxi);
        maxi = max(ans[i], maxi);
        // freq[a[i]]++;
        previdx[a[i]] = i;

      } else if (freq[a[i]] % 2 == 0) {
        // discovered first Time.
        // freq[a[i]]++;
        if (ans[previdx[a[i]]] + 1 < maxi) {
          ans[i] = maxi;
          freq[a[i]] = 1;
        } else {
          ans[i] = ans[previdx[a[i]]] + 1;
        }

        previdx[a[i]] = i;
        maxi = max(maxi, ans[i]);
      }
    }
    // for (int i = 1; i <= n; i++) {
    //   cout << ans[i] << " ";
    // }

    cout << 2 * maxi << "\n";
    */
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << "Time taken: " << duration.count() << " microseconds\n";

  return 0;
}