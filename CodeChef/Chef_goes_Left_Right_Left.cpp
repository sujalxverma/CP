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
const int MOD = 1e7 + 7;

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
Strategy:

Chef is trying to find Reziba at the Code Expo by asking people whose ratings
are distinct and arranged such that:
    - People with rating > X are to the right of person X
    - People with rating < X are to the left of person X

Each person tells Chef whether Reziba is to their left or right,
based on whether their own rating is higher or lower than Reziba's rating `k`.

To validate the sequence of people Chef questioned, we simulate his search:

1. We maintain two bounds:
   - `low`: the minimum possible rating Reziba can have (exclusive)
   - `high`: the maximum possible rating Reziba can have (exclusive)

2. For each person with rating `a[i]`:
   - If `a[i]` lies outside the current (low, high) range, the sequence is invalid.
   - If `a[i] > k`, Reziba must be to the left => update `high = min(high, a[i])`
   - If `a[i] < k`, Reziba must be to the right => update `low = max(low, a[i])`
   - If `a[i] == k`, this is Reziba — no update needed

3. If we finish processing the entire sequence without violating the bounds,
   the sequence is valid and the answer is "YES".

This simulates how Chef restricts his search range step by step,
and ensures that he never revisits or crosses previously explored directions.
*/



void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    int high = INT_MAX;
    int low = INT_MIN;

    rep(i, 0, n)
    {
        if (a[i] <= low || a[i] >= high)
        {
            no;
            return;
        }

            if (a[i] > k)
            {
                high = min(high, a[i]);
            }
            else if (a[i] < k)
            {
                low = max(low, a[i]);
            }

    }
     yes;
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
