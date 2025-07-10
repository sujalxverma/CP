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

//------------------------------------------------------------------------------------------
//                  Here you go

/*
Approach:
---------
This program uses a recursive backtracking approach to solve the 
"Apple Division" problem. The goal is to divide the apples into two
groups such that the absolute difference between the total weights
of the groups is minimized.

At each step, the recursive function `recurse_apples` considers two
choices for the current apple:
    1. Add the current apple's weight to group 1 (sum1)
    2. Add the current apple's weight to group 2 (sum2)

The recursion continues until all apples are considered.
At the base case (index == n), it returns the absolute difference 
between sum1 and sum2.

The overall minimum difference across all such groupings is found 
by taking the minimum of all possible recursive outcomes.

This brute-force method has time complexity O(2^n), since each apple
can go into either group, and there are n apples.
*/


vl a(1e6);
ll diff(ll index , ll sum1 , ll sum2,ll n){
    if(index == n){
        return abs(sum1 - sum2);
    }
    return min(diff(index+1,sum1 + a[index] , sum2 , n) , diff(index+1 , sum1 , sum2 + a[index] , n));
}


void solve() {
    ll n;
    cin >> n;
    a.resize(n);

    rep2(i,0,n) cin >> a[i];

    ll sum1 = 0;
    ll sum2 = 0;

    cout<<diff(0,0,0,n);

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
