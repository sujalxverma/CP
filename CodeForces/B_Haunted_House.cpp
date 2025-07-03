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
#define line cout << "\n"
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
    1. First, reverse the string to simplify the problem. This way, bringing '0's to the front in the original string
       becomes equivalent to moving them towards the end after reversing.

    2. Count the number of '0's in the reversed string and store their positions (indices) in an array `index`.
       This helps us efficiently track where the zeroes are located.

    3. For each k from 1 to the number of zeroes, we want to bring the first k zeroes to the first k positions
       (i.e., positions 0 to k-1) using the **minimum number of adjacent swaps**.

       The minimum number of adjacent swaps required to move the i-th '0' to position i is:
           index[i] - i

       So, the total number of swaps to bring the first k zeroes to the front is:
           sum_{i=0 to k-1} (index[i] - i)

    4. For all values of k > number of zeroes, it is impossible to bring more than that many zeroes to the front,
       so we print -1 for those cases.
*/


// int swaps(vector<int> &index, int bit, string s)
// {
//     int total = 0;
//     rep(i, 0, bit)
//     {
//         int idx = lower_bound(index.begin(),index.end(),i) - index.begin(); // you got index at or above i.
//         if(idx >= index.size()) break; // means, if idx i got which is not present in index. here, idx is index at which next 0 is present in index.
//        int actualIdx = index[idx];
//         swap(s[i], s[actualIdx]);
//         total += actualIdx - i;
//     }
//     return total;
// }  I thought if using this function , but it did not work well.

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    ll zero = 0;
    rep2(i, 0, n)
    {
        if (s[i] == '0')
            zero++; // count zero bits.
    }

    vector<ll> index;
    rep2(i, 0, n)
    {
        if (s[i] == '0')
        {
            index.push_back(i); // stores index of 0s.
        }
    }
    ll ans = 0;
    rep2(i, 0, zero )
    {
        // int ans = swaps(index,i,s);
         ans += (index[i] - i);
        cout<<ans<<" ";
    }
    rep2(i, zero, n)
    {
        cout << -1 << " ";
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
