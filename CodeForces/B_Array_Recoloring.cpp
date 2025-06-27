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
- Read 'n' and 'k', and input array 'a' with 1-based indexing.
- Special case for k == 1:
   - Pick the better of the first or last element.
   - Add the next largest element from the sorted list.
- General case for k > 1:
   - Sort the array in descending order (ignoring a[0]).
   - Sum the top (k + 1) elements to get the maximum possible sum.
- Output the result accordingly.

Assumption:
- Problem likely allows choosing up to (k + 1) elements with constraints.
*/

void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vl a(n + 1);
    rep(i, 1, n + 1)
    {
        cin >> a[i];
    }
    ll elem = 0;
    if (k == 1)
    {
        elem = max(a[01], a[n]);
    }
    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());

    ll sum = 0;

    if (k == 1)
    {
        if (a[1] == elem)
        {
            cout << elem + a[2] << endl;
            return;
        }
        cout << elem + a[1] << endl;
        return;
    }

    rep(i, 1, n + 1)
    {
        if (i <= k + 1)
        {
            sum += a[i];
        }
    }
    cout << sum << endl;
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
