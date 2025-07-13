#include "bits/stdc++.h"
using namespace std;

/*
Approach:
Given an array v of size n, where each v[i] represents a position (1-based),
we want to construct an array 'ans' of the first n prime numbers.

For each index i (0-based):
- If v[i] == i+1 (the element points to itself), print ans[i].
- Otherwise, print ans[v[i] - 1].

We precompute a large list of primes using the Sieve of Eratosthenes.
For each test case, we output the prime corresponding to each position as described above.
*/
/*
    Understanding the Condition:
    ----------------------------
    The condition res[i] == res[a[i] - 1] implies that:
        - The value at index i must be equal to the value at index a[i] - 1.
        - Since a[i] uses 1-based indexing, we subtract 1 for 0-based access.

    This creates a chain of equalities:
        res[i] == res[a[i] - 1]
              == res[a[a[i] - 1] - 1]
              == res[a[a[a[i] - 1] - 1] - 1]
              ... and so on

    In other words, each index is "pointing" to another index whose value it must match,
    forming a chain (or path) of equal-value constraints.

    These chains always terminate at a "root" index j, where a[j] == j + 1,
    meaning that res[j] == res[j], so we can assign it a concrete value.

    Once the root has a value, the entire chain leading to it can be assigned the same value,
    thereby satisfying the condition for all indices along the path.
*/

vector<long long> sieveOfEratosthenes(long long n) {
    vector<int> isNotPrime(n + 1, 0);

    for (long long i = 2; i * i <= n; i++) {
        if (isNotPrime[i]) continue;
        for (long long j = i * i; j <= n; j += i) {
            isNotPrime[j] = 1;
        }
    }

    vector<long long> primes;
    for (long long i = 2; i <= n; i++) {
        if (!isNotPrime[i]) primes.push_back(i);
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    // Precompute primes up to 10^7 (should be enough for typical constraints)
    vector<long long> primes = sieveOfEratosthenes(1e7);

    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        // For each element, print the prime number corresponding to the condition
        for (int i = 0; i < n; i++) {
            if (v[i] == i + 1)
                cout << primes[i] << " ";
            else
                cout << primes[v[i] - 1] << " ";
        }
        cout << "\n";
    }
}
