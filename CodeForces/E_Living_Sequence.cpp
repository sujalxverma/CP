// VERMA
#include "bits/stdc++.h"
#include <numeric>
#include <random>
using namespace std;
using ll = long long;

constexpr int MOD = 1'000'000'007;
constexpr int INF = 1'000'000'000;
constexpr ll LINF = (ll)4e18;

#define yes cout << "YES\n";
#define no cout << "NO\n";

// Bit helpers
// #define BITHELPER
#ifdef BITHELPER
static inline int setbits(unsigned int x) { return __builtin_popcount(x); }
static inline int setbitsll(unsigned long long x) { return __builtin_popcountll(x); }
static inline int leadingzero(unsigned int x) { return __builtin_clz(x); }
static inline int trailingzero(unsigned int x) { return __builtin_ctz(x); }
static inline int parity(unsigned int x) { return __builtin_parity(x); }
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

vector<ll> pre() {
    vector<ll> dp(16, 0);
    dp[1] = 8;
    for (int i = 2; i <= 15; i++) {
        dp[i] = dp[i - 1] * 9;
    }
    vector<ll> p(16, 0);
    for (int i = 1; i <= 15; i++) {
        p[i] = p[i - 1] + dp[i];
    }
    return p;
}
void solve() {
    long long n;
    cin >> n;

    string ans;

    while (n > 0) {
        int d = n % 9;
        n /= 9;

        if (d >= 4)
            d++;

        ans.push_back(char('0' + d));
    }

    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}
// void solve() {
//     ll n;
//     cin >> n;
//     // can use binary search to get number of digits.
//     int idx = -1;
//     vector<ll> dp = pre();
//     for (int i = 1; i <= 15; i++) {
//         if (dp[i] >= n) {
//             idx = i;
//             break;
//         }
//     }
//     ll val = n - dp[idx - 1];
//     vector<ll> nums(idx + 1);

//     for (int i = 1; i <= idx; i++) {
//         ll vk = 0;
//         if (i == 1) {
//             ll nine = 9;
//             for (int k = 1; k <= (idx - 1); k++) {
//                 nine *= 9;
//             }
//             for (ll j = 1; j <= 9; j++) {

//                 if (j == 4) {
//                     // skip
//                 } else {
//                     nine /= 9;
//                     ll v = j * (nine);
//                     if (v <= val) {
//                         nums[i] = j;
//                         vk = v;
//                     } else {
//                         val -= vk;
//                         break;
//                     }
//                 }
//             }
//         } else {
//             ll nine = 9;
//             for (int k = 1; k <= (idx - 1); k++) {
//                 nine *= 9;
//             }
//             for (ll j = 0; j <= 9; j++) {
//                 if (j == 4) {
//                     // skip
//                 } else {
//                     nine /= 9;
//                     ll v = j * (nine);
//                     if (v <= val) {
//                         nums[i] = j;
//                         vk = v;
//                     } else {
//                         val -= vk;
//                         break;
//                     }
//                 }
//             }
//         }
//     }
//     for (int i = 1; i <= idx; i++) {
//         cout << nums[i];
//     }
//     cout << "\n";
// }

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