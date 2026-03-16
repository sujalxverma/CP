#include "bits/stdc++.h"
#include <chrono>
#include <queue>
#include <vector>
using namespace std;
using namespace std::chrono;
map<int, set<int>> order;
vector<vector<int>> g;

void bfs() {
    queue<pair<int, int>> q;
    q.push({1, 0});

    while (!q.empty()) {
        auto [u, level] = q.front();
        q.pop();

        order[level].insert(u);

        for (auto &v : g[u]) {
            q.push({v, level + 1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int n;
    cin >> n;
    g.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    vector<int> bfstraveral(n);
    for (int i = 0; i < n; i++) {
        cin >> bfstraveral[i];
    }

    bool f = true;
    int s = 0;
    int e = 0;
    bfs();
    for (auto &[id, x] : order) {
        cout << id << "\n";
        for (auto &z : x) {
            cout << z << " ";
        }
        cout << "\n";
    }

    return 0;
    for (auto &[id, x] : order) {
        s = e;
        e += (int)x.size();

        for (int i = s; i < e; i++) {
            if (x.find((bfstraveral[i])) == x.end()) {
                f = false;
                break;
            }
        }
    }

    if (f) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}