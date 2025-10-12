// VERMA
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

void rotateSubarrayRightByOne(std::vector<int> &arr, int i, int j)
{
    if (i < 0 || j >= arr.size() || i >= j)
    {
        std::cerr << "Invalid indices.\n";
        return;
    }

    int last = arr[j]; // Save the last element
    for (int k = j; k > i; --k)
    {
        arr[k] = arr[k - 1];
    }
    arr[i] = last;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    // vector<int> a(n);
    int z = 0, o = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            z++;
        }
        else
        {
            o++;
        }
    }
    // if (z == n || o == n)
    // {
    //     cout << "YES" << "\n";
    //     if (o == n)
    //     {
    //         for (int i = 1; i <= n; i++)
    //         {
    //             cout << i << " ";
    //         }
    //         cout << "\n";
    //         return;
    //     }
    //     else
    //     {
    //         int m = n / 2;
    //         cout << m << " ";
    //         for (int i = 1; i <= m - 1; i++)
    //         {
    //             cout << i << " ";
    //         }
    //         cout << n << " ";
    //         for (int i = m + 1; i <= n - 1; i++)
    //         {
    //             cout << i << " ";
    //         }
    //         cout << "\n";
    //         return;
    //     }
    // }

    if (s[0] == '0' && s[1] == '1')
    {
        cout << "NO" << "\n";
        return;
    }
    if (s[n - 1] == '0' && s[n - 2] == '1')
    {
        cout << "NO" << "\n";
        return;
    }
    for (int i = 0; i < n - 2; i++)
    {
        if (s[i] == '1' && s[i + 1] == '0' && s[i + 2] == '1')
        {
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    bool f = false;
    int x = 0;
    int y = 0;
   for(int i = 0 ; i < n ; i++){
    if(s[i] == '0'){
        x = i;
        y = n - 1;
        for(int k = i+1; k < n ; k++){
            if(s[k] == '1'){
                y = k - 1;
                break;
            }
        }

        if (x < y)
            rotateSubarrayRightByOne(a, x, y);

        i = y;  // skip to next part
    }
}


    for (auto x : a)
    {
        cout << x << " ";
    }

    cout << "\n";
    return;
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
