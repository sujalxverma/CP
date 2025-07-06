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
 * Approach and Strategy:
 * ----------------------
 * The problem requires counting the total number of pairs of elements in an array
 * that have the same bit-length representation.
 *
 * Steps:
 * 1. Read the input array of integers.
 * 2. For each element, compute its bit-length:
 *      bit_length = floor(log2(value)) + 1
 *    This gives the number of bits required to represent the number.
 *
 * 3. Store all bit-lengths in a separate array and sort it.
 *    Sorting groups equal bit-length elements together.
 *
 * 4. Traverse the sorted array to identify consecutive groups of equal bit-lengths.
 *    For each group:
 *      - Calculate the number of pairs that can be formed using nC2 formula:
 *          number_of_pairs = nC2(group_size) = group_size * (group_size - 1) / 2
 *      - Accumulate this count to the total result.
 *
 * 5. Output the total count of pairs having equal bit-lengths.
 *
 * Important notes:
 * - Initialize the group count to 1 at the start since the first element always forms
 *   a group of at least size 1.
 * - When moving to a new group, add the pairs from the previous group using nC2.
 * - For groups of size 1, nC2 returns 0 as no pairs can be formed.
 *
 * This approach efficiently groups elements by their bit-length and counts pairs
 * without extra space or complex data structures, using sorting and a simple traversal.
 */

/*
 * Why we approach the problem this way:
 * ------------------------------------
 * 1. The condition (a[i] & a[j]) >= (a[i] ^ a[j]) compares bitwise AND and XOR of two numbers.
 *    Understanding this relationship helps reduce the problem from brute force checks to
 *    something more manageable.
 *
 * 2. Bitwise AND tends to be smaller or equal to both numbers, while XOR highlights differing bits.
 *    The inequality suggests pairs with many common bits and fewer differing bits are favorable.
 *
 * 3. By analyzing this condition, we can exploit bit-level patterns or mathematical properties,
 *    potentially grouping numbers or using sorting to optimize pair counting.
 *
 * 4. Doing a direct brute force O(n^2) check may be too slow for large inputs, so recognizing
 *    properties of AND and XOR guides efficient solutions.
 *
 * In summary, the approach is designed to leverage bitwise properties to simplify counting pairs
 * that satisfy the given condition without expensive computations.
 */
long long nC2(long long n)
{
    if (n < 2)
        return 0;
    return (n * (n - 1)) / 2;
}

void solve()
{
    ll n;
    cin >> n;
    vl a(n);
    rep2(i, 0, n)
    {
        ll k;
        cin >> k;
        a[i] = floor(log2(k)) + 1;
    }
    sort(a.begin(), a.end());

    ll total = 0;
    ll count = 1; // Start with 1 for the first element

    rep2(i, 1, n)
    {
        if (a[i] == a[i - 1])
        {
            count++;
        }
        else
        {
            total += nC2(count);
            count = 1; // Reset count for new group
        }
    }
    total += nC2(count); // Add for the last group
    cout << total << endl;
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
