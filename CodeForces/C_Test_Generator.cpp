#include "bits/stdc++.h"
#include <numeric>
#include <random>
using namespace std;
using ll = long long;

constexpr int MOD = 1'000'000'007;
constexpr int INF = 1'000'000'000;
constexpr ll LINF = (ll)4e18; // wider than 1e18 for safety

#define yes cout << "YES\n";
#define no cout << "NO\n";

// Bit helpers (careful with types)
// #define BITHELPER
#ifdef BITHELPER
static inline int setbits(unsigned int x) { return __builtin_popcount(x); }
static inline int setbitsll(unsigned long long x) { return __builtin_popcountll(x); }
static inline int leadingzero(unsigned int x) { return __builtin_clz(x); }
static inline int trailingzero(unsigned int x) { return __builtin_ctz(x); }
static inline int parity(unsigned int x) { return __builtin_parity(x); }
#endif

// #define COMBINATORICS
#ifdef COMBINATORICS
struct Combinatorics {
    static constexpr long long MOD = 1'000'000'007;
    vector<long long> fact, invFact;

    long long modpow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    Combinatorics(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n] = modpow(fact[n], MOD - 2);

        for (int i = n; i > 0; i--)
            invFact[i - 1] = invFact[i] * i % MOD;
    }

    long long factorial(int n) {
        return fact[n];
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n)
            return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    long long nPr(int n, int r) {
        if (r < 0 || r > n)
            return 0;
        return fact[n] * invFact[n - r] % MOD;
    }

    long long catalan(int n) {
        return nCr(2 * n, n) * modpow(n + 1, MOD - 2) % MOD;
    }

    long long starsBars(int k, int n) {
        return nCr(k + n - 1, n - 1);
    }
};
#endif

// #define SEGMENTTREE
#ifdef SEGMENTTREE
struct Node {
    long long val;

    Node(long long v = 0) {
        val = v;
    }
};

struct SegTree {
    int size;
    int real_size;
    vector<Node> tree;
    Node NEUTRAL = Node(0);

    Node merge(const Node &a, const Node &b) {
        return Node(a.val + b.val);
    }

    void init(int n) {
        real_size = n;
        size = 1;
        while (size < n)
            size <<= 1;
        tree.assign(2 * size, NEUTRAL);
    }

    void build(vector<int> &arr, int node, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)arr.size())
                tree[node] = Node(arr[lx]);
            return;
        }

        int mid = (lx + rx) / 2;
        build(arr, 2 * node + 1, lx, mid);
        build(arr, 2 * node + 2, mid, rx);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void build(vector<int> &arr) {
        build(arr, 0, 0, size);
    }

    void set(int i, int v, int node, int lx, int rx) {
        if (rx - lx == 1) {
            tree[node] = Node(v);
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid)
            set(i, v, 2 * node + 1, lx, mid);
        else
            set(i, v, 2 * node + 2, mid, rx);

        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    Node query(int l, int r, int node, int lx, int rx) {
        if (rx <= l || r <= lx)
            return NEUTRAL;
        if (l <= lx && rx <= r)
            return tree[node];

        int mid = (lx + rx) / 2;
        Node left = query(l, r, 2 * node + 1, lx, mid);
        Node right = query(l, r, 2 * node + 2, mid, rx);
        return merge(left, right);
    }

    Node query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};
#endif

int cal1(vector<ll> &a, ll n, ll m) {
    ll ans = 0;
    vector<ll> comp(61, 0);
    // start with m.

    for (int i = 0; i <= 60; i++) {
        if ((1LL << i) > m) {
            break;
        }
        if (!((1LL << i) & m)) {
            comp[i] += (n / m);
        }
    }
    ans += (n / m);
    n = n - m * (n / m);

    for (int i = 0; i < (int)a.size(); i++) {
        ll v = a[i];
        ll times = n / v;

        for (int j = 0; j <= 60; j++) {
            if ((1LL << j) > n) {
                break;
            }
            if ((1LL << j) & n) {
                if (comp[j] >= times) {
                    comp[j] -= times;
                    break;
                } else {
                    times -= comp[j];
                    comp[j] = 0;
                    ans += times;
                    for (int k = 0; k <= 60; k++) {
                        if ((1LL << k) > v) {
                            break;
                        } else {
                            if (!((1LL << k) & v)) {
                                comp[k] += times;
                            }
                        }
                    }
                    break;
                }
            }
        }
        n = n - v * times;
    }
    return ans;
}

int cal2(vector<ll> &a, ll n, ll m) {
    ll ans = 0;
    vector<ll> comp(61, 0);
    for (int i = 0; i < (int)a.size(); i++) {
        ll v = a[i];
        ll times = n / v;
        for (int j = 0; j <= 60; j++) {
            if ((1LL << j) > n) {
                break;
            }
            if ((1LL << j) & n) {
                if (comp[j] >= times) {
                    comp[j] -= times;
                    break;
                } else {
                    times -= comp[j];
                    comp[j] = 0;
                    ans += times;
                    for (int k = 0; k <= 60; k++) {
                        if ((1LL << k) > v) {
                            break;
                        } else {
                            if (!((1LL << k) & v)) {
                                comp[k] += times;
                            }
                        }
                    }
                    break;
                }
            }
        }
        n = n - v * times;
    }
    return ans;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    if (n % 2 == 1 && m % 2 == 0) {
        cout << "-1\n";
        return;
    }
    if (m == 1) {
        cout << n << "\n";
        return;
    }
    vector<ll> a;

    for (int i = 0; i <= 18; i++) {
        if (m & (1LL << i)) {
            a.push_back(1LL << i);
        }
    }
    sort(rbegin(a), rend(a));
    cout << min(cal1(a, n, m), cal2(a, n, m)) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}