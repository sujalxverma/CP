// VERMA
#include "bits/stdc++.h"
using namespace std;
#include <random>
#include <chrono>
#include <numeric>

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<long long>;

std::mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int MOD = 1'000'000'007;
constexpr int INF = 1'000'000'000;
constexpr ll LINF = (ll)4e18;

static inline void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

#ifndef ONLINE_JUDGE
template <typename T>
void _pr(const T &v) { cerr << v; }
template <typename T>
void _pr(const vector<T> &v)
{
    cerr << "[ ";
    for (auto &e : v)
    {
        _pr(e);
        cerr << ' ';
    }
    cerr << "]";
}
#define debug(x)             \
    do                       \
    {                        \
        cerr << #x << " = "; \
        _pr(x);              \
        cerr << '\n';        \
    } while (0)
#else
#define debug(x) ((void)0)
#endif

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < n; j++)
        cin >> b[j];

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int val = a[i];
        for (int j = 2; j * j <= val; j++)
        {
            if (val % j == 0)
            {
                mp[j]++;
                while (val % j == 0)
                    val /= j;
            }
        }
        if (val > 1)
            mp[val]++;
    }

    for (auto &[prime, count] : mp)
    {
        if (prime == 1)
            continue;
        if (count >= 2)
        {
            cout << 0 << "\n";
            return;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int val = a[i] + 1;
        for (int j = 2; j * j <= val; j++)
        {
            if (val % j == 0)
            {
                if (mp.count(j))
                {
                    cout << 1 << "\n";
                    return;
                }
                while (val % j == 0)
                    val /= j;
            }
        }
        if (val > 1 && mp.count(val))
        {
            cout << 1 << "\n";
            return;
        }
    }

    cout << 2 << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto begin = chrono::steady_clock::now();

    int T = 1;
    if (!(cin >> T))
        return 0;
    while (T--)
        solve();

    auto end = chrono::steady_clock::now();
    auto ns = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
    cerr << "Time measured: " << (ns * 1e-9) << " seconds.\n";
    return 0;
}
