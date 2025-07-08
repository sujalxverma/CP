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

class DSU
{
public:
    vector<int> parent, rank, size;

    DSU(int n)
    { // heres 'n' gives number of nodes, 0 based indexing.
        parent.resize(n + 1);
        rank.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i; // initially, every node will be parent of itself.
            size[i] = 1;
        }
    }

    int superParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = superParent(parent[node]);
    }

    void unionByRank(int nodeA, int nodeB)
    {
        // it takes 2 nodes as argument.
        int parentOfNodeA = superParent(nodeA);
        int parentOfNodeB = superParent(nodeB);

        if (parentOfNodeA == parentOfNodeB)
        {
            return; // it simply means they are of part of same component.
        }

        if (rank[parentOfNodeA] > rank[parentOfNodeB])
        {
            parent[parentOfNodeB] = parentOfNodeA;
        }
        else if (rank[parentOfNodeA] < rank[parentOfNodeB])
        {
            parent[parentOfNodeA] = parentOfNodeB;
        }
        else
        {
            parent[parentOfNodeB] = parentOfNodeA; // rank only increase if they both have same rank, rank can be considered as level.
            rank[parentOfNodeA]++;                 // if level is same, then only rank increase.
        }
    }
    void unionBySize(int nodeA, int nodeB) // O(4@) -> O(constant)
    {                                      // it takes 2 nodes as argument.
        int parentOfNodeA = superParent(nodeA);
        int parentOfNodeB = superParent(nodeB);

        if (parentOfNodeA == parentOfNodeB)
        {
            return; // it simply means they are of part of same component.
        }

        if (size[parentOfNodeA] >= size[parentOfNodeB])
        {
            size[parentOfNodeA] += size[parentOfNodeB]; // nodeB is added to nodeA, hence nodeA component size increase.
            parent[parentOfNodeB] = parentOfNodeA;
        }
        else
        {
            size[parentOfNodeB] += size[parentOfNodeA]; // nodeA is added to nodeB , hence nodeB component size increase.
            parent[parentOfNodeA] = parentOfNodeB;
        }
    }
};

/*
 * In every union operation, the superParent() (also known as find() in many texts) function must be called for both nodes.
 */

void solve()
{
    int n, k, m;
    cin >> n >> k >> m;

    vector<string> msg(n + 1);
    unordered_map<string, int> wordToIndex;

    for (int i = 1; i <= n; i++)
    {
        cin >> msg[i];
        wordToIndex[msg[i]] = i;
    }

    vector<int> cost(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }

    DSU dsu(n + 1);
    vector<int> minCost = cost; // 1-based

    // Process groups
    for (int i = 0; i < k; i++)
    {
        int members;
        cin >> members;
        vector<int> group(members);
        for (int j = 0; j < members; j++)
        {
            cin >> group[j];
        }

        for (int j = 1; j < members; j++)
        {
            int a = dsu.superParent(group[0]);
            int b = dsu.superParent(group[j]);
            if (a != b)
            {
                dsu.unionBySize(a, b);
                int newRoot = dsu.superParent(a); // union might have changed root
                minCost[newRoot] = min(minCost[a], minCost[b]);  // minimum cost for the entire group/component.
            }
        }
    }

    ll total = 0;
    for (int i = 0; i < m; i++)
    {
        string word;
        cin >> word;
        int idx = wordToIndex[word];
        int groupRoot = dsu.superParent(idx);
        total += minCost[groupRoot];
    }

    cout << total << '\n';
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
