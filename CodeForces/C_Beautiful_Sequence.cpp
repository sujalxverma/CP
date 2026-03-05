#include "bits/stdc++.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

using ll = long long;

const ll MOD = 998244353;

/*

PROBLEM STRUCTURE
-----------------
We want to count subsequences of the form:

    1 , 2 , 2 , 2 , ... , 2 , 3

Rules:
• First element must be 1
• Last element must be 3
• Between them any non-empty subset of 2's can be chosen


------------------------------------------------------------
BRUTE FORCE APPROACH
------------------------------------------------------------

Observation:
If we fix positions of 1 and 3:

    i < j
    a[i] = 1
    a[j] = 3

Let

    k = number of 2's between them

Every subsequence must pick:
    • the 1
    • the 3
    • at least one of the k twos

Number of ways to choose the twos:

    C(k,1) + C(k,2) + ... + C(k,k)

Which simplifies to:

    2^k − 1

So brute force procedure:

1. Store indices of all 1's.
2. Store indices of all 3's.
3. Precompute prefix count of 2's.
4. For each pair (1,3):
       count twos between them
       add (2^k − 1)

Time Complexity:

    O(#1 × #3)

Worst case:

    O(n²)


------------------------------------------------------------
OPTIMIZATION IDEA
------------------------------------------------------------

For a fixed pair (1,3):

    contribution = 2^(prefix[j] − prefix[i]) − 1

Rewrite exponent:

    2^(prefix[j] − prefix[i])
        = 2^prefix[j] / 2^prefix[i]

Define:

    power2[x] = 2^(prefix[x])

Then:

    contribution =
        power2[j] / power2[i] − 1

Instead of iterating every pair (1,3), we:

1. Precompute power2[i]
2. Maintain:

       sum = Σ power2[j]  for all remaining 3's

3. For each index i where a[i] = 1:

       total += (sum / power2[i]) − number_of_3_after_i

Why subtract suffix count?

Because the division gives:

    2^(k)

but we need

    2^k − 1

and there is one subtraction for every 3.


------------------------------------------------------------
DATA STRUCTURES USED
------------------------------------------------------------

prefix[i]  → number of 2's up to i
suffix[i]  → number of 3's after i
power2[i]  → 2^(prefix[i])

sum        → Σ power2[j] for remaining 3's


------------------------------------------------------------
TIME COMPLEXITY
------------------------------------------------------------

Per test case:

    O(n)

Total memory:

    O(n)


------------------------------------------------------------
ADVANTAGE
------------------------------------------------------------

Reduces quadratic brute force into a single linear scan.

*/

ll mod_pow(ll base, ll exp) {
    ll result = 1;
    base %= MOD;

    while (exp) {
        if (exp & 1)
            result = (result * base) % MOD;

        base = (base * base) % MOD;
        exp >>= 1;
    }

    return result;
}

ll mod_inv(ll x) {
    return mod_pow(x, MOD - 2);
}

ll mod_div(ll a, ll b) {
    return (a % MOD * mod_inv(b)) % MOD;
}

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

        for (auto &x : a)
            cin >> x;

        vector<ll> prefix(n);
        vector<ll> suffix(n);

        prefix[0] = (a[0] == 2);

        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + (a[i] == 2);

        suffix[n - 1] = (a[n - 1] == 3);

        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] + (a[i] == 3);

        vector<ll> power2(n);

        for (int i = 0; i < n; i++)
            power2[i] = mod_pow(2, prefix[i]);

        ll sum = 0;

        for (int i = 0; i < n; i++)
            if (a[i] == 3)
                sum = (sum + power2[i]) % MOD;

        ll answer = 0;

        for (int i = 0; i < n; i++) {

            if (a[i] == 2)
                continue;

            if (a[i] == 3) {
                sum = (sum - power2[i] + MOD) % MOD;
                continue;
            }

            if (suffix[i] == 0)
                break;

            ll val = (mod_div(sum, power2[i]) - suffix[i]) % MOD;

            if (val < 0)
                val += MOD;

            answer = (answer + val) % MOD;
        }

        cout << answer << '\n';
    }

    auto stop = high_resolution_clock::now();

    auto duration =
        duration_cast<microseconds>(stop - start);

    cerr << "Time taken: "
         << duration.count()
         << " microseconds\n";

    return 0;
}