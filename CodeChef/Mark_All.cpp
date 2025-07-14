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
#define zerobits(x)          __builtin_ctzll(x)
#define setbits(x)           __builtin_popcount(x)     // Count of set bits in int
#define setbitsll(x)         __builtin_popcountll(x) // Count of set bits in long long
#define leadingzero(x)       __builtin_clz(x)      // Leading zeros (int)
#define trailingzero(x)      __builtin_ctz(x)     // Trailing zeros (int)
#define parity(x)            __builtin_parity(x)        // 1 if odd number of set bits, else 0

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
    Problem Insight:
    ----------------
    You are given an array A of size n.
    The goal is to find the **minimum possible cost** based on selecting certain elements.

    The operations or decisions you can perform:
    -------------------------------------------
    1. You're allowed to consider combinations of elements from the array using:
       a. Pairwise sums of adjacent elements (a[i] + a[i+1]).
       b. Minimum so far (`val`) from the prefix combined with current a[i] => (a[i] + val).
    
    2. You are essentially minimizing:
         - Either sum of adjacent elements: a[i] + a[i+1]
         - Or, a[i] + some previous minimal value (prefix) => val = min(val, a[i])

    3. Also, you compare the above with:
         - The minimum of the edge elements (first and last): min(a[0], a[n-1])
    
    Final Answer:
    -------------
    - The result is the **minimum of all the above**.
    - It's guaranteed that the result will be less than or equal to min(a[0], a[n-1])
      because you can always choose one of those individually as your answer if needed.

    Note:
    -----
    The loop maintains the minimum prefix value `val` and at each step computes:
        - ans = min(ans, a[i] + a[i+1], a[i] + val)
      Then updates `val` to the minimum seen so far.
*/

/*
      A = [3,2,7,4,5,6,1,3,4]
      1. Now how can you perform the operation, either :
          a. Take prefix op from (1 to i) and suffix op from (i+1,N).
          b. Another way, prefix op form (1 to i) and suffix op from (j to N). where  (j < i), means taking suffix,A[j]
             which lies before A[i], it can be done.
          c. Now, we can take minium of either 2 above steps.
          4. But keep in mind to update the j (j<i) , is it possible that after applying prefix on i, for the next iteration,
             A[i] < A[j] , so we can update j , with (j = i).
      2. the ans will be less than min(A[0] , A[n-1]);

    
              
*/


void solve()
{
      int n;
    cin >> n;
    vl a(n);
    rep(i,0,n) cin >> a[i];
    ll mini = min(a[0] , a[n-1]);
    ll val = a[0];
    ll ans = INT_MAX;
    for(int i = 1 ; i <= n-1 ; i++){
        ans = min(ans ,   min(a[i] + a[i+1] ,  a[i] + val ));
        val = min(val,a[i]);
    }
    cout<<min(ans,mini)<<"\n";
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