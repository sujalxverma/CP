#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

class DSU {
  public:
    vector<int> parent, rank, size;

    DSU(int n) { // heres 'n' gives number of nodes, 0 based indexing.
        parent.resize(n + 1);
        rank.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i; // initially, every node will be parent of itself.
            size[i] = 1;
        }
    }

    int find(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    void unionByRank(int nodeA, int nodeB) {
        // it takes 2 nodes as argument.
        int parentOfNodeA = find(nodeA);
        int parentOfNodeB = find(nodeB);

        if (parentOfNodeA == parentOfNodeB) {
            return; // it simply means they are of part of same component.
        }

        if (rank[parentOfNodeA] > rank[parentOfNodeB]) {
            parent[parentOfNodeB] = parentOfNodeA;
        } else if (rank[parentOfNodeA] < rank[parentOfNodeB]) {
            parent[parentOfNodeA] = parentOfNodeB;
        } else {
            parent[parentOfNodeB] = parentOfNodeA; // rank only increase if they both have same rank, rank can be considered as level.
            rank[parentOfNodeA]++;                 // if level is same, then only rank increase.
        }
    }
    void unionBySize(int nodeA, int nodeB) // O(4@) -> O(constant)
    {                                      // it takes 2 nodes as argument.
        int parentOfNodeA = find(nodeA);
        int parentOfNodeB = find(nodeB);

        if (parentOfNodeA == parentOfNodeB) {
            return; // it simply means they are of part of same component.
        }

        if (size[parentOfNodeA] >= size[parentOfNodeB]) {
            size[parentOfNodeA] += size[parentOfNodeB]; // nodeB is added to nodeA, hence nodeA component size increase.
            parent[parentOfNodeB] = parentOfNodeA;
        } else {
            size[parentOfNodeB] += size[parentOfNodeA]; // nodeA is added to nodeB , hence nodeB component size increase.
            parent[parentOfNodeA] = parentOfNodeB;
        }
    }
};

/*
 * In every union operation, the find() (also known as find() in many texts) function must be called for both nodes.
 */

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> f, g;
    DSU d1(n + 1);
    DSU d2(n + 1);
    for (int i = 0; i < a; i++) {
        int u, v;
        cin >> u >> v;
        f.push_back({u, v});
    }
    for (int i = 0; i < b; i++) {
        int u, v;
        cin >> u >> v;
        g.push_back({u, v});
        d1.unionBySize(d1.find(u), d1.find(v));
    }

    if (b == 0) {
        cout << a << "\n";
        return;
    }
    if (a == 0 && b == 0) {
        cout << "0\n";
        return;
    }
    int cnt = 0;

    for (int i = 0; i < a; i++) {
        int u = f[i][0];
        int v = f[i][1];

        if (d1.find(u) == d1.find(v)) {
            // u and v connected in G, so keep this edge.
            d2.unionBySize(u, v);
        } else {
            // No connection b/w u and v, so remove this edge.
            cnt++;
        }
    }

    for (int i = 0; i < b; i++) {
        int u = g[i][0];
        int v = g[i][1];
        if (d2.find(u) != d2.find(v)) {
            // u and v are connected in G, but not connected in F, so add an edge b/w u and v.
            cnt++;
            d2.unionBySize(u, v);
        }
    }

    cout << cnt << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}