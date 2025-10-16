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

std::mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int MOD = 1'000'000'007;
constexpr int INF = 1'000'000'000;
constexpr ll LINF = (ll)4e18; // wider than 1e18 for safety

// Fast IO
static inline void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Bit helpers (careful with types)
static inline int setbits(unsigned int x) { return __builtin_popcount(x); }
static inline int setbitsll(unsigned long long x) { return __builtin_popcountll(x); }
static inline int leadingzero(unsigned int x) { return __builtin_clz(x); }
static inline int trailingzero(unsigned int x) { return __builtin_ctz(x); }
static inline int parity(unsigned int x) { return __builtin_parity(x); }

// Math utils
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
static inline bool is_prime_ll(long long n)
{
    if (n < 2)
        return false;
    if ((n & 1LL) == 0)
        return n == 2;
    for (long long d = 3; d * d <= n; d += 2)
    {
        if (n % d == 0)
            return false;
    }
    return true;
}

// Mod ops
static inline int norm_mod(long long x)
{
    x %= MOD;
    if (x < 0)
        x += MOD;
    return (int)x;
}
static inline int mod_add(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }
static inline int mod_sub(int a, int b) { return a - b < 0 ? a - b + MOD : a - b; }
static inline int mod_mul(int a, int b) { return int(1LL * a * b % MOD); }
static inline int mod_pow(int a, long long e)
{
    int r = 1;
    while (e)
    {
        if (e & 1LL)
            r = mod_mul(r, a);
        a = mod_mul(a, a);
        e >>= 1LL;
    }
    return r;
}
static inline int mod_inv(int a) { return mod_pow(a, MOD - 2); } // MOD prime

// Algorithms helpers
template <class It>
static inline void rotate_left(It first, It last, long long k)
{
    long long n = last - first;
    if (n <= 0)
        return;
    k %= n;
    if (k < 0)
        k += n;
    std::rotate(first, first + k, last);
}

// Debug
#ifndef ONLINE_JUDGE
template <typename T>
void _pr(const T &v) { cerr << v; }
template <typename T>
void _pr(const vector<T> &v)
{
    cerr << "[ ";
    for (auto &e : v)
    {
        _pr(e);
        cerr << ' ';
    }
    cerr << "]";
}
#define debug(x)             \
    do                       \
    {                        \
        cerr << #x << " = "; \
        _pr(x);              \
        cerr << '\n';        \
    } while (0)
#else
#define debug(x) ((void)0)
#endif

/* This also worked
static inline bool f(const vector<long long>& a,
                            const vector<long long>& b,
                            long long m, long long k) {
    long long need = 0;
    int n = (int)a.size();
    for (int i = 0; i < n; i++) {
        long long req = m * a[i] - b[i];
        if (req > 0) {
            need += req;
            if (need > k) return false;
        }
    }
    return true; // i.e., need <= k
}
 
 
void solve()
{
    // TODO: implement per test case solution.
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    ll s = 1;
    ll e = 1e10;
    ll ans = 0;
    // if(n == 1){
    //     cout<< (b[0]+k)/a[0]<<"\n";
    //     return ;
    // }
    while (s <= e)
    {
        ll m = s + (e - s) / 2;
        if (f(a, b, m, k))
        {
            ans = m;
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    ll sum = 0;
    for(ll i = 0; i < n ; i++){
        sum += a[i];
    }
    if(ans == 1e18){
        cout<<ans+ (ll)(k/sum) <<"\n";
        return ;
    }
    cout<<ans<<"\n";
} */


static inline bool f(const vector<long long> &a,
                     const vector<long long> &b,
                     long long m, long long k)
{
    __int128 need = 0; // 128-bit accumulator
    int n = (int)a.size();
    for (int i = 0; i < n; i++)
    {
        __int128 prod = (__int128)m * (__int128)a[i]; // 128-bit product
        __int128 req = prod - (__int128)b[i];         // 128-bit diff
        if (req > 0)
        {
            need += req;
            if (need > (__int128)k)
                return false; // early exit
        }
    }
    return true; // need <= k
}

void solve()
{
    // TODO: implement per test case solution.
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    ll s = 1;
    ll e = (ll)1e18;
    ll ans = 0;
    // if(n == 1){
    //     cout<< (b[0]+k)/a[0]<<"\n";
    //     return ;
    // }
    while (s <= e)
    {
        ll m = s + (e - s) / 2;
        if (f(a, b, m, k))
        {
            ans = m;
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }

    cout << ans << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto begin = chrono::steady_clock::now();

    int T = 1;
    // if (!(cin >> T))
    //     return 0;
    while (T--)
        solve();

    auto end = chrono::steady_clock::now();
    auto ns = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
    cerr << "Time measured: " << (ns * 1e-9) << " seconds.\n";
    return 0;
}