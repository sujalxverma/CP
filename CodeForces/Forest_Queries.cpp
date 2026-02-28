#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '*')
            {
                g[i][j] = 1;
            }
            else
            {
                g[i][j] = 0;
            }
        }
    }

    vector<vector<int>> prefix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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

    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;

        int r1 = x1, c1 = y1;
        int r2 = x2, c2 = y2;
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

        cout << total << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}