#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

void solve() {

  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> close(n, 0);
  close[n - 1] = (s[n - 1] == ')' ? 1 : 0);
  for (int i = n - 2; i >= 0; i--) {
    close[i] += close[i + 1] + (s[i] == ')' ? 1 : 0);
  }

  vector<int> open(n, 0);
  int value = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == ')') {
      open[i] = value;
    } else {
      open[i] = i;
      value = i;
    }
  }
  vector<int> prefix(n, 0);
  prefix[0] = (s[0] == '(' ? 1 : -1);
  for (int i = 1; i < n; i++) {
    prefix[i] = prefix[i - 1] + (s[i] == '(' ? 1 : -1);
  }

  int ans = -1;

  for (int i = 1; i < n; i++) {
    if (s[i] == ')') {
      int swaps = prefix[i - 1];
      int idx = open[i];
      if (idx == -1) {
        continue; // no further opening bracket present.
      } else {
        swaps++;
        if (close[idx] >= swaps) {
          ans = max(ans, n - 2 * (idx - i));
          /*
             ans = max(ans, 2 * swaps + 2 * (close[idx] - swaps));

             This expression is incorrect because it tries to compute
             the answer using prefix balance and suffix counts, but the correct
             invariant depends only on the gap (idx - i).

             When we replace s[i] = ')' with the next '(' at position
             idx, we are forced to skip exactly (idx - i) closing brackets. To
             keep the total balance zero, we must also delete exactly (idx - i)
             opening brackets after idx. yes that is fact.

             Therefore, the resulting RBS length is:

                          n - 2 * (idx - i)

             Using 2 * swaps + 2 * (close[idx] - swaps) mixes prefix
             balance with suffix counts, which does not correctly model the
             number of characters actually removed.
          */
        }
      }
    }
  }

  cout << ans << "\n";
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