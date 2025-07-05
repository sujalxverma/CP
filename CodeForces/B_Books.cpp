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
Why use the Sliding Window Technique?

- Problem:
  We are given an array of book reading times and a total amount of free time (k).
  We need to find the maximum number of consecutive books Valera can read such that
  the total reading time does not exceed k.

- Naive Approach:
  Try every possible subarray using nested loops.
  Time Complexity: O(n^2) — too slow for n up to 1e5.

- Sliding Window Insight:
  We want the longest subarray (of consecutive books) where the sum of times is <= k.
  This is a classic use case for the sliding window (or two-pointer) technique:
    → Expand the window from the right.
    → Shrink it from the left if the sum exceeds the limit.
    → Keep track of the maximum window length that satisfies the constraint.

- Efficiency:
  Each element is added and removed from the window at most once.
  So the time complexity is O(n), which is optimal and fast enough.

- Summary:
  Sliding window helps us efficiently maintain a moving range [j, i]
  that always satisfies the condition (sum ≤ k),
  and update the maximum number of books that can be read.
*/

void solve()
{
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    vl a(n);
    rep2(i, 0, n)
    {
        cin >> a[i];
    }

    // Sliding window
    ll sum = 0;
    ll j = 0;
    ll len = 0;

    rep2(i, 0, n)
    {
        sum += a[i];

        // Shrink window if sum exceeds k
        while (sum > k && j <= i)
        {
            sum -= a[j];
            j++;
        }

        // Now sum <= k, update max length
        len = max(len, i - j + 1);
    }

    cout << len << endl;
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
