#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int n, m;
int sr, sc, gr, gc;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'S')
                sr = i, sc = j;
            if (g[i][j] == 'G')
                gr = i, gc = j;
        }
    }

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    vector<char> dc = {'R', 'L', 'D', 'U'};

    // visited[x][y][dir]
    vector<vector<vector<int>>> vis(
        n, vector<vector<int>>(m, vector<int>(4, 0)));

    // parent[x][y][dir] = {px, py, pdir}
    vector<vector<vector<tuple<int, int, int>>>> parent(
        n, vector<vector<tuple<int, int, int>>>(
               m, vector<tuple<int, int, int>>(4, {-1, -1, -1})));

    queue<tuple<int, int, int>> q;

    // start: push all 4 directions
    for (int d = 0; d < 4; d++) {
        int nx = sr + dx[d];
        int ny = sc + dy[d];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (g[nx][ny] == '#')
            continue;

        vis[nx][ny][d] = 1;
        parent[nx][ny][d] = {sr, sc, -1};
        q.push({nx, ny, d});
    }

    int end_dir = -1;

    while (!q.empty()) {
        auto [x, y, d] = q.front();
        q.pop();

        if (x == gr && y == gc) {
            end_dir = d;
            break;
        }

        char cell = g[x][y];

        for (int nd = 0; nd < 4; nd++) {

            // apply constraints
            if (cell == 'o' && nd != d)
                continue;
            if (cell == 'x' && nd == d)
                continue;

            int nx = x + dx[nd];
            int ny = y + dy[nd];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (g[nx][ny] == '#')
                continue;

            if (vis[nx][ny][nd])
                continue;

            vis[nx][ny][nd] = 1;
            parent[nx][ny][nd] = {x, y, d};
            q.push({nx, ny, nd});
        }
    }

    if (end_dir == -1) {
        cout << "No\n";
        return 0;
    }

    // reconstruct path
    string ans;
    int x = gr, y = gc, d = end_dir;

    while (true) {
        ans.push_back(dc[d]);
        auto [px, py, pd] = parent[x][y][d];

        if (px == sr && py == sc)
            break;

        x = px;
        y = py;
        d = pd;
    }

    reverse(ans.begin(), ans.end());

    cout << "Yes\n";
    cout << ans << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}