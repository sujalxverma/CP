#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
#define int long long

const int mod = 998244353;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int binaryExpo(int base, int exp) {
    int res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

vector<int> getPrimeFactors(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}

void solve(int n, int m) {
    int ans = 0;
    vector<int> powers(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        // Safe-guarding against n < 2 edge cases
        powers[i] = binaryExpo(i, max(0LL, n - 2));
    }

    vector<vector<int>> primes(m + 1);
    for (int i = 2; i <= m; i++) {
        primes[i] = getPrimeFactors(i);
    }

    int dp[105];
    memset(dp, 0, sizeof(dp));
    for (int g = m; g >= 1; g--) {
        dp[g] = powers[m / g];

        for (int mult = 2 * g; mult <= m; mult += g)
            dp[g] = (dp[g] - dp[mult] + mod) % mod;
    }
    // fix the gcd -g for : A[2] to A[N-1]
    for (int g = 2; g <= m; g++) {
        for (int a = 2; a <= m; a++) {
            for (int b = 2; b <= m; b++) {
                if (gcd(gcd(a, b), g) != 1 || gcd(a, g) <= 1 || gcd(b, g) <= 1)
                    continue;
                ans = (ans % mod + dp[g] % mod) % mod;
            }
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    // Fast I/O is heavily recommended for N=200000, M=100
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            int N, M;
            cin >> N >> M;
            solve(N, M);
        }
    }
    return 0;
}