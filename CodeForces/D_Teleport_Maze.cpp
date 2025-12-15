#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<string> a(H);
    for (int i = 0; i < H; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dist(H, vector<int>(W, -1));
    vector<vector<pair<int,int>>> warp(26);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c = a[i][j];
            if (c >= 'a' && c <= 'z') {
                warp[c - 'a'].push_back({i, j});
            }
        }
    }

    vector<bool> warp_used(26, false);
    queue<pair<int,int>> q;

    dist[0][0] = 0;
    q.push({0, 0});

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == H - 1 && y == W - 1) {
            cout << dist[x][y] << "\n";
            return 0;
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if (a[nx][ny] == '#') continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }

        char c = a[x][y];
        if (c >= 'a' && c <= 'z') {
            int id = c - 'a';

            if (!warp_used[id]) {
                warp_used[id] = true;

                for (auto &p : warp[id]) {
                    int wx = p.first;
                    int wy = p.second;

                    if (dist[wx][wy] == -1) {
                        dist[wx][wy] = dist[x][y] + 1;
                        q.push({wx, wy});
                    }
                }
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}
