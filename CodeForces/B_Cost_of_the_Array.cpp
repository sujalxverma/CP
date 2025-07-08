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
        ll __n = (ll)(v).size();                         \
        if (__n > 0)                                     \
        {                                                \
            ll __k = (k) % __n;                          \
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
Problem Statement:
------------------
Given an array `a` of length `n` and an even number `k`, split the array into
`k` contiguous non-empty subarrays. Then, concatenate all even-indexed subarrays
(2nd, 4th, ..., kth) into a new array `b` and append 0 at the end.
The cost of `b` is defined as the first index `i` (1-based) where b[i] ≠ i.
We aim to minimize this cost.

Approach:
---------
1. Special Case: If n == k
   - Each element must be its own subarray.
   - Even-indexed subarrays (in 1-based logic) will be at indices 2, 4, ...
     → These are a[1], a[3], a[5], ... (0-based indices: i where i % 2 == 1).
   - Store those values in a new array `b`, append 0 at the end.
   - Compare b[i] with (i+1). First mismatch determines cost.

2. General Case: n > k
   - The current code uses a heuristic:
     - If the first (n - k + 1) elements are all equal to 1, assume cost is 2.
     - Otherwise, assume cost is 1.
   - This heuristic assumes that a longer prefix of ones makes it harder
     to build a correct sequence [1, 2, 3, ...] in b, but it's not a general solution.

Limitations:
------------
- The current implementation does NOT simulate actual subarray partitioning.
- It assumes that cost is always 1 or 2, which is not always true.
- For fully correct results, a more general algorithm is needed that:
  → Finds the maximum prefix [1, 2, 3, ..., x] that can be constructed from 
     even-indexed subarrays after optimal partitioning.
  → This may involve greedy selection or scanning while maintaining possible splits.

Note:
-----
- The use of a pointer-based count (a + 1) is unsafe with stack arrays; should use std::vector.
- Your implementation handles the `n == k` case reasonably, but needs improvement for general cases.
*/


void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int a[n];
    rep(i, 0, n) cin >> a[i]; // 1 based indexing.

    if(n==k){
     vi b;
     rep(i,0,n){
        if((i&1) == 1){
            b.push_back(a[i]);
        }

     }
     b.push_back(0);
     rep(i,0,b.size()){
        if(i+1 != b[i]){
            cout<<i+1<<endl;
            return ;
        }
     }
    }

    if (count(a + 1, a + n - k + 2, 1) == n - k + 1){
        cout<<2<<endl;
    }else{
        cout<<1<<endl;
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
