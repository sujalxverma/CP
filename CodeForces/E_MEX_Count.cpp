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
Problem Statement Summary:
---------------------------
You're given an array of non-negative integers `a` of size `n`.
For each `k` in the range [0, n], determine how many different values
of MEX (Minimum EXcluded number) can be achieved by removing exactly `k` elements from the array.

MEX of an array is the smallest non-negative integer not present in the array.

Approach Explanation:
---------------------

1. Frequency Mapping:
   - First, we count the frequency of each number in the array using a `map<int, int> mp`
     so that keys (elements) are automatically stored in sorted order.

2. Initial MEX Computation:
   - Start from 0 and increase until we find the smallest number not in the array.
     This gives the initial MEX of the full array.
   - For each element from 0 up to (but not including) the MEX, we record how many times it appears.
     This helps later in calculating how many removals are needed to "break" continuity of MEX.

3. Frequency of Frequencies:
   - Store how many elements (less than the MEX) have the same frequency.
   - This helps us simulate how removing a certain number of elements can create or preserve valid MEX values.

4. Result Vector `ans` of Size `n + 1`:
   - `ans[k]` will store how many distinct MEX values are possible after removing exactly `k` elements.

5. Backward Filling for MEX Values:
   - Starting from `ans[n] = 1` (full array — only one MEX possible),
     backfill last `mex` entries using `ans[i] = ans[i+1] + 1`:
     This is because each MEX from `0` to `MEX-1` can be formed by removing increasing numbers of elements.

6. Forward Filling for Lower k (removals):
   - For smaller `k`, simulate how many distinct MEX values can be achieved using frequency breakdown.
   - For example, if some numbers appeared more than once, you might need multiple removals to fully eliminate that number.
   - `ans[i] = ans[i-1] + frq[i]` adds potential new MEX values that become reachable after `i` removals.

7. Edge Case Handling:
   - Ensure that `ans[0] = 1` since there's always exactly one MEX for the full array.
   - Stop updating `ans[i]` once a value has been set during backward fill, to avoid overwriting.

8. Output:
   - For each test case, print the resulting `ans` array of size `n + 1`.

Time and Space Complexity:
---------------------------
- Time per test case: O(n + log n) due to map operations and single-pass processing.
- Space: O(n) for maps and result array.
- Efficient for total `n` ≤ 2 * 10^5 across all test cases.

This solution leverages the sorted nature of `map` and efficient bookkeeping of frequencies
to compute the count of possible MEX values for every `k` in a single forward/backward sweep.
*/

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    // use map not unordered, to store in sorted manner.
    map<int, int> mp; // stores frequency of element.
    rep(i, 0, n)
    {
        mp[a[i]]++;
    }
    // now you need store frquency of numbers on the basis of duplicacy.
    int mex = 0;
    map<int, int> frq;
    for (auto it : mp)
    {
        // it.first -> this number i want to be MEX, it.second -> after removing this amount of numbers i will get it.first as MEX.
        if (it.first == mex)
        {
            mex++;
            frq[it.second]++;
        }
    }
    vi ans(n + 1, 0);
    ans[n] = 1;
    for (int i = n - 1; i > n - mex; i--)
    {
        ans[i] = ans[i + 1] + 1; // last elements will be in order :  _ _ _ _ _ _ MEX , MEX-1, MEX-2, MEX-3 ... 1  , it is pattern that forms.
    }
    ans[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (ans[i])
            break;

        ans[i] = ans[i - 1] + frq[i];
    }

    for (auto &x : ans)
        cout << x << " ";
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
