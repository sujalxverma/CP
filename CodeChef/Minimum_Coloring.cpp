#include "bits/stdc++.h"
using namespace std;

void bfs(vector<vector<int>> &a, int x1, int y1, int x2, int y2)
{

    int n = a.size();
    int m = a[0].size();
    std::queue<pair<int, int>> q;
    q.push({x1, y1});
    vector<pair<int, int>> d = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (auto [i, j] : d)
        {
            int l = i + x;
            int r = j + y;
            if (l >= 1 && l <= n - 1 && r >= 1 && r <= m - 1)
            {
                if (a[l][r] == 0)
                {
                    if (a[x][y] == 1)
                    {
                        a[l][r] = 2;
                        q.push({l, r});
                    }
                    else
                    {
                        a[l][r] = 1;
                        q.push({l, r});
                    }
                }
            }
        }
    }

    for (auto [i, j] : d)
    {
        int l = i + x2;
        int r = j + y2;
        if (l >= 1 && l <= n - 1 && r >= 1 && r <= m - 1){
            if(a[x2][y2] == a[l][r]){
                a[l][r] = 3;
            }
        }
    }
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
        int x1, y1, x2, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;

        a[x1][y1] = 1;
        a[x2][y2] = 2;

        bfs(a, x1, y1, x2, y2);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
