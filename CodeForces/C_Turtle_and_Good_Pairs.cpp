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
  To maximize the number of good pairs:
  1. A good pair is either:
     - s[i] == s[j], OR
     - A "pleasant pair" (see conditions below).

  2. A "pleasant pair" (i, j) exists if:
     - There exists k such that i ≤ k < j, AND
     - s[k] ≠ s[k+1], AND
     - s[k] ≠ s[i] OR s[k+1] ≠ s[j]

  3. Our goal is to reorder the string to **maximize** the number of good pairs.
     - Repeating characters help because s[i] == s[j] is trivially a good pair.
     - Thus, grouping same characters (like aaaabbbb) is good for count of (s[i] == s[j]).

  4. However, we also want to avoid long runs of the same character (like aaaa...),
     because they reduce the number of **pleasant pairs** due to lack of variation.

  Strategy:
  - Sort the string first to group same characters (ensures maximum s[i] == s[j] pairs).
  - Then, interleave smallest and largest characters alternately from both ends.
    This introduces variation in neighboring characters and helps fulfill the
    s[k] ≠ s[k+1] condition, thereby increasing pleasant pairs.

  Result:
  - This interleaving approach balances between identical character pairs and variation,
    aiming to maximize total number of good pairs.
*/

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        cout << s[i] << "";
        cout << s[j] << "";
        i++;
        j--;
    }
    if (!even(n))
    {
        cout << s[j];
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
