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
/*
---------------------------------- Approach Summary ----------------------------------

Given a string `s` of length `n`, we need to identify contiguous blocks of characters,
find the maximum length `a` of such a block, and determine whether multiple characters
have blocks of that same maximum length.

---------------------------------- Steps Performed -----------------------------------

1. Traverse the string to group contiguous characters together.
   Example: "aabbcccdd" → [('a', 2), ('b', 2), ('c', 3), ('d', 2)]

2. From these groups, determine the maximum block length `a`.

3. Count how many distinct characters have a block of length exactly equal to `a`.

4. If **multiple different characters** have a block of length `a`, output `a`.
   (This means the max-length block is not unique to a single character.)

5. If **only one character** has a block of length `a`, output `a - 1` as a penalty.
   (Even if no block of length `a - 1` exists, we still return `a - 1` — it's just a rule.)

---------------------------------- Edge Case Handling --------------------------------

- Case 1: All characters are the same (e.g., "aaaaa")
  → One block of length 5 → unique → output 5 - 1 = 4

- Case 2: Multiple characters have blocks of same max length
  e.g., "aaabbbccc" → all blocks are of length 3 → output 3

- Case 3: Only one character has the longest block
  e.g., "aabbbcccccdd" → only 'c' has length 5 → output 4

- Case 4: No block of length `a - 1` exists
  e.g., "aabbbcccccdd" → max = 5, next actual block is 3 → still output 4

- Case 5: All blocks are length 1
  e.g., "abcdef" → max = 1, multiple characters → output 1

- Case 6: Only one character has block length 1
  e.g., "a" → output 0 (1 - 1)

---------------------------------- Final Note ----------------------------------------

- This approach is not looking for the second largest block length;
  it simply penalizes uniqueness by returning a - 1, regardless of whether a - 1 exists.
*/

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<char, int>> v; //{char , maxLength}
    int i = 0;
    int flag = 0;
    while (i < n)
    {
        char c = s[i];
        int len = 1;
        while (s[i] == s[i + 1] && i < n)
        {
            i++;
            len++;
        }
        v.push_back({c, len});
        i++;
    }

    sort(v.begin(), v.end(), [&](pair<char, int> &a, pair<char, int> &b)
         { return a.second > b.second; });


    int a = v[0].second;
    vector<int>f(26,0);
    for(auto d : v){
        if(d.second != a) break;
        f[d.first - 'a']++;
    }

    for(auto fr : f){
        if(fr > 1){
            flag = 1;
            break;
        }
    }

 cout << (flag ? a : a - 1) << endl;





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