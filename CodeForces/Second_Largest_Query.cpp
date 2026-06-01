// // VERMA
// #include "bits/stdc++.h"
// #include <chrono>
// #include <numeric>
// #include <random>
// using namespace std;

// using ll = long long;
// using ld = long double;

// std::mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// constexpr int MOD = 1'000'000'007;
// constexpr int INF = 1'000'000'000;
// constexpr ll LINF = (ll)4e18;

// #define yes cout << "YES\n"
// #define no cout << "NO\n"
// static inline void fastio() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
// }

// // #define BITHELPER
// #ifdef BITHELPER
// static inline int setbits(unsigned int x) { return __builtin_popcount(x); }
// static inline int setbitsll(unsigned long long x) { return __builtin_popcountll(x); }
// static inline int leadingzero(unsigned int x) { return __builtin_clz(x); }
// static inline int trailingzero(unsigned int x) { return __builtin_ctz(x); }
// static inline int parity(unsigned int x) { return __builtin_parity(x); }
// #endif

// // #define MATHS
// #ifdef MATHS
// int gcd(int a, int b) {
//     return b == 0 ? a : gcd(b, a % b);
// }

// static inline ll mod_pow(ll base, ll exp, ll mod) {
//     ll res = 1;
//     base %= mod;
//     while (exp > 0) {
//         if (exp & 1)
//             res = (res * base) % mod;
//         base = (base * base) % mod;
//         exp >>= 1;
//     }
//     return res;
// }
// #endif

// #define SEGMENTTREE
// #ifdef SEGMENTTREE
// struct Node {
//     int first, second, cntf, cnts;
//     Node(int f, int s, int c1, int c2) {
//         first = f;
//         second = s;
//         cntf = c1;
//         cnts = c2;
//     }
// };

// struct SegTree {
//     int size, real_size;
//     vector<Node> tree;
//     Node NEUTRAL = Node(-1e9, -1e9, 0, 0);

//     Node merge(const Node &a, const Node &b) {
//         if (a.first > b.first) {
//             if (a.second > b.first)
//                 return Node(a.first, a.second, a.cntf, a.cnts);
//             else if (a.second < b.first)
//                 return Node(a.first, b.first, a.cntf, b.cntf);
//             else
//                 return Node(a.first, a.second, a.cntf, a.cnts + b.cntf);
//         }

//         else if (b.first > a.first) {
//             if (b.second > a.first)
//                 return Node(b.first, b.second, b.cntf, b.cnts);
//             else if (b.second < a.first)
//                 return Node(b.first, a.first, b.cntf, a.cntf);
//             else
//                 return Node(b.first, b.second, b.cntf, b.cnts + a.cntf);
//         }

//         else { // a.first == b.first
//             if (a.second > b.second)
//                 return Node(a.first, a.second, a.cntf + b.cntf, a.cnts);

//             else if (b.second > a.second)
//                 return Node(a.first, b.second, a.cntf + b.cntf, b.cnts);

//             else
//                 return Node(a.first, a.second,
//                             a.cntf + b.cntf,
//                             a.cnts + b.cnts);
//         }
//     }

//     void init(int n) {
//         real_size = n;
//         size = 1;
//         while (size < n)
//             size <<= 1;
//         tree.assign(2 * size, NEUTRAL);
//     }

//     void build(vector<int> &arr, int node, int lx, int rx) {
//         if (rx - lx == 1) {
//             if (lx < (int)arr.size())
//                 tree[node] = Node(arr[lx], 0, 1, 0);
//             return;
//         }
//         int mid = (lx + rx) / 2;
//         build(arr, 2 * node + 1, lx, mid);
//         build(arr, 2 * node + 2, mid, rx);
//         tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
//     }

//     void build(vector<int> &arr) { build(arr, 0, 0, size); }

//     void set(int i, int v, int node, int lx, int rx) {
//         if (rx - lx == 1) {
//             tree[node] = Node(v, 0, 1, 0);
//             return;
//         }
//         int mid = (lx + rx) / 2;
//         if (i < mid)
//             set(i, v, 2 * node + 1, lx, mid);
//         else
//             set(i, v, 2 * node + 2, mid, rx);
//         tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
//     }

//     void set(int i, int v) { set(i, v, 0, 0, size); }

//     Node query(int l, int r, int node, int lx, int rx) {
//         if (rx <= l || r <= lx)
//             return NEUTRAL;
//         if (l <= lx && rx <= r)
//             return tree[node];
//         int mid = (lx + rx) / 2;
//         return merge(query(l, r, 2 * node + 1, lx, mid),
//                      query(l, r, 2 * node + 2, mid, rx));
//     }

//     Node query(int l, int r) { return query(l, r, 0, 0, size); }
// };
// #endif

// void solve() {
//     int n, q;
//     cin >> n >> q;
//     vector<int> a(n);
//     for (auto &X : a) {
//         cin >> X;
//     }
//     SegTree st;
//     st.init(n);
//     st.build(a);
//     while (q--) {
//         int x;
//         cin >> x;
//         if (x == 1) {
//             int l, v;
//             cin >> l >> v;
//             st.set(l - 1, v);
//         } else {
//             int l, r;
//             cin >> l >> r;
//             auto ans = st.query(l - 1, r);
//             cout << ans.cnts << "\n";
//         }
//     }
// }

// int main() {
//     fastio();
//     auto begin = chrono::steady_clock::now();

//     int t = 1;
//     // cin >> t;
//     while (t--) {
//         solve();
//     }

//     auto end = chrono::steady_clock::now();
//     auto ns = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
//     // cerr << "Time measured: " << (ns * 1e-9) << " seconds.\n";
//     return 0;
// }
