#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
const int inf = 1e9;
int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;
    vector<vector<int>> d(n, vector<int>(m, inf));
    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'M') {
                q.push({i, j});
                d[i][j] = 0;
            }
        }
    }
    int sr, sc;
    // run bfs from all monsters position.
    vector<vector<int>> hero(n, vector<int>(m, inf));
    vector<vector<char>> path(n, vector<char>(m, inf));
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    vector<char> dir = {'R', 'D', 'L', 'U'};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int rt = dx[i] + r;
            int ct = dy[i] + c;
            if (rt >= 0 && ct >= 0 && rt < n && ct < m && g[rt][ct] != '#') {
                if (d[rt][ct] == inf) {
                    d[rt][ct] = d[r][c] + 1;
                    q.push({rt, ct});
                }
            }
        }
    }

    // now we got minium distance to reach boundary for the monsters.
    // now we have to check our hero can reach some boundary or not.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'A') {
                q.push({i, j});
                hero[i][j] = 0;
                sr = i;
                sc = j;
            }
        }
    }
    int fr = -1;
    int fc = -1;
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        if ((r == n - 1 || r == 0) || (c == 0 || c == m - 1)) {
            fr = r;
            fc = c;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int rt = dx[i] + r;
            int ct = dy[i] + c;
            if (rt >= 0 && ct >= 0 && rt < n && ct < m && g[rt][ct] != '#' && hero[rt][ct] == inf) {
                if (hero[r][c] + 1 < d[rt][ct]) {
                    hero[rt][ct] = 1 + hero[r][c];
                    path[rt][ct] = dir[i];
                    q.push({rt, ct});
                }
            }
        }
    }

    if (fr == -1 && fc == -1) {
        cout << "NO\n";
        return 0;
    }

    // need to backtrack the path.
    cout << "YES\n";
    vector<char> ans;

    while (!(fr == sr && fc == sc)) {
        ans.push_back(path[fr][fc]);
        if (path[fr][fc] == 'U') {
            fr++;
        } else if (path[fr][fc] == 'D') {
            fr--;
        } else if (path[fr][fc] == 'R') {
            fc--;
        } else {
            fc++;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << (int)ans.size() << "\n";
    for (auto &x : ans) {
        cout << x;
    }
    cout << "\n";
    return 0;
}