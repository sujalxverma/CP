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

const int MOD = 1e9;
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

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s; // FIXED

    // 1. Replace ? next to o with .
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] == '?' && (s[i - 1] == 'o' || s[i + 1] == 'o'))
        {
            s[i] = '.';
        }
    }
    if (s[0] == '?' && s[1] == 'o')
        s[0] = '.';
    if (s[n - 1] == '?' && s[n - 2] == 'o')
        s[n - 1] = '.';

    // 2. Count current o's
    int count_o = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o')
            count_o++; // FIXED
    }

    // 3. Greedily simulate placement
    string temp = s;
    int max_o = count_o;
    for (int i = 0; i < n; i++)
    {
        if (temp[i] == '?')
        {
            if ((i == 0 || temp[i - 1] != 'o') && (i == n - 1 || temp[i + 1] != 'o'))
            {
                temp[i] = 'o';
                max_o++;
            }
            else
            {
                temp[i] = '.';
            }
        }
    }

    // Case 1
    if (count_o == k)
    {
        for (char &c : s)
            if (c == '?')
                c = '.';
        cout << s << endl;
        return;
    }

    // Case 2
    if (max_o == k)
    {
        string res(n, '?');
        for (int i = 0; i < n;)
        {
            if (s[i] != '?')
            {
                res[i] = s[i];
                i++;
                continue;
            }
            int j = i;
            while (j < n && s[j] == '?')
                j++;
            int len = j - i;

            vector<char> p1(len), p2(len);
            for (int l = 0; l < len; l++)
            {
                if (l % 2 == 0)
                {
                    p1[l] = 'o';
                    p2[l] = '.';
                }
                else
                {
                    p1[l] = '.';
                    p2[l] = 'o';
                }
            }
            for (int l = 0; l < len; l++)
            {
                if (len % 2 == 1)
                {
                    res[i + l] = p1[l];
                }
                else
                {
                    res[i + l] = (p1[l] == p2[l]) ? p1[l] : '?';
                }
            }
            i = j;
        }
        cout << res << endl;
        return;
    }

    // Case 3
    string res(n, '?');
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o')
            res[i] = 'o';
        else if (s[i] == '.')
            res[i] = '.';
        else
        {
            if ((i > 0 && s[i - 1] == 'o') || (i < n - 1 && s[i + 1] == 'o'))
            {
                res[i] = '.';
            }
            else
            {
                res[i] = '?';
            }
        }
    }
    cout << res << endl;
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
