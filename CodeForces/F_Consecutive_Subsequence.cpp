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
void solve() {
    ll n; 
    cin >> n;
    vl a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<ll,ll> dp;           // dp[val] = length of longest subsequence ending with val
    map<ll,ll> prev;         // prev[val] = previous value in subsequence
    map<ll,ll> valToIndex;   // valToIndex[val] = last index of val in a[]

    ll maxLength = 0;
    ll lastValue = -1;

    for (int i = 0; i < n; i++) {
        ll value = a[i];

        ll prevLength = 0;
        if (dp.find(value - 1) != dp.end()) {
            prevLength = dp[value - 1];
        }

        dp[value] = prevLength + 1;

        if (prevLength > 0) {
            prev[value] = value - 1;
        } else {
            prev[value] = -1;
        }

        valToIndex[value] = i;

        if (dp[value] > maxLength) {
            maxLength = dp[value];
            lastValue = value;
        }
    }

    // Reconstruct the subsequence indices
    vl resultIndices;
    ll currentVal = lastValue;
    while (currentVal != -1) {
        resultIndices.push_back(valToIndex[currentVal]);
        currentVal = prev[currentVal];
    }

    cout << maxLength << "\n";
    for (int i = (int)resultIndices.size() - 1; i >= 0; i--) {
        cout << resultIndices[i] + 1 << " ";  // +1 for 1-based indexing, remove if 0-based preferred
    }
    cout << "\n";
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // ll t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
}
