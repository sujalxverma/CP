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
    1. This problem solved after applying brute force for smaller constraints, and then fincding patterns.
*/


pair<int, int> problem(int a, int b)
{
    int ans = INT_MAX;
    int result = -1;
    for (int i = 1; i <= min(a, b); i++)
    {
        if (lcm(a, i) - gcd(b, i) < ans)
        {
            result = i;
            ans = lcm(a, i) - gcd(b, i);
        }
    }
    return {ans, result};
}
void solve()
{
    int a, b;
    cin >> a >> b;
    // pair<int, int> ans = problem(a, b);
    // cout << ans.first << " " << ans.second << endl;

    // Solution
    if (b % a == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (gcd(a, b) == 1)
    {
        cout << a - 1 << endl;
        return;
    }
    if (a > b)
    {
        if (prime(a))
        {
            cout << a - 1 << endl;
            return;
        }
        cout<< max(a,b) - gcd(a,b)  <<endl;
    }
    else
    {
        if (prime(a) || prime(b))
        {
            cout << a - 1 << endl;
            return;
        }
        else{
            cout<<min(a,b) - gcd(a,b)<<endl;
        }
    }
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
