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

// uses Set instead of PQ.
// 1 based indexing
pair<vector<ll>, vector<ll>> dijkstra(const vector<vector<pair<ll, ll>>> &graph, ll source) {
    ll n = graph.size() - 1;
    vector<ll> distances(n + 1, LLONG_MAX);
    vector<ll> predecessors(n + 1, -1);

    set<pair<ll, ll>> active_nodes;

    distances[source] = 0;
    active_nodes.insert({0, source});

    while (!active_nodes.empty()) {
        auto [current_distance, current_node] = *active_nodes.begin();
        active_nodes.erase(active_nodes.begin());

        if (current_distance > distances[current_node])
            continue;

        for (const auto &edge : graph[current_node]) {
            ll neighbor = edge.first;
            ll weight = edge.second;

            ll new_distance = current_distance + weight;
            if (new_distance < distances[neighbor]) {
                if (distances[neighbor] != LLONG_MAX) {
                    active_nodes.erase({distances[neighbor], neighbor});
                }
                distances[neighbor] = new_distance;
                predecessors[neighbor] = current_node;
                active_nodes.insert({new_distance, neighbor});
            }
        }
    }

    return {distances, predecessors};
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> graph(n + 1);
    rep2(i, 1, m + 1) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    auto [distances, predecessors] = dijkstra(graph, 1);

    if (distances[n] == LLONG_MAX) {
        cout << -1 << endl;
        return;
    }

    vector<ll> path;
    ll dest = n;
    while (dest != -1) {
        path.push_back(dest);
        dest = predecessors[dest];
    }
    reverse(path.begin(), path.end());

    for (auto node : path) cout << node << " ";
    cout << endl;
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


