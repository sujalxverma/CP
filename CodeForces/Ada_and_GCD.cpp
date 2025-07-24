#include "bits/stdc++.h"
using namespace std;

const int MAXA = 1e7 + 1;
const long long MOD = 1000000007;

int spf[MAXA];         // smallest prime factor of i
int countInNums[MAXA]; // how many numbers have this prime factor
int minExponent[MAXA]; // minimum exponent of this prime factor across all numbers

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Initialize SPF to itself for all numbers and minExponent to a large number
    for (int i = 1; i < MAXA; i++) {
        spf[i] = i;
        minExponent[i] = INT_MAX; // use max int for min comparison
    }

    // Compute SPF using sieve of Eratosthenes variant
    for (int i = 2; i * i < MAXA; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = i * i; j < MAXA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    int n;
    cin >> n;

    long long gcdResult = 1;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        unordered_map<int, int> primeCount;

        // Factorize each factor and accumulate prime counts
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            while (x > 1) {
                primeCount[spf[x]]++;
                x /= spf[x];
            }
        }

        // Update global counts:
        // - Mark that these primes appear in this number
        // - Update the minimum exponent seen so far
        for (auto& [prime, cnt] : primeCount) {
            countInNums[prime]++;
            minExponent[prime] = min(minExponent[prime], cnt);
        }
    }

    // Compute GCD by multiplying primes to their minimum exponents
    for (int prime = 2; prime < MAXA; prime++) {
        if (countInNums[prime] == n) { // prime appears in all numbers
            for (int k = 0; k < minExponent[prime]; k++) {
                gcdResult = (gcdResult * prime) % MOD;
            }
        }
    }

    cout << gcdResult << "\n";
    return 0;
}
