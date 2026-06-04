#include "bits/stdc++.h"
using namespace std;
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    DSU d(n);
    // unordered_map<pair<int, int>, int> mp;
    set<pair<int, int>> mp;
    vector<tuple<string, int, int>> g;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) {
            swap(u, v);
        }
        mp.insert({u, v});
    }
    for (int i = 0; i < q; i++) {
        string ch;
        int u;
        int v;
        cin >> ch >> u >> v;
        if (u > v) {
            swap(u, v);
        }
        g.push_back({ch, u, v});
        if (ch == "cut") {
            mp.erase({u, v});
        }
    }
    vector<string> ans;
    for (auto &[x, z] : mp) {
        d.unionBySize(x, z);
    }
    for (int i = q - 1; i >= 0; i--) {
        auto [x, u, v] = g[i];
        if (x == "cut") {
            d.unionBySize(u, v);
        } else {
            if (d.find(u) == d.find(v)) {
                ans.push_back("YES");
            } else {
                ans.push_back("NO");
            }
        }
    }
    for (int i = (int)ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << "\n";
    }

    return 0;
}