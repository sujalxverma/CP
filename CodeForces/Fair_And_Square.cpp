#include "bits/stdc++.h"
using namespace std;
#define int long long
/*
* N -> TOTAL NODES IN TREE
* LCA(U,V) -> L(U,V)
* PRODUCT(U,V) -> P(U,V)

* SAY IF WE WANT TO FIND : P(U,V) = (P(ROOT,U) * P(ROOT,V) * LCA(U,V)) / ((P(ROOT,L(U,V)))**2)
* NOW SINCE ((P(ROOT,L(U,V)))**2), IS ALREADY SQUARED. SO WE JUST LEAVE IT.

* NOW THE THING IS, FOR THREE DISTINCT NODES OF A TREE :
* {L(U,V) , L(V,W) , L(U,W)} -> SIZE IS ATMOST 2, MEANS AT LEAST ONE LCA IS REPEATED. (AND THIS IS AWESOME OBSERVATION).
* TO VERIFY JUST DRAW TREE, AND CHECK IT OUT.

* P(U,V) * P(V,W) * P(U,W) => SHORTS DOWN TO => L(U,V) * L(U,W) * L(V,W).
* AND SINCE ATLEAST ONE LCA IS REPEATED, THUS
* POSSIBLITEIES, IS : L*L*K , OR L*L*L

* FOR L*L*K => IF K IS PERFECT SQUARE, THEN THE WHOLE PATH SATISFY CONDITION.
* FOR L*L*L => IF L ITSELF IS PERFECT SQUARE, THEN THE WHOLE PATH SATIFIES CONDITION.

* CASE 1 : L*L*L -> WHEN LCA (SAY X) IS ALSO PART OF TRIPLET (U,V,W) , THEN I HAVE TO CHOOSE
* TWO MORE NODES. THESE TWO NODES MUST COME FROM TWO DIFFERENT COMPONENTS CONNECTED TO X.
*
* CASE 2 : L*L*K -> WHEN LCA (SAY X) IS STRICTLY THE INTERSECTION AND NOT PART OF THE TRIPLET,
* THEN I HAVE TO CHOOSE THREE NODES FROM THREE DIFFERENT COMPONENTS CONNECTED TO X.
*
* OPTIMIZATION : BOTH CASES CAN BE CALCULATED SIMULTANEOUSLY USING A ROLLING SUM TRICK
* OVER THE CONNECTED COMPONENTS (CHILDREN + PARENT) OF EVERY PERFECT SQUARE NODE.
*/

int n;
vector<vector<int>> tree;
vector<int> value;
vector<int> subtree;
set<int> prefectSquare;
vector<int> triplets;
void subtreeDFS(int u, int p) {
    subtree[u] = 1;
    for (int &v : tree[u]) {
        if (p != v) {
            subtreeDFS(v, u);
            subtree[u] += subtree[v];
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        // CRITICAL FIX: Properly clear all global state for multiple test cases
        tree.assign(n + 1, vector<int>());
        value.assign(n + 1, 0);
        subtree.assign(n + 1, 0);
        prefectSquare.clear();
        triplets.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> value[i];
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            if (floor(sqrt(value[i])) * floor(sqrt(value[i])) == value[i]) {
                prefectSquare.insert(value[i]);
            }
        }

        subtreeDFS(1, -1);
        int ans = 0;
        // L*L*L, case.
        for (int i = 1; i <= n; i++) {
            if (!prefectSquare.count(value[i])) {
                continue;
            }

            int sum = 0;
            int pairs = 0;
            for (auto &v : tree[i]) {
                int comp_size;
                if (subtree[v] > subtree[i]) {
                    // v is the parent. The component is everything in the tree EXCEPT node i's subtree.
                    comp_size = n - subtree[i];
                } else {
                    // v is a child. The component is just v's subtree.
                    comp_size = subtree[v];
                }

                pairs += (comp_size * sum);
                sum += comp_size;
            }

            // triplets[i] = pairs;
            ans += pairs;
        }

        // L * L * K case.
        // Now the Node X is not part of 3 nodes, it is intersection.
        for (int i = 1; i <= n; i++) {
            if (!prefectSquare.count(value[i])) {
                continue;
            }
            int sum = 0;     // total number of single nodes.
            int pairs = 0;   // The total valid 2-node combinations from different components seen so far.
            int triples = 0; // The total valid 3-node combinations from different components seen so far
            int comp_size;
            for (auto &v : tree[i]) {
                int comp_size;
                if (subtree[v] > subtree[i]) {
                    // v is the parent. The component is everything in the tree EXCEPT node i's subtree.
                    comp_size = n - subtree[i];
                } else {
                    // v is a child. The component is just v's subtree.
                    comp_size = subtree[v];
                }
                triples += (comp_size * pairs);
                pairs += (comp_size * sum);
                sum += comp_size;
            }

            ans += triples;
        }
        // WE CAN COMBINE ABOVE TWO LOOPS, AS SECOND LOOP ALSO CALCULATES PAIRS.
        cout << ans << "\n";
    }

    return 0;
}