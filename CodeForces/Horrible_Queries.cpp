#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
using ll = long long;
// Lazy Propogation Segment Tree.
// sum query for range and updatation.
struct Node {
  long long val; // stores sum of segment

  Node(long long v = 0) { val = v; }
};

struct SegTree {
  ll size;
  ll real_size;
  vector<Node> tree;
  vector<char> marked;
  vector<long long> lazy; // lazy array for range add
  Node NEUTRAL = Node(0);

  // merge function (sum)
  Node merge(const Node &a, const Node &b) { return Node(a.val + b.val); }

  void init(ll n) {
    real_size = n;
    size = 1;
    while (size < n)
      size <<= 1;

    tree.assign(2 * size, NEUTRAL);
    lazy.assign(2 * size, 0LL);
    marked.assign(2 * size, false); // false -> no pending operation
  }

  // build
  void build(vector<ll> &arr, ll node, ll lx, ll rx) {
    if (rx - lx == 1) {
      if (lx < (ll)arr.size())
        tree[node] = Node(arr[lx]);
      return;
    }

    ll mid = (lx + rx) / 2;
    build(arr, 2 * node + 1, lx, mid);
    build(arr, 2 * node + 2, mid, rx);
    tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
  }

  void build(vector<ll> &arr) { build(arr, 0, 0, size); }

  // apply lazy value to node
  void apply(ll node, ll lx, ll rx, long long v) {
    tree[node].val += (rx - lx) * v; // update segment sum
    lazy[node] += v;
    marked[node] = true;
  }

  // push lazy to children
  void push(ll node, ll lx, ll rx) {
    if (!marked[node] || rx - lx == 1)
      return;

    ll mid = (lx + rx) / 2;

    apply(2 * node + 1, lx, mid, lazy[node]);
    apply(2 * node + 2, mid, rx, lazy[node]);

    lazy[node] = 0;
    marked[node] = false;
  }

  // range add [l, r)
  void update(ll l, ll r, long long v, ll node, ll lx, ll rx) {
    if (rx <= l || r <= lx)
      return;

    if (l <= lx && rx <= r) {
      apply(node, lx, rx, v);
      return;
    }

    push(node, lx, rx);

    ll mid = (lx + rx) / 2;
    update(l, r, v, 2 * node + 1, lx, mid);
    update(l, r, v, 2 * node + 2, mid, rx);

    tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
  }

  void update(ll l, ll r, long long v) { update(l, r, v, 0, 0, size); }

  // range query [l, r)
  Node query(ll l, ll r, ll node, ll lx, ll rx) {
    if (rx <= l || r <= lx)
      return NEUTRAL;

    if (l <= lx && rx <= r)
      return tree[node];

    push(node, lx, rx);

    ll mid = (lx + rx) / 2;
    Node left = query(l, r, 2 * node + 1, lx, mid);
    Node right = query(l, r, 2 * node + 2, mid, rx);

    return merge(left, right);
  }

  Node query(ll l, ll r) { return query(l, r, 0, 0, size); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto start = high_resolution_clock::now();

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int q;
    cin >> q;
    // vector<ll> a(n, 0);
    SegTree st;
    st.init(n);
    // st.build(a);
    while (q--) {
      int type;
      cin >> type;
      if (type == 0) {
        ll l, r, v;
        cin >> l >> r >> v;
        l--;

        st.update(l, r, v);
      } else {
        ll l, r;
        cin >> l >> r;
        l--;

        cout << st.query(l, r).val << "\n";
      }
    }
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << "Time taken: " << duration.count() << " microseconds\n";

  return 0;
}