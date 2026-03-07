#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

// Full nCR computation
const int MAXN = 30;
const long long MOD = 1e9 + 7;
long long fact[MAXN], invFact[MAXN];

long long modpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[MAXN - 1] = modpow(fact[MAXN - 1], MOD - 2);

    for (int i = MAXN - 2; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

long long nCr(int n, int r) {
    if (r > n || r < 0)
        return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    precompute();
    while (t--) {
        /*
        - maxbits = number of bits in num, (0 index)
        - cntbits = number of setbits.
        - ans = (summation) (maxbits(a) +  cntbits(a) > k)
        - n -> some power of 2.
        - Thus maxbits range [0,d-1]
        - Say if we have bits 4 , and setbits 3, their value = 7, which is > k.
          Thus all combination of nCr(4,3) , will have value = 7, >k.
          ans += nCr(4,3).
        */
        int n, k;
        cin >> n >> k;
        int ans = 0;
        // int maxbits = 31 - __builtin_clz(n);
        int maxbits = floor(log2(n));
        for (int i = 0; i < maxbits; i++) {
            for (int j = 1; j <= i + 1; j++) {
                int value = j + i;
                if (value > k) {
                    //  - Say if we have bits 4 , and setbits 3, their value = 7, which is > k.
                    // MSB is always 1, that is why nCr(i,j-1);
                    // b/c j =>  MSB(1) + all other setbits.
                    ans += nCr(i, j - 1);
                }
            }
        }
        if (maxbits + 1 > k) {
            ans++;
        }

        cout << ans << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}