#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto start = high_resolution_clock::now();

  while (true) {
    int n;
    cin >> n;
    if (n == 0)
      break;

    string s;
    cin >> s;

    vector<vector<char>> v(10000, vector<char>(n, '.'));
    // cout << s.length() << "\n";
    int dir = 0;
    int row = 0;
    for (int i = 0; i < (int)s.length(); i++) {

      if (dir == 0) {
        v[row][i % n] = s[i];
      } else {
        v[row][n - 1 - (i % n)] = s[i];
      }

      // Row finishes every n characters — regardless of direction
      if (i % n == n - 1) {
        dir = !dir;
        row++;
      }
    }
    //   v[row][i % n] = s[i];
    //   if ((i % n) == n - 1) {
    //     row++;
    //   }
    string ans = "";
    dir = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 10000; j++) {
        if (v[j][i] == '.')
          continue;
        ans += v[j][i];
      }
    }
    cout << ans << "\n";
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  //   cerr << "Time taken: " << duration.count() << " microseconds\n";

  return 0;
}