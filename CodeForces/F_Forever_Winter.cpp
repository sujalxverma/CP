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
Approach to Solve the Snowflake Graph Problem:

1. Problem Structure:
   - The graph is generated using two integers x and y (both > 1).
   - Structure of the graph:
     • 1 central vertex of degree x
     • x middle vertices, each connected to the center and y leaf vertices (degree = y + 1)
     • x * y leaf vertices, each connected to only one middle vertex (degree = 1)

2. Goal:
   - Given the graph (as an edge list), determine the values of x and y.

3. Key Observations:
   - Degree-1 vertices (leaves) appear exactly x * y times.
   - One vertex has a unique degree x — this is the central vertex.
   - x vertices have degree y + 1 — the middle layer.
   - Edge case: If x == y + 1, then both the central vertex and middle vertices have the same degree x.
     • In this case, degree x appears x + 1 times.

4. Algorithm:
   - Count degrees of all vertices using edge list.
   - Count the frequency of each degree.
   - Use degree-1 frequency to get x * y.
   - If there's a degree with frequency 1, it's x (central vertex), and y = (x * y) // x.
   - Else (edge case), find degree d with count d + 1:
     • x = d - 1
     • y = x - 1

5. Time Complexity:
   - O(n + m) per test case (n = number of vertices, m = number of edges),
     since we only loop through edges and then through degrees once.

6. Assumptions:
   - Input graph follows the snowflake pattern strictly.
   - The graph is connected and has no extra or missing edges.
*/


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n + 1);
    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

     map<int,int>mp;
     for(int i = 1; i <= n ; i++){
        mp[edges[i].size()]++;
     }
     vector<int>v;
     for(auto it : mp){
        v.push_back(it.second);
     }
     sort(v.begin(),v.end());
     if(v.size() == 3){
        cout << v[1] << ' ' << v[2] / v[1] << '\n';
     }else{
        cout << v[0] - 1 << ' ' << v[1] / (v[0] - 1) << '\n';  
     }
}

// let' say we have, 

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




