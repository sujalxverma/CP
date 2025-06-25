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

// For each position i where s[i] == c, find the nearest 'g' that appears after i.
// Since the string is circular, if no 'g' is found after i, wrap around to the first 'g'.
// We precompute all positions of 'g' in a sorted vector and use lower_bound to find the nearest 'g' in O(log n) time.
// This reduces the overall time complexity from O(n^2) to O(n log n).

void solve() {
    int n;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;

    if (c == 'g') {
        cout << 0 << endl;
        return;
    }

    vi g_positions;
    rep(i, 0, n) {
        if (s[i] == 'g') g_positions.push_back(i);
    }

    int max_dist = 0;
    rep(i, 0, n) {
        if (s[i] == c) {
            /*
            lower_bound works on value not index, 
            here we get that index value stored in the vector for which position g is greater than c index. 
            */
           // *it gives the value at which neaarest g is present.
            auto it = lower_bound(g_positions.begin(), g_positions.end(), i);
            if (it == g_positions.end()) {
                max_dist = max(max_dist, g_positions[0] + n - i);
            } else {
                max_dist = max(max_dist, *it - i);
            }
        }
    }

    cout << max_dist << endl;
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
