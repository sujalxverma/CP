#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

/*
------------------------------------------------------------
PERMUTATIONAL DP (Top-Down / Memoization)

Problem:
Count the number of ways to form sum = n using a dice
(allowed values: 1 to 6), where ORDER MATTERS.

Key Idea (Permutational DP):
- We fix the LAST move.
- If the last dice value is k, then before it we must have
  formed (n - k).
- Every way to form (n - k) becomes a new valid way for n
  by appending k at the end.

Recurrence:
f(n) = f(n-1) + f(n-2) + ... + f(n-6)

Base Case:
f(0) = 1
(Exactly one way to make sum 0 — choose nothing)

Why this is PERMUTATIONAL:
- 1 + 2 and 2 + 1 are counted separately
- Order of dice throws matters
------------------------------------------------------------
*/

ll f(vector<ll> &dp, ll n)
{
    if (n == 0)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    ll ways = 0;
    for (ll i = 1; i <= 6; i++)
    {
        if (n - i >= 0)
        {
            // ADD all possibilities (never overwrite)
            ways = (ways + f(dp, n - i)) % mod;
        }
    }

    return dp[n] = ways;
}

/*
------------------------------------------------------------
PERMUTATIONAL DP (Bottom-Up / Tabulation)

dp[i] = number of ordered sequences of dice throws
        that sum up to i

Loop order is CRITICAL:
- Outer loop → current sum
- Inner loop → last move (dice value)

This loop order ensures permutations are counted.

If we reversed the loops, it would turn into
COMBINATIONAL DP (order would NOT matter).
------------------------------------------------------------
*/

ll f_tab(ll n)
{
    vector<ll> dp(n + 1, 0);

    // Base case
    dp[0] = 1;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= 6; j++)
        {
            if (i - j >= 0)
            {
                // Fix last move = j
                dp[i] = (dp[i] + dp[i - j]) % mod;
            }
        }
    }

    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    // Using tabulation (faster, no recursion stack)
    cout << f_tab(n) << "\n";
    return 0;
}

/*
------------------------------------------------------------
HOW THIS DIFFERS FROM COMBINATIONAL DP

Permutational DP (this problem):
- Order matters
- Fix LAST move
- Transition uses SUM over all choices
- Loop order: sum → choices

Example counted:
1 + 2
2 + 1   (different)

Combinational DP (e.g., coin change combinations):
- Order does NOT matter
- Fix ITEM first
- Loop order: item → sum

Example NOT counted separately:
1 + 2 == 2 + 1

Rule to remember:
"If changing order creates a new answer → PERMUTATIONAL DP"
------------------------------------------------------------
*/
