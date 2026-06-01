#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for (int i = 0; i < h; i++) {
        cin >> g[i];
    }
    int sr, sc, dr, dc;
    cin >> sr >> sc >> dr >> dc;
    sr--;
    sc--;
    dr--;
    dc--;
    vector<vector<int>> steps(h, vector<int>(w, 1e9));
    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<>>
        pq;
    pq.push({0, sr, sc});
    steps[sr][sc] = 0;
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    while (!pq.empty()) {
        auto [s, x, y] = pq.top();
        pq.pop();
        if (steps[x][y] < s) {
            continue;
        }
        if (x == dr && y == dc) {
            // cout << s << "\n";
            continue;
        }
        for (int i = 0; i < 4; i++) {
            bool wall = false;

            for (int j = 1; j <= 2; j++) {
                int r = x + dx[i] * j;
                int c = y + dy[i] * j;

                if (r < 0 || r >= h || c < 0 || c >= w)
                    break;

                if (g[r][c] == '#')
                    wall = true;

                int ns = s + (wall ? 1 : 0);

                if (steps[r][c] > ns) {
                    steps[r][c] = ns;
                    pq.push({ns, r, c});
                }
            }
        }
    }
    cout << steps[dr][dc] << "\n";
    return 0;
}