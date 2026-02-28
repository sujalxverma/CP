#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<char>> g(8, vector<char>(8));
        string ans = "";
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cin >> g[i][j];
                if (g[i][j] != '.')
                {
                    ans += g[i][j];
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}