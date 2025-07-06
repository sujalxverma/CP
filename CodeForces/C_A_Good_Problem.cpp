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
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)

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
/*
 * Approach Explanation:
 * ---------------------
 * Goal: Construct an array of size `n` with values in the range [l, r]
 *       and return the value at index `k` (0-based), following certain constraints.
 *
 * Step-by-step logic:
 *
 * 1. If `n == 2`:
 *    - It's impossible to build the required structure with only 2 elements,
 *      so output `-1`.
 *
 * 2. If `n` is odd:
 *    - Directly return `l` as a simple base case or special case for odd sizes.
 *
 * 3. If `n` is even:
 *    - Compute the next power of 2 greater than `l`:
 *         next2power = 1 << (floor(log2(l)) + 1)
 *      This ensures that we get a value with one more bit set than `l`.
 *
 *    - If this next2power exceeds `r`, it means we can't use it,
 *      so output `-1` as it falls outside the allowed range.
 *
 *    - Otherwise:
 *        - If `k <= n - 2`: output `l`
 *          → Most of the array (first n-2 elements) is filled with `l`
 *        - Else: output `next2power`
 *          → The last two elements are set to this larger power-of-2 value
 *            to ensure higher bit-length or other constraints.
 *
 * Notes:
 * - This kind of logic might be used in bitmask/bitwise structure problems
 *   or those involving minimum excluded values, constraints on distinctness, etc.
 * - The structure ensures that most values are constant (`l`) and
 *   only the tail of the array is "special" using a higher power-of-two.
 */

void solve()
{
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n == 2)
    {
        cout << -1 << endl;
        return;
    }
    if ((n & 1) == 1)
    {
        cout << l << endl;
        return;
    }
    else
    {
        ll next2power = 1LL << ((ll)floor(log2(l)) + 1);
        if (next2power > r)
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            if (k <= n - 2)
            {
                cout << l << endl;
            }
            else
            {
                cout << next2power << endl;
            }
        }
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
