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
#define gcd(a, b) ([](int x, int y) {while (y != 0) { int temp = y;y = x % y; x = temp;}return x; })(a, b)
#define lcm(a, b) (a * b / gcd(a, b))
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

1. For both arrays `a` and `b`, we want to compute the longest contiguous subarray (streak) for each number.
2. We create two frequency vectors (`max_a` and `max_b`) where:
   - `max_a[x]` stores the length of the longest contiguous streak of number `x` in array `a`
   - `max_b[x]` stores the same for array `b`
3. After computing these vectors, we iterate through all possible values and compute:
   - max_a[x] + max_b[x] → total max streak of `x` across both arrays
4. The maximum of all such sums is our final answer.

Time Complexity: O(n)
Space Complexity: O(n)
*/

void solve()
{
    ll n;
    cin >> n;
    vl a(n), b(n);
    rep2(i, 0, n) cin >> a[i];
    rep2(i, 0, n) cin >> b[i];

    vl max_a(2 * n + 5, 0), max_b(2 * n + 5, 0);


    ll count = 1;
    rep2(i, 1, n)
    {
        if (a[i] == a[i - 1])
        {
            count++;
        }
        else
        {
            max_a[a[i - 1]] = max(count, max_a[a[i - 1]]);
            count = 1;
        }
    }
    max_a[a[n - 1]] = max(count, max_a[a[n - 1]]);


    count = 1;
    rep2(i, 1, n)
    {
        if (b[i] == b[i - 1])
        {
            count++;
        }
        else
        {
            max_b[b[i - 1]] = max(count, max_b[b[i - 1]]);
            count = 1;
        }
    }
    max_b[b[n - 1]] = max(count, max_b[b[n - 1]]);


    ll ans = 0;
    for (ll i = 0; i <= 2 * n + 1; i++)
    {
        ans = max(ans, max_a[i] + max_b[i]);
    }
    cout << ans << endl;
    
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
