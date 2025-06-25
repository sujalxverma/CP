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

void dfs(int node, int parent, vector<vector<int>> &graph, vector<int> &color){
    for (int child : graph[node]) {
        if (child == parent) continue;

        if (color[node] == 0) {
            color[child] = 1;
            cout << node  << " " << child  << "\n";
        } else {
            color[child] = 0;
            cout << child  << " " << node << "\n";
        }

        dfs(child, node, graph, color);
    }
}

void solve() {
    int n;
    cin >> n;
    // u->incoming = 0 , v->incoming=2 & outgoing = 0
    vector<vector<int>>graph(n+1);
    vector<int>color(n+1,-1);
    vector<int>visit(n+1,-1);
    rep(i,0,n-1){
        int u,v;
        cin >> u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int node = 0;
   for(int i = 1 ; i <= n; i++){
    if(graph[i].size() == 2){
        node = i;
        break;
    }
   }
   if(node == 0){
    no;
    return ;
   }
   yes;
   color[graph[node][0]] = 1;
   color[graph[node][1]] = 0;
   visit[node] = 1;

   vector<vector<int>>ans(n+1); // directed graph

   dfs(graph[node][0],node,graph,color);
   dfs(graph[node][1],node,graph,color);
   cout<<node<<" "<<graph[node][0]<<endl;
   cout<<graph[node][1]<<" "<<node<<endl;
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
