
/*
=============================================================
=                    PROBLEM LOGIC                          =
=============================================================

You choose a range [l, r] and replace every a[l..r] with (l + r).

The change in total sum is:

    Δ = sum_{i=l..r} (l+r - a[i])
      = (r - l + 1) * (l + r) - (prefix[r] - prefix[l-1])

Expand (r - l + 1) * (l + r):

    (r - l + 1)(l + r) = (r^2 + r) + (-l^2 + l)

So:

    Δ = (r^2 + r - prefix[r])        <-- depends only on r
      + (-l^2 + l + prefix[l-1])    <-- depends only on l

Define:

    F(r) = r^2 + r - prefix[r]
    G(l) = -l^2 + l + prefix[l-1]

Thus:

    Δ = F(r) + G(l), with the constraint l ≤ r.

==============================================================
=          KEY OPTIMIZATION (CRITICAL PATTERN)              =
==============================================================

We want:

    max over all l ≤ r of (F(r) + G(l))

This can be done in **O(n)**:

    - Maintain maxi = best G(l) seen so far (for all l ≤ r)
    - For each r from 1..n:
         diff = max(diff, F(r) + maxi)
         update maxi with G(r)

This avoids an O(n²) brute force.

==============================================================
=         WHAT TO REMEMBER FOR FUTURE PROBLEMS             =
==============================================================

1. If the cost for a range [l, r] can be algebraically split into:

       something_with(r) + something_with(l)

   then you can solve it in **O(n)**:
       Scan r from 1..n and maintain max G(l) for l ≤ r.

2. Always convert range sums a[l..r] into prefix sums:
       prefix[r] - prefix[l-1]

3. When you see (r - l + 1), expand it — often it separates nicely.

4. With n up to 2e5, never use O(n²). Look for:
       algebraic transformations,
       prefix maxima,
       DP over prefixes,
       Kadane-like optimizations.

5. This "F(r) + G(l)" technique is VERY common in Codeforces and 
   competitive programming for single-range-optimization problems.

==============================================================
*/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        ll sum = 0;
        // 1 based indexing.
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        vector<ll> prefix(n + 1, 0);
        vector<ll> suffix(n + 2, 0);

        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + a[i];

        suffix[n] = a[n];
        for (int i = n - 1; i >= 1; i--)
            suffix[i] = suffix[i + 1] + a[i];

        ll diff = 0;
        ll maxi = 0;

        for (ll r = 1; r <= n; r++)
        {
            maxi = max(maxi , -1*(r*r) + r + prefix[r-1]);
            diff = max(diff , r*r + r - prefix[r] + maxi);
        }
        cout << sum + diff << "\n";
    }
    return 0;
}