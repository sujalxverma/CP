#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<string> g(H);
    for (int i = 0; i < H; i++)
        cin >> g[i];

    int si, sj, gi, gj;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (g[i][j] == 'S')
                si = i, sj = j;
            if (g[i][j] == 'G')
                gi = i, gj = j;
        }
    }

    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    char dc[4] = {'U', 'D', 'L', 'R'};

    vector vis(H, vector(W, array<bool, 4>{false, false, false, false}));

    struct Node {
        int pi, pj, pd;
    };
    vector par(H, vector(W, array<Node, 4>()));

    queue<tuple<int, int, int>> q;

    for (int d = 0; d < 4; d++) {
        vis[si][sj][d] = true;
        par[si][sj][d] = {-1, -1, -1};
        q.emplace(si, sj, d);
    }

    int end_d = -1;

    while (!q.empty()) {
        auto [i, j, d] = q.front();
        q.pop();

        if (i == gi && j == gj) {
            end_d = d;
            break;
        }

        for (int nd = 0; nd < 4; nd++) {
            int ni = i + di[nd];
            int nj = j + dj[nd];

            if (ni < 0 || nj < 0 || ni >= H || nj >= W)
                continue;
            if (g[ni][nj] == '#')
                continue;

            char c = g[i][j];

            if (c == 'o' && nd != d)
                continue;
            if (c == 'x' && nd == d)
                continue;

            if (!vis[ni][nj][nd]) {
                vis[ni][nj][nd] = true;
                par[ni][nj][nd] = {i, j, d};
                q.emplace(ni, nj, nd);
            }
        }
    }

    if (end_d == -1) {
        cout << "No\n";
        return 0;
    }

    string ans;
    int i = gi, j = gj, d = end_d;

    while (true) {
        auto [pi, pj, pd] = par[i][j][d];
        if (pi == -1)
            break;
        ans.push_back(dc[d]);
        i = pi;
        j = pj;
        d = pd;
    }

    reverse(ans.begin(), ans.end());

    cout << "Yes\n";
    cout << ans << "\n";

    return 0;
}