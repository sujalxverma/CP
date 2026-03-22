#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int n, m;
vector<vector<char>> v;

void dfs(int r, int c) {
    if (v[r][c] == '#')
        return;
    v[r][c] = '#';

    vector<int> dx = {0, -1, 1, 0};
    vector<int> dy = {1, 0, 0, -1};

    for (int i = 0; i < 4; i++) {
        int x = dx[i] + r;
        int y = dy[i] + c;

        if (x >= 0 && x < n && y >= 0 && y < m) {
            if (v[x][y] == '.') {
                dfs(x, y);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    cin >> n >> m;
    v.assign(n, vector<char>(m, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        dfs(0, i);
    }

    for (int i = 0; i < m; i++) {
        dfs(n - 1, i);
    }
    for (int i = 0; i < n; i++) {
        dfs(i, 0);
    }
    for (int i = 0; i < n; i++) {
        dfs(i, m - 1);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] != '#') {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}