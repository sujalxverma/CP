// VERMA 
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
#define zerobits(x) __builtin_ctzll(x)
#define setbits(x) __builtin_popcount(x)     // Count of set bits in int
#define setbitsll(x) __builtin_popcountll(x) // Count of set bits in long long
#define leadingzero(x) __builtin_clz(x)      // Leading zeros (int)
#define trailingzero(x) __builtin_ctz(x)     // Trailing zeros (int)
#define parity(x) __builtin_parity(x)        // 1 if odd number of set bits, else 0

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

inline bool prime(int num) {
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
inline int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

inline int lcm(int a, int b) {
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
inline int mod_pow(int base, int exp) {
    int result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (1LL * result * base) % MOD;
        base = (1LL * base * base) % MOD;
        exp /= 2;
    }
    return result;
}

template <typename T>
void printVector(const T &val) {
    cerr << val;
}

template <typename T>
void printVector(const vector<T> &v) {
    cerr << "[ ";
    for (const auto &elem : v) {
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
    ll n;
    cin >> n;
    vector<vl> g(n);                         // numbers for each person
    map<ll, vector<ll>> owner;               // number -> list of people with it
    rep(i, 0, n) {
        ll m;
        cin >> m;
        rep(j, 0, m) {
            ll d;
            cin >> d;
            g[i].push_back(d);
            owner[d].push_back(i);
        }
    }

    // DSU for people
    vi par(n);
    rep(i, 0, n) par[i] = i;
    function<int(int)> find = [&](int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    };
    auto unite = [&](int x, int y) {
        x = find(x); y = find(y);
        if (x != y) par[x] = y;
    };

    vector<tuple<int,int,ll>> edges; // (p, q, r)

    for (auto &kv : owner) {
        const auto &people = kv.second;
        if (people.size() < 2) continue;
        int root = people[0];
        rep(j, 1, people.size()) {
            int a = find(root), b = find(people[j]);
            if (a != b) {
                unite(a, b);
                edges.push_back({root + 1, people[j] + 1, kv.first});
            }
        }
    }
    // After all unions, check if there’s one component and n-1 edges.
    set<int> comps;
    rep(i, 0, n) comps.insert(find(i));
    if (comps.size() > 1 || edges.size() != n - 1) {
        cout << "impossible\n";
        return;
    }
    for (auto &it : edges) {
        int p, q; ll r;
        tie(p, q, r) = it;
        cout << p << " " << q << " " << r << "\n";
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
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
