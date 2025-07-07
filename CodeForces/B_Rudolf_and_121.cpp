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
---------
We are allowed to perform an operation at any index i (2 ≤ i ≤ n-1) that reduces:
    a[i-1] by 1,
    a[i]   by 2,
    a[i+1] by 1

Key Observations:
- Each operation reduces the total sum of the array by 4.
  So, the total sum must be divisible by 4; otherwise, it's impossible.

- To make all elements zero, we can process the array from left to right:
    At each index i (0 to n - 3), we apply the operation at index i+1 enough times
    to make a[i] become 0.

- For that to be valid:
    - a[i+1] must be at least 2 * a[i]
    - a[i+2] must be at least a[i]

- We apply the operation a[i] times and update the three elements accordingly.

- After the loop, we check if the last two elements (a[n-2] and a[n-1]) are zero.
  If they are, the array has been reduced to all zeros.

Time Complexity:
- O(n) per test case

Space Complexity:
- O(n) for array storage
*/

/*
    for a[i] to be 0, then a[i+1] should be atleast 2*a[i], then only operation can be used.
*/
void solve()
{
    int n;
    cin >> n;
    vl a(n);
    rep(i, 0, n) cin >> a[i];
   
    for(int i = 0 ; i < n-2 ; i++){
        if(a[i] < 0){
            no;
            return ;
        }
        ll diff = a[i];
        a[i] -= diff;
        a[i+1] -= (2*diff);
        a[i+2] -= diff;
    }

    if(a[n-1] != 0 || a[n-2] != 0){
        no;
        return ;
    }yes;

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
