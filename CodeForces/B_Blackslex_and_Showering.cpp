// VERMA 
#include "bits/stdc++.h"
using namespace std;
#include <random>
#include <chrono>
#include <numeric>

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<long long>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int MOD = 1'000'000'007;
constexpr int INF = 1'000'000'000;
constexpr ll LINF = (ll)4e18;

// Fast IO
static inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Bit helpers
static inline int setbits(unsigned int x) { return __builtin_popcount(x); }
static inline int setbitsll(unsigned long long x) { return __builtin_popcountll(x); }
static inline int leadingzero(unsigned int x) { return __builtin_clz(x); }
static inline int trailingzero(unsigned int x) { return __builtin_ctz(x); }
static inline int parity(unsigned int x) { return __builtin_parity(x); }

// Math utils
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Debug
#ifndef ONLINE_JUDGE
template<typename T>
void _pr(const T& v) { cerr << v; }
template<typename T>
void _pr(const vector<T>& v) {
    cerr << "[ ";
    for (auto &e : v) {
        _pr(e);
        cerr << ' ';
    }
    cerr << "]";
}
#define debug(x) do { cerr << #x << " = "; _pr(x); cerr << '\n'; } while(0)
#else
#define debug(x) ((void)0)
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto begin = chrono::steady_clock::now();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        // EDGE CASE
        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }

        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += abs(a[i] - a[i + 1]);
        }

        int minSum = sum;

        for (int i = 0; i < n - 2; i++) {
            if (i == 0) {
                minSum = min(minSum, sum - abs(a[i] - a[i + 1]));
            } else {
                minSum = min(
                    minSum,
                    sum
                    - abs(a[i] - a[i - 1])
                    - abs(a[i] - a[i + 1])
                    + abs(a[i - 1] - a[i + 1])
                );
            }
        }

        minSum = min(minSum, sum - abs(a[n - 1] - a[n - 2]));

        cout << minSum << "\n";
    }

    auto end = chrono::steady_clock::now();
    auto ns = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
    cerr << "Time measured: " << (ns * 1e-9) << " seconds.\n";

    return 0;
}
