// VERMA
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

// #define SEGMENTTREE
#ifdef SEGMENTTREE
struct Node
{
	long long val; // change type as needed

	Node(long long v = 0)
	{
		val = v;
	}
};

struct SegTree
{
	int size;
	int real_size;
	vector<Node> tree;
	Node NEUTRAL = Node(0); // neutral element for merge

	// merge two nodes
	// can be modified.
	Node merge(const Node &a, const Node &b)
	{
		return Node(a.val + b.val); // example: sum segment tree
	}

	// initialize tree
	void init(int n)
	{
		real_size = n;
		size = 1;
		while (size < n)
			size <<= 1;
		tree.assign(2 * size, NEUTRAL);
	}

	// build from array
	void build(vector<int> &arr, int node, int lx, int rx)
	{
		if (rx - lx == 1)
		{
			if (lx < (int)arr.size())
				tree[node] = Node(arr[lx]);
			return;
		}

		int mid = (lx + rx) / 2;
		build(arr, 2 * node + 1, lx, mid);
		build(arr, 2 * node + 2, mid, rx);
		tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
	}

	void build(vector<int> &arr)
	{
		build(arr, 0, 0, size);
	}

	// point update: set position i to value v
	void set(int i, int v, int node, int lx, int rx)
	{
		if (rx - lx == 1)
		{
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

	void set(int i, int v)
	{
		set(i, v, 0, 0, size);
	}

	// range query [l, r), to include r => [l,r+1)
	// int x -> current node of the tree.
	Node query(int l, int r, int node, int lx, int rx)
	{
		if (rx <= l || r <= lx)
			return NEUTRAL;
		if (l <= lx && rx <= r)
			return tree[node];

		int mid = (lx + rx) / 2;
		Node left = query(l, r, 2 * node + 1, lx, mid);
		Node right = query(l, r, 2 * node + 2, mid, rx);
		return merge(left, right);
	}

	Node query(int l, int r)
	{
		return query(l, r, 0, 0, size);
	}
};
#endif
void solve()
{
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cin >> t;
	while (t)
	{
		solve();
	}

	return 0;
}