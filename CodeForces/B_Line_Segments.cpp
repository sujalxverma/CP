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
#define line cout << "\n"
#define contains(vec, x) (std::find((vec).begin(), (vec).end(), (x)) != (vec).end())
#define containsBS(vec, x) (std::binary_search((vec).begin(), (vec).end(), (x)))
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

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

inline int mod_add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
inline int mod_sub(int a, int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
inline int mod_mul(int a, int b) { return ((1LL * a % MOD) * (b % MOD)) % MOD; }
inline int mod_pow(int base, int exp)
{
    int result = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (1LL * result * base) % MOD;
        base = (1LL * base * base) % MOD;
        exp /= 2;
    }
    return result;
}

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
 * Explanation of minimum reachable distance (d_min):
 *
 * Given a sequence of steps with fixed lengths a[i], you want to determine
 * the minimum possible net displacement from the starting point after
 * taking all steps in any directions.
 *
 * Intuition:
 * Each step is a vector of length a[i] with a freely chosen direction.
 * The final position is the vector sum of all these steps.
 *
 * Definitions:
 *   L = max(a[i])           // length of the largest step
 *   S = sum of all a[i]     // total length of all steps
 *
 * The minimum net distance d_min after all moves satisfies:
 *
 *   d_min = max(0, 2 * L - S)
 *
 * Why?
 * - If the largest step L is less than or equal to the sum of the others (S - L),
 *   the vectors can be arranged to form a closed polygon, so minimum distance is 0.
 * - If L is greater, the largest step cannot be fully canceled by others,
 *   so minimum distance is the leftover: L - (S - L) = 2L - S.
 *
 * This formula is a direct consequence of the triangle inequality in vector addition.
 * It helps check if a target point is reachable given the steps.
 */

ll euclideanDistance(double x1, double y1, double x2, double y2)
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

void solve()
{
    ll n;
    ;
    cin >> n;
    ll px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    vl a(n);
    ll maxi = 0;
    rep(i, 0, n)
    {
        cin >> a[i];
        maxi = max(a[i], maxi);
    }
    ll sum = 0;
    rep(i, 0, n)
    {
        sum += a[i];
    }

    ll d = (px - qx) * (px - qx) + (py - qy) * (py - qy);
    if ((d) > sum * sum)
    {
        no;
        return;
    }
    ll mini = max(0ll, 2 * maxi - sum);
    if (d < mini * mini)  // it means i can never reach point (qx,qy).
    {
        no;
        return;
    }
    yes;
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
