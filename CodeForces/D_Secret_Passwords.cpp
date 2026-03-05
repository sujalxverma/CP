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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> fr(26, 0);
    for (auto &x : s) {
        cin >> x;
        for (int i = 0; i < (int)x.length(); i++) {
            fr[x[i] - 'a'] = 1;
        }
    }
    DSU dsu(27);
    for (auto &x : s) {
        for (int i = 0; i < (int)x.size() - 1; i++) {

            dsu.unionBySize(dsu.find(x[i] - 'a'), dsu.find(x[i + 1] - 'a'));
        }
    }
    for (int i = 0; i < 26; i++) {
        dsu.parent[i] = dsu.find(i);
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (dsu.find(i) == i && fr[i] == 1) {
            ans++;
        }
    }

    cout << ans << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}