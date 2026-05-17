#include "bits/stdc++.h"
using namespace std;
/*
Key observation:

For any fixed set of remaining bars, the function

    f(x) = Σ |x - ai|

is minimized at the median(s).

- If remaining count is odd:
      minimum occurs at one median.
- If remaining count is even:
      minimum occurs for every integer between
      the two middle elements.

The problem only asks whether there EXISTS some way
to remove at most k bars such that x becomes optimal.
We do NOT compare minimum sums across different removals.

So for every adjacent pair [a[i], a[i+1]], we check
whether they can become the middle pair after removing
at most k bars.

Let:
    left  = bars strictly before i
    right = bars strictly after i+1

To make a[i], a[i+1] the middle pair, the number of
remaining bars on both sides must be equal.
Thus we need to remove at least:

    abs(left - right)

bars from the larger side.

If this value <= k, then every integer in:

    [a[i], a[i+1]]

can be a minimizing house for some valid removal.

We take the union of all such intervals.
*/
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(begin(a), end(a));

    int l = 1e9;
    int u = -1e9;
    for (int i = 1; i <= n - 1; i++) {
        // want to check if [i , i+1] , segment can be consider as median.
        int left = i - 1;
        int right = n - i - 1;
        int diff = abs(left - right);
        if (k >= diff) {
            l = min(a[i], l);
            u = max(a[i + 1], u);
        } else {
            // do nothing
        }
    }
    cout << max(1, u - l + 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}