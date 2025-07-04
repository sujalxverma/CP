#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rep2(i, a, b) for (long long i = a; i < b; i++)
typedef unordered_map<int, int> umap;
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
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

const ll MOD = 1e9 + 7;

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
    1. we start x from 0 to n.
    2. and say 'x', at most x people are liar.
    3. then check if a[j] inside loop , will check a[j]> x, it means they are liar.
    4. now if liar == x, it means our assumption is true, then return x.
    5. if not at the end return -1.
*/

/*
Assume that there are exactly x liars in the group (for each x from 0 to n).

For each person:
- If they say a[i] > x, then they're lying,
  because according to our assumption, there are only x liars — and they are claiming more.
- So anyone who says a[i] > x must be one of the liars.

Count how many such people there are. Call that number 'liars'.

If liars == x, then our assumption is self-consistent:
- The exact number of people whose statements contradict the assumption
  is equal to the number of liars we assumed.

✅ So, this assumption is valid — print x and stop.

If no such x works from 0 to n, then the statements are contradictory — print -1.
*/

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int x = 0; x <= n; x++) {
        int liars = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] > x) {
                liars++;
            }
        }
        if(liars == x) {
            cout << x << endl;
            return ;
        }
    }
    cout << -1 << endl;


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
