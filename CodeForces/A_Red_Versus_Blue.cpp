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
Approach:

We are given:
- r = number of 'R' characters
- b = number of 'B' characters

Goal:
Construct a string of length r + b with exactly r 'R's and b 'B's,
such that the 'R's are distributed as evenly as possible between the 'B's.

Strategy:
1. There are (b + 1) gaps between the 'B's where we can place the 'R's:
   Example: for b = 2 → gaps = 3 → _ B _ B _

2. Divide r 'R's into these (b + 1) gaps:
   - Each gap gets at least floor(r / (b + 1)) R's → call this q
   - The first (r % (b + 1)) gaps get one extra R for balance

3. Loop over each gap and:
   - Print q or (q + 1) R's
   - If it's not the last gap, print a 'B'

This ensures the most balanced placement of R's between B's.
*/
void solve()
{
    int n;
    cin >> n;
    int r, b;
    cin >> r >> b;

    int partition = b + 1;
    int q = r / partition;
    int rem = r % partition;

    rep(i, 0, partition)
    {
        int rs = q + (i < rem ? 1 : 0);
        rep(i, 0, rs)
        {
            cout << "R";
        }
        if (i < b)
        {
            cout << "B";
        }
    }
    line;
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
