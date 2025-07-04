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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    unordered_map<int, int> freqB, freqA;
    for (int x : b) freqB[x]++;

    int matchedCount = 0;
    // initialize first window
    for (int i = 0; i < m; i++) {
        freqA[a[i]]++;
        if (freqA[a[i]] <= freqB[a[i]])
            matchedCount++;
    }

    int ans = (matchedCount >= k) ? 1 : 0;
    for (int i = m; i < n; i++) {
        // remove left element
        int leftVal = a[i - m];
        if (freqA[leftVal] <= freqB[leftVal])
            matchedCount--;
        freqA[leftVal]--;

        // add new element
        int rightVal = a[i];
        freqA[rightVal]++;
        if (freqA[rightVal] <= freqB[rightVal])
            matchedCount++;

        if (matchedCount >= k)
            ans++;
    }

    cout << ans << "\n";
}

// void solve()
// {
//     int n, m;
//     size_t k;
//     cin >> n >> m >> k;
//     vector<int> a(n);
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> a[i];
//     }
//     multiset<int> todo, done, extra;
//     for (int j = 0; j < m; ++j)
//     {
//         int b;
//         cin >> b;
//         todo.insert(b);
//     }
//     for (int j = 0; j < m; ++j)
//     {
//         if (todo.find(a[j]) != todo.end())
//         {
//             todo.erase(todo.find(a[j]));
//             done.insert(a[j]);
//         }
//         else
//         {
//             extra.insert(a[j]);
//         }
//     }
//     int ans = (done.size() >= k);
//     for (int r = m; r < n; ++r)
//     {
//         int old = a[r - m];
//         if (extra.find(old) != extra.end()) {
//             extra.erase(extra.find(old));
//         } else
//         if (done.find(old) != done.end())
//         {
//             done.erase(done.find(old));
//             todo.insert(old);
//         }
//         if (todo.find(a[r]) != todo.end())
//         {
//             todo.erase(todo.find(a[r]));
//             done.insert(a[r]);
//         }
//         else
//         {
//             extra.insert(a[r]);
//         }
//         ans += (done.size() >= k);
//     }
//     cout << ans << '\n';
// }

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