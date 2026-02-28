#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

/*

THE LOGIC IS PRETTY SIMPLE.
------------------------------------------------------------------------------
WE CAN ITERATE OVER EACH EMPTY CELL (FOR THEIR FIRST EXPLOSION), AND CHECK THE LOSS OF GOLD FROM THAT EXPLOSION.
MIN_LOSS = MIN LOSS FROM ALL POSSIBLE EXPLOSION
------------------------------------------------------------------------------
RETURN (TOTAL GOLD - MIN_LOS)
------------------------------------------------------------------------------
I CRACKED THE LOGIC, BUT I COULD NOT CODE IT. AND I SAW THE EXPLANATION,
ITS USE OF 2-D PREFIX SUM, AND SUB-MATRIX SUM QUERY.

*/

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> p;
    vector<vector<int>> g(n, vector<int>(m));

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == 'g')
            {
                g[i][j] = 1;
                sum++;
            }
            else
            {
                g[i][j] = 0;
            }

            if (ch == '.')
            {
                p.push_back({i, j});
            }
        }
    }
    // construction of prefix sum.
    vector<vector<int>> prefix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            prefix[i][j] += g[i][j];

            if (i > 0)
            {
                prefix[i][j] += prefix[i - 1][j];
            }
            if (j > 0)
            {
                prefix[i][j] += prefix[i][j - 1];
            }

            if (i > 0 && j > 0)
            {
                // reduce overlap.
                prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }
    }
    /*
    SUB-ARRAY MATRIX SUM
        int r1,c1;
        int r2,c2;
        int total = prefix[r2][c2];
        if(r1 > 0){
            total -= prefix[r1-1][c2];
        }
        if(c1 > 0){
            total -= prefix[r2][c1-1];
        }
        if(r1 > 0 && c1 > 0){
            total += prefix[r1-1][c1-1];
        }
    */
    int ans = 1e9;
    for (auto &[x, y] : p)
    {

        // k-1
        int r1 = max(0, x - k + 1), c1 = max(0, y - k + 1);
        int r2 = min(n - 1, x + k - 1), c2 = min(m - 1, y + k - 1);
        int total = prefix[r2][c2];
        if (r1 > 0)
        {
            total -= prefix[r1 - 1][c2];
        }
        if (c1 > 0)
        {
            total -= prefix[r2][c1 - 1];
        }
        if (r1 > 0 && c1 > 0)
        {
            total += prefix[r1 - 1][c1 - 1];
        }

        ans = min(ans, total);
    }
    cout << sum - ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}