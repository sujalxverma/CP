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
#define line cout << endl
#define contains(vec, x) (std::find((vec).begin(), (vec).end(), (x)) != (vec).end())
#define containsBS(vec, x) (std::binary_search((vec).begin(), (vec).end(), (x)))
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

const int MOD = 100000;

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

    1. Precompute all primes up to √(max(a[i])) or (1e6+1) using the Sieve of Eratosthenes.
    2. Create a set of T-primes (i.e., primes squared).
    3. For each a[i], simply check if it's in the set.
    
*/

set<ll>ans ;
void sieveOfEratosthenes(ll n) {
    vector<ll> numbers(n + 1, 0);  // 0 = prime, 1 = not prime

    for (ll i = 2; i * i <= n; i++) {
        if (numbers[i]) continue;

        for (ll j = i * i; j <= n; j += i) {
            numbers[j] = 1;  // mark as not prime
        }
    }

   
    for (ll i = 2; i <= n; i++) {
        if (!numbers[i]) {
            ans.insert(i * i);
        }
    }


}

void solve()
{
    ll n;
    cin >> n;
    vl a(n);
    rep2(i, 0, n)
    {
        cin >> a[i];
    }

    rep2(i, 0, n)
    {
       if(a[i] == 1){
        no;
        continue;
       }
       if(ans.count(a[i]) == 1){
        yes;
       }
       else{
        no;
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
    // ll t;
    // cin >> t;
    // while (t--)
    // {
        sieveOfEratosthenes(1e6); 
    solve();
    // }
}
