#include "bits/stdc++.h"
using namespace std;

struct DSU {
    vector<int> parent, rank, parity;
    vector<array<int, 2>> cnt; // cnt[x][0], cnt[x][1]

    DSU(int n) {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        parity.assign(n + 1, 0);
        cnt.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            cnt[i] = {1, 0}; // initially each node is color 0
        }
    }

    pair<int, int> find(int x) {
        if (parent[x] == x)
            return {x, 0};

        auto [p, par] = find(parent[x]);
        parity[x] ^= par;
        parent[x] = p;

        return {parent[x], parity[x]};
    }

    bool unite(int u, int v) {
        auto [pu, xu] = find(u);
        auto [pv, xv] = find(v);

        if (pu == pv) {
            return ((xu ^ xv) == 1);
        }

        if (rank[pu] < rank[pv]) {
            swap(pu, pv);
            swap(xu, xv);
        }

        parent[pv] = pu;

        // determine how to merge counts
        int flip = xu ^ xv ^ 1;

        array<int, 2> new_cnt = {0, 0};

        for (int c = 0; c < 2; c++) {
            new_cnt[c] = cnt[pu][c] + cnt[pv][c ^ flip];
        }

        cnt[pu] = new_cnt;

        if (rank[pu] == rank[pv])
            rank[pu]++;

        return true;
    }

    // get size of component containing x
    int get_size(int x) {
        auto [p, _] = find(x);
        return cnt[p][0] + cnt[p][1];
    }

    // get partitions
    pair<int, int> get_partition(int x) {
        auto [p, _] = find(x);
        return {cnt[p][0], cnt[p][1]};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        if (!dsu.unite(u, v)) {
            // cout << "Not Bipartite at edge " << i + 1 << '\n';
            cout << "-1\n";
            // return 0;
        } else {
            cout << dsu.get_size(dsu.find(u).first) / 2 << "\n";
        }
    }

    // cout << "Graph is Bipartite\n";
    return 0;
}