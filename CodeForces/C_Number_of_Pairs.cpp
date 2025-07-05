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

// index - (a.begin() + i + 1)

/*
Approach Explanation:

We are given an array of integers and two values l and r.
We want to count the number of pairs (i, j) such that:
    0 <= i < j < n  and  l <= a[i] + a[j] <= r

Brute-force would be O(n^2), which is too slow.
So we optimize using sorting + binary search.

Key Idea:
Let’s fix a[i] and for every i, find how many values of a[j] (where j > i)
satisfy the condition: l <= a[i] + a[j] <= r
=> (l - a[i]) <= a[j] <= (r - a[i])

This means for every i:
- Count how many a[j] (j > i) satisfy a[j] <= (r - a[i])  → countR
- Count how many a[j] (j > i) satisfy a[j] <= (l - 1 - a[i])  → countL
- The number of valid pairs for this i is (countR - countL)

We do this using upper_bound (binary search) on the sorted array.
We loop from i = 0 to n-2 and for each i, use:
    upper_bound(a.begin() + i + 1, a.end(), x) - (a.begin() + i + 1)
to count elements a[j] where j > i and a[j] <= x

Finally, summing (countR - countL) for all i gives the total number of valid pairs.

Time Complexity: O(n log n) per test case
- Sorting takes O(n log n)
- Each iteration uses upper_bound → O(log n), total O(n log n)
This is efficient for n ≤ 2 * 10^5
*/


/*
Why this approach works better:

- Directly binary searching for pairs with sums in the range [l, r] is complicated 
  because we would need to simultaneously handle both lower and upper bounds in one step.

- However, counting pairs with sums less than or equal to a certain value (like r) 
  is straightforward by sorting the array and using binary search (upper_bound).

- Similarly, counting pairs with sums less than l (i.e., sums ≤ l - 1) is done in the same way.

- By calculating:
    countR = number of pairs with sums ≤ r
    countL = number of pairs with sums < l (i.e., sums ≤ l - 1)

- The number of pairs with sums in [l, r] is simply countR - countL.

- This subtraction technique avoids the complexity of checking both boundaries simultaneously
  and reduces the problem from potentially O(n^2) to O(n log n), making it efficient for large inputs.
*/


void solve()
{
    int n;
    cin >> n;
    ll l, r;
    cin >> l >> r;
    vl a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    ll smallerR = 0;
    rep(i, 0, n - 1)
    {
        ll num = r - a[i];
        auto index = upper_bound(a.begin() + i + 1, a.end(), num);
        smallerR += index - (a.begin() + i + 1);
    }

    ll smallerL = 0;
    rep(i, 0, n - 1)
    {
        ll num = l - 1 - a[i];
        auto index = upper_bound(a.begin() + i + 1, a.end(), num);
        smallerL += index - (a.begin() + i + 1);
    }

    cout << smallerR - smallerL << endl;
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
