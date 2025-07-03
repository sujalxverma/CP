

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
/*
    🔍 Problem Insight:
    -------------------
    We want to minimize the total score, which is the sum of f(u, v) over all pairs (u, v),
    where f(u, v) = MEX of the labels on the path from u to v.
    We can choose the labels as a permutation of [0, N-1] to minimize the score.

    ✅ Observations:
    ----------------
    1. A tree with all nodes having degree ≤ 2 (i.e., a path or chain) has exactly one path between any two nodes,
       and the MEX increases in a predictable way.
    2. If a node has degree > 2, it means some paths will "merge" at this high-degree node,
       increasing the chances of small labels appearing more often along paths (thus increasing total MEX contribution).

    ⚙️ Optimization:
    ----------------
    - If any node has degree > 2:
        → That node is used in many paths, and assigning it a small label would reduce MEX in many paths.
        → But since labels are distinct, this effect causes many paths to get low MEXs.
        → The best we can do here is: **minimum score = N + 1** (lower bound due to central concentration).
    
    - If all nodes have degree ≤ 2 (i.e., it's a path/tree chain):
        → We can label nodes linearly (0 to N-1), so MEX along any path (subarray of permutation) increases steadily.
        → This leads to the **minimum possible score = 2 * N - 1** (based on mathematical properties of MEX sums in chains).
    
    💡 Implementation Notes:
    -------------------------
    - Use 1-based indexing for node input and adjacency list.
    - For each node, check its degree:
        → If any node has degree > 2 → Output N + 1.
    - Otherwise → Output 2 * N - 1.

    🚫 Additional Notes:
    ---------------------
    - Since f(u, v) == f(v, u), we don't need to count both (u, v) and (v, u) — just once.
    - But this optimization is not needed here, since we are returning a constant based on tree shape.
*/


void solve()
{
    int n;
    cin >> n;
    // 1 bases indexing
    vector<vector<int>>edges(n+1);
    if(n==1){
        cout<<1<<endl;
        return ;
    }
    rep(i,1,n){
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    // if number of edge for a vertex is > 2, then return 2N-1 , else N+1.
    rep(i,1,n+1){
        
        if(edges[i].size() > 2){
            cout<<n+1<<endl;
            return ;
        }

    }
    cout<<2*n-1<<endl;
    
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
