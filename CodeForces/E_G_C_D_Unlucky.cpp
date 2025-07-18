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

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

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
inline int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

inline int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

#define ROTATE_VEC(v, k)                                 \
    do                                                   \
    {                                                    \
        int __n = (int)(v).size();                       \
        if (__n > 0)                                     \
        {                                                \
            int __k = (k) % __n;                         \
            if (__k != 0)                                \
            {                                            \
                reverse((v).begin(), (v).end());         \
                reverse((v).begin(), (v).begin() + __k); \
                reverse((v).begin() + __k, (v).end());   \
            }                                            \
        }                                                \
    } while (0)

inline int mod_add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
inline int mod_sub(int a, int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
inline int mod_mul(int a, int b) { return ((1LL * a % MOD) * (b % MOD)) % MOD; }
inline int mod_pow(int base, int exp)
{
    int result = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (1LL * result * base) % MOD;
        base = (1LL * base * base) % MOD;
        exp /= 2;
    }
    return result;
}

template <typename T>
void printVector(const T &val)
{
    cerr << val;
}

template <typename T>
void printVector(const vector<T> &v)
{
    cerr << "[ ";
    for (const auto &elem : v)
    {
        printVector(elem);
        cerr << " ";
    }
    cerr << "]";
}
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    printVector(x);    \
    cerr << endl;
#else
#define debug(x)
#endif

//------------------------------------------------------------------------------------------------------------//
//                                          Here you go

bool is_valid_array_possible(const vector<ll> &prefix_gcd, const vector<ll>& suffix_gcd) {
    int n = prefix_gcd.size();

    for (int i = 0; i < n; ++i) {
        int a_possible_from_prefix;
        if (i == 0) {
            a_possible_from_prefix = prefix_gcd[0];
        } else {
            // prefix_gcd[i] = gcd(prefix_gcd[i-1], A[i])
            // Check if prefix_gcd[i] divides prefix_gcd[i-1]
            if (prefix_gcd[i - 1] % prefix_gcd[i] != 0) {
                return false;
            }
            a_possible_from_prefix = prefix_gcd[i];
        }

        int a_possible_from_suffix;
        if (i == n - 1) {
            a_possible_from_suffix = suffix_gcd[n - 1];
        } else {
            // Check if suffix_gcd[i+1] divides suffix_gcd[i]
            if (suffix_gcd[i + 1] % suffix_gcd[i] != 0) {
                return false;
            }
            a_possible_from_suffix = suffix_gcd[i];
        }

        // Both prefix and suffix impose constraints on A[i]
        // So check if gcd(a_possible_from_prefix, a_possible_from_suffix) == max(prefix_gcd[i], suffix_gcd[i])
        if (gcd(a_possible_from_prefix, a_possible_from_suffix) != max(prefix_gcd[i], suffix_gcd[i])) {
            return false;
        }
    }

    return true;
}
void solve()
{
    int n;
    cin >> n;
    vl p(n), s(n);
    rep(i, 0, n) cin >> p[i];
    rep(i, 0, n) cin >> s[i];

    rep(i,0,n-1){
        if(p[i] < p[i+1]){
            no;
            return ;
        }
    }
    rep(i,0,n-1){
        if(s[i] > s[i+1]){
            no;
            return ;
        }
    }
    bool f = is_valid_array_possible(p,s);

    if(f){
        yes;
    }else{
        no;
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}