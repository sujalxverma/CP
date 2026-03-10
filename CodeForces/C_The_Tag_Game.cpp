#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

/*
- Alice is at 1, Bob is at x, Bob starts first, its a tree.
- Bob will try to move to the leaf nodes of its subtree.
- Beacuse if bob tries to escape its subtree, then alice will catch him.
- So, what can we do is to find the distance to leaf nodes from Alice and Bob as well.
- Obviously, check for only leaf nodes, for which Bob can reach.
- Thus, we have done alice_dfs[leaf] > bob_dfs[leaf] : ans = max(ans , 2 * alice_dfs[leaf])
- But why not ? alice_dfs[leaf] >= bob_dfs[leaf], if at any point distance is same, then its possible
  that both alice and bob meets at some intermediate node.
- Check Sample Case for this reason.
*/

vector<int> alice_dfs, bob_dfs, alice_v, bob_v;
vector<vector<int>> tree;
set<int> leafs;
void dfs(int node, vector<int> &v, vector<int> &dist, int d) {
    v[node] = 1;
    dist[node] = d;
    bool f = false;
    for (auto &n : tree[node]) {
        if (v[n] == 0) {
            f = true;
            dfs(n, v, dist, d + 1);
        }
    }

    if (!f) {
        leafs.insert(node);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();
    int n, bob;
    cin >> n >> bob;
    tree.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    alice_dfs.assign(n + 1, 0);
    bob_dfs.assign(n + 1, 0);
    alice_v.assign(n + 1, 0);
    bob_v.assign(n + 1, 0);

    dfs(1, alice_v, alice_dfs, 0);
    dfs(bob, bob_v, bob_dfs, 0);

    int ans = 2 * alice_dfs[bob]; // atleast this answer is always possible, need to find better answer.

    // now check disatance of each leaf node, to which bob can reach faster.

    for (auto &x : leafs) {
        if (alice_dfs[x] > bob_dfs[x]) {
            ans = max(ans, 2 * alice_dfs[x]);
        }
    }

    cout << ans << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}