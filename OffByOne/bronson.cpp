#include "bits/stdc++.h"
using namespace std;

/*
1. Reconstruct the subset thatt sums = target.
2. It requires 2D DP, cannot be created using 1D optimised DP.
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a = {1, 4, 2, 9, 5, 7};
    int target = 12;
    int n = (int)a.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    vector<vector<int>> choice(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    { // index, traversing array
        for (int j = 1; j <= target; j++)
        { // value/sum, taravtraversingersing the sum.

            // nottake
            if (dp[i - 1][j])
            {
                dp[i][j] = 1;
                choice[i][j] = 0;
            }

            // take
            if (a[i-1] <= j && dp[i - 1][j - a[i-1]])
            {
                dp[i][j] = 1;
                choice[i][j] = 1;
            }
        }
    }

    if (!dp[n][target])
    {
        cout << "Not Exist\n";
        return 0;
    }

    vector<int> subset;

    int idx = n;
    int sum = target;
    while (idx > 0 && sum > 0)
    {
        if (choice[idx][sum])
        {
            // this is element is selected.
            sum -= a[idx-1];
            subset.push_back(a[idx-1]);
        }
        idx--;
    }

    cout << "Subset elements:\n";
    for (int x : subset)
        cout << x << " ";
    cout << "\n";

    return 0;
}