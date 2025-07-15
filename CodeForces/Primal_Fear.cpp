#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rep2(i, a, b) for (long long i = a; i < b; i++)
typedef unordered_map<int, int> umap;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define even(a) (((a) % 2) == 0 ? 1 : 0)
#define rev(v) reverse(v.begin(), v.end())
#define sorting(v) sort(v.begin(), v.end())
#define line cout << "\n"
#define contains(vec, x) (std::find((vec).begin(), (vec).end(), (x)) != (vec).end())
#define containsBS(vec, x) (std::binary_search((vec).begin(), (vec).end(), (x)))
#define zerobits(x) __builtin_ctzll(x)
#define setbits(x) __builtin_popcount(x)     // Count of set bits in int
#define setbitsll(x) __builtin_popcountll(x) // Count of set bits in long long
#define leadingzero(x) __builtin_clz(x)      // Leading zeros (int)
#define trailingzero(x) __builtin_ctz(x)     // Trailing zeros (int)
#define parity(x) __builtin_parity(x)        // 1 if odd number of set bits, else 0
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
inline bool prime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    for (int i = 3; i * i <= num; i += 2)
        if (num % i == 0)
            return false;
    return true;
}
typedef long long ll;
vector<bool> isPrime(1e6 + 10, true);
vector<ll> leftTruncatablePrimes;

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= 1e6; ++i) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= 1e6; j += i) {
                isPrime[j] = false;
            }
        }
    }
}


// if any of the digit is 0 , return false.
bool isLeftTruncatable(ll num) {
    if (num < 10) return (num != 0) && prime(num); // single-digit primes, no zero allowed

    ll temp = num;
    // Check if any digit is zero
    while (temp > 0) {
        if (temp % 10 == 0) return false;
        temp /= 10;
    }

    ll n = num;
    ll div = 1;
    while (n >= 10) {
        div *= 10;
        n /= 10;
    }

    ll truncated = num;
    while (div > 0) {
        if (!prime(truncated)) return false;
        truncated = truncated % div; // remove leftmost digit
        div /= 10;
    }

    return true;
}

void precomputeLeftTruncatable() {
    for (ll i = 2; i <= 1e6; ++i) {
        if (isPrime[i] && isLeftTruncatable(i)) {
            leftTruncatablePrimes.push_back(i);
        }
    }
}
// pre compute all left turncated primes and store in leftTruncatablePrimes

void solve() {
    ll n;
    cin >> n;
    int ans = upper_bound(leftTruncatablePrimes.begin(), leftTruncatablePrimes.end(), n) - leftTruncatablePrimes.begin() ;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    precomputeLeftTruncatable();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
