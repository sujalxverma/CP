#include "bits/stdc++.h"
using namespace std;

/*
    Problem Idea:
    -------------
    Given a 2D matrix, we are to find the maximum element (mx) and determine if we can reduce *all* instances of it to (mx - 1)
    by reducing all values in a single row or a single column (in one operation).

    Observation:
    ------------
    - If all cells containing `mx` lie in a single row or a single column,
      then reducing that row or column will reduce all instances of `mx` by 1.

    Approach:
    ---------
    1. Find `mx` (maximum element in the grid) and count how many times it appears (`cnt_mx`).
    2. For each row and column, count how many times `mx` appears in that row and column.
    3. Try all positions (i, j) and see if row[i] + col[j] contains all the `mx` values.
       (Subtract 1 if (i,j) itself is `mx`, since it gets counted twice.)
    4. If any such (i,j) exists, we can reduce all `mx` → answer is `mx - 1`; else it's `mx`.
*/

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    int mx = 0, cnt_mx = 0;

    // Step 1: Read matrix and track max value and its count
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            if (a[i][j] > mx)
            {
                mx = a[i][j];
                cnt_mx = 1;
            }
            else if (a[i][j] == mx)
            {
                cnt_mx++;
            }
        }
    }

    // Step 2: Count occurrences of mx in each row and column
    vector<int> row(n, 0), col(m, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == mx)
            {
                row[i]++;
                col[j]++;
            }
        }
    }

    // Step 3: Check if any row + column contains all mx values
    bool reducible = false;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int total = row[i] + col[j];
            if (a[i][j] == mx)
                total--; // subtract overcount

            if (total == cnt_mx)
                reducible = true;
        }
    }

    cout << mx - reducible << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
