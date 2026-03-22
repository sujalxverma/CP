#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<string> g;
vector<vector<int>> vis;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    g.resize(n);
    for (int i = 0; i < n; i++)
        cin >> g[i];

    int sr = -1, sc = -1;

    // find start
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'A') {
                sr = i;
                sc = j;
            }
        }
    }

    vis.assign(n, vector<int>(m, 0));
    vector<vector<char>> parent(n, vector<char>(m));

    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = 1;
    parent[sr][sc] = 'Q';

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    vector<char> dir = {'D', 'R', 'U', 'L'};

    int er = -1, ec = -1;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (g[r][c] == 'B') {
            er = r;
            ec = c;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int x = r + dx[i];
            int y = c + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m &&
                !vis[x][y] && g[x][y] != '#') {

                vis[x][y] = 1;
                parent[x][y] = dir[i];
                q.push({x, y});
            }
        }
    }

    // if B not reachable
    if (er == -1) {
        cout << "NO\n";
        return 0;
    }

    // reconstruct path
    vector<char> ans;
    int r = er, c = ec;

    while (parent[r][c] != 'Q') {
        char d = parent[r][c];
        ans.push_back(d);

        if (d == 'U')
            r++;
        else if (d == 'D')
            r--;
        else if (d == 'L')
            c++;
        else if (d == 'R')
            c--;
    }

    reverse(ans.begin(), ans.end());
    if (ans.size() == 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << ans.size() << "\n";
    for (char ch : ans)
        cout << ch;
    cout << "\n";

    return 0;
}