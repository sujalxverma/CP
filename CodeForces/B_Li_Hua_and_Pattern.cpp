#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != a[n - 1 - i][n - 1 - j])
                count++;
        }
    }

    count = count / 2; // Each difference counted twice

    if (count > k)
    {
        cout << "NO\n";
        return;
    }
    else
    {
        int remaining_changes = k - count;
        // After fixing the mismatches, 
        // if we have leftover operations, 
        // check parity conditions.

        if (remaining_changes % 2 == 0)
        {
            cout << "YES\n";
        }
        else
        {
            if (n % 2 == 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // Number of test cases
    while (t--)
        solve();

    return 0;
}
