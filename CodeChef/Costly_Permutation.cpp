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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        DSU d(n);
        for (int i = 0; i < n; i++) {
            int u = i;
            int v = a[u] - 1;
            // if (u == v) {
            //     continue;
            // }
            d.unionBySize(u, v);
        }
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            q;
        for (int i = 0; i < n; i++) {
            if (d.parent[i] == i) {
                if (d.size[i] == n) {
                    continue;
                }
                q.push({d.size[i], i});
            }
            // cout << i << " -> " << d.size[i] << "\n";
        }

        int sum = 0;
        while (q.size() > 1) {

            auto [c1, u] = q.top();
            q.pop();
            auto [c2, v] = q.top();
            q.pop();
            int c = c1 + c2;
            sum += c;
            d.unionBySize(u, v);
            q.push({c, d.find(u)});
        }
        cout << sum << "\n";
    }
    return 0;
}