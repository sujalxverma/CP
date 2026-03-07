#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
using ll = long long;
const ll mod = 1e9 + 7;

/*
1. ARRAY OF SIZE N, AND NUMBERS 1<=A[i]<=M, THEN TOTAL ARRAY POSSIBLE = M^N.
2. EACH ELEMENT CAN BE USED IN N POSITIONS, AND WE HAVE M ELEMENTS OF ALL.
3. FOR EACH ARRAY , F(A) = SUM(A[2 , N]) - A[1]. -> THIS IS MAXIMUM F(A) ACHIEVABLE FOR AN ARRAY,
   WHERE A[1] IS MINIUM VALUE OF ARRAY
4. SAY WE SORTED THE ARRAYS, SO A[1] IS MIN, Y = A[1].
5. ALL OTHER ELEMENTS >= Y. THUS [Y , M]
6. THUS NUMBER OF ARRAYS ARE : (M-Y+1)^N. THESE ARE ARRAYS WHOSE MINIUM IS >=Y, NOT EXACTLY Y.
7. NUMBER OF ARRAYS WHOSE MIN > Y, ARE : (M-Y)^N.
8. NUMBER OF ARRAYS WHOSE MIN IS EXACTLY Y -> (M-Y+1)^N - (M-Y)^N == SAY Z.
9. SUM OF Y IN THESE ARRAYS -> Y * Z.
10. NOW Y RANGES FROM [1,M].
11. THUS SUM -> (SUMMATION)[1,Y] -> Y*Z.
*/

// Modular Exponention
ll mod_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        ll inv2 = (mod + 1) / 2;

        ll totalSum =
            (n % mod *
             mod_pow(m, n - 1, mod) % mod *
             ((m % mod * (m + 1) % mod) % mod * inv2 % mod) % mod) %
            mod;

        ll ysum = 0;

        for (ll y = 1; y <= m; y++) {
            ll diff =
                (mod_pow(m - y + 1, n, mod) -
                 mod_pow(m - y, n, mod) + mod) %
                mod;

            ysum = (ysum + y % mod * diff % mod) % mod;
        }

        cout << (totalSum - ysum + mod) % mod << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}