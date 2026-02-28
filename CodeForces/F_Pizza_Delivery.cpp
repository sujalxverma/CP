#include "bits/stdc++.h"
#include <chrono>
using namespace std::chrono;
using namespace std;
using ll = long long;

/*
Approach (Group DP on x-coordinates):

1) Since we cannot move left (x is non-decreasing),
   all delivery points must be processed in increasing order of x.

2) We compress all distinct x-coordinates (including start and end).
   For each x-group i:
       d[i].first  = maximum y in this group (high_i)
       d[i].second = minimum y in this group (low_i)

   All points in the group lie vertically between low_i and high_i.

3) Observation:
   When finishing deliveries in group i, the last delivered point
   must be either high_i or low_i.
   (Because to cover all vertical points, we must sweep the full segment.)

4) DP definition:
   dp[i].first  = minimum cost to process groups [0..i]
                  and finish at high_i
   dp[i].second = minimum cost to process groups [0..i]
                  and finish at low_i

   Base:
       dp[0].first = dp[0].second = 0

5) Transition:
   To finish at high_i:
       - First move from previous group (either high_{i-1} or low_{i-1})
         to low_i,
       - Then sweep vertically from low_i to high_i.

   To finish at low_i:
       - First move from previous group to high_i,
       - Then sweep vertically from high_i to low_i.

   Manhattan distance is used:
       dist(a,b) = |x_a - x_b| + |y_a - y_b|

   Since x_i > x_{i-1}, horizontal distance is:
       xcor[i] - xcor[i-1]

6) Therefore transitions are:

   Let:
       horizontal = xcor[i] - xcor[i-1]
       span       = |high_i - low_i|

   dp[i].first =
       horizontal
     + span
     + min(
         dp[i-1].first  + |high_{i-1} - low_i|,
         dp[i-1].second + |low_{i-1}  - low_i|
       );

   dp[i].second =
       horizontal
     + span
     + min(
         dp[i-1].first  + |high_{i-1} - high_i|,
         dp[i-1].second + |low_{i-1}  - high_i|
       );

7) Final answer:
       min(dp[m-1].first, dp[m-1].second)

Time complexity:
   - Sorting + coordinate compression: O(n log n)
   - DP transitions: O(n)
   Total: O(n log n)
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    // ---- Your code here ----

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll s_x, s_y, e_x, e_y;
        cin >> s_x >> s_y >> e_x >> e_y;

        vector<pair<ll, ll>> p(n);
        vector<ll> xcor;
        xcor.push_back(s_x);
        xcor.push_back(e_x);
        for (auto &[x, y] : p)
        {
            cin >> x;
            xcor.push_back(x);
        }
        for (auto &[x, y] : p)
        {
            cin >> y;
        }

        sort(xcor.begin(), xcor.end());
        xcor.erase(unique(begin(xcor), end(xcor)), end(xcor));
        ll m = (ll)xcor.size();
        // 0 - > start , m-1 - end.

        vector<pair<ll, ll>> d(m, {-1e18, 1e18}); // {high , low}
        d[0].first = s_y;
        d[0].second = s_y;

        d[m - 1].first = e_y;
        d[m - 1].second = e_y;

        for (auto &[x, y] : p)
        {
            ll idx = lower_bound(xcor.begin(), xcor.end(), x) - xcor.begin();
            d[idx].first = max(d[idx].first, y);
            d[idx].second = min(d[idx].second, y);
        }

        vector<pair<ll, ll>> dp(m, {0, 0});
        for (int i = 1; i <= m - 1; i++)
        {
            // want to reach high point.
            dp[i].first = xcor[i] - xcor[i - 1] + abs(d[i].first - d[i].second) + min(dp[i - 1].first + abs(d[i - 1].first - d[i].second), dp[i - 1].second + abs(d[i - 1].second - d[i].second));
            // want to reach low point.
            dp[i].second = xcor[i] - xcor[i - 1] + abs(d[i].first - d[i].second) + min(dp[i - 1].first + abs(d[i - 1].first - d[i].first), dp[i - 1].second + abs(d[i - 1].second - d[i].first));
        }

        cout << min(dp[m - 1].first, dp[m - 1].second) << "\n";
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cerr << "Time taken: "
         << duration.count() << " microseconds\n";
    return 0;
}





