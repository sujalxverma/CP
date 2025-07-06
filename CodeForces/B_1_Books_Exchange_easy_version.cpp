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
#define gcd(a, b) ([](int x, int y) {while (y != 0) { int temp = y;y = x % y; x = temp;}return x; })(a, b)
#define lcm(a, b) (a * b / gcd(a, b))
#define sorting(v) sort(v.begin(), v.end())
#define line cout << endl
#define contains(vec, x) (std::find((vec).begin(), (vec).end(), (x)) != (vec).end())
#define containsBS(vec, x) (std::binary_search((vec).begin(), (vec).end(), (x)))
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

const int MOD = 100000;

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
    void unionBySize(int nodeA, int nodeB)   // O(4@) -> O(constant)
    { // it takes 2 nodes as argument.
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
     1. First we create dsu components by traversing througg array.
     2. Now for each book to be returned, its number of days will be equal to size of that component.
*/
void solve(){
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    DSU dsu(n);
    // Union each index with its mapped value
    for (int i = 1; i <= n; i++) {
        dsu.unionBySize(i, a[i]);
    }

    // For each index output size of the component it belongs to
    for (int i = 1; i <= n; i++) {
        int p = dsu.superParent(i);
        cout << dsu.size[p] << " ";
    }
    cout << "\n";
  
}
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


