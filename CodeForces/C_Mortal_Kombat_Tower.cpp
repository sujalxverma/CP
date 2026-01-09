#include "bits/stdc++.h"
using namespace std;

const int maxN = 200005;
// memoisation
int f(vector<int> &a, int idx, int chance, vector<vector<int>> &dp)
{
    if (idx >= (int)a.size())
    {
        return 0;
    }

    if (dp[chance][idx] != -1)
    {
        return dp[chance][idx];
    }

    int ans1 = 0;
    int ans2 = 0;
    if (chance == 0)
    { // bro
        // one kill

        if (a[idx] == 1)
        {
            ans1 = 1 + f(a, idx + 1, !chance, dp);
        }
        else
        {
            ans1 = 0 + f(a, idx + 1, !chance, dp);
        }

        // two kill
        if (idx + 1 < (int)a.size() && a[idx] == 1 && a[idx + 1] == 1)
        {
            // uses 2 skips to kill 2 hard boses.
            ans2 = 2 + f(a, idx + 2, !chance, dp);
        }
        else if (idx + 1 < (int)a.size() && a[idx] == 1 && a[idx + 1] == 0)
        {
            ans2 = 1 + f(a, idx + 2, !chance, dp);
        }
        else if (idx + 1 < (int)a.size() && a[idx] == 0 && a[idx + 1] == 0)
        {
            ans2 = 0 + f(a, idx + 2, !chance, dp);
        }
        else if (idx + 1 < (int)a.size() && a[idx] == 0 && a[idx + 1] == 1)
        {
            ans2 = 1 + f(a, idx + 2, !chance, dp);
        }
        else
        {
            if (a[idx] == 1)
            {
                ans2 = 1 + f(a, idx + 1, !chance, dp);
            }
            else
            {
                ans2 = 0 + f(a, idx + 1, !chance, dp);
            }
        }
    }
    else
    {
        // you
        ans1 = 0 + f(a, idx + 1, !chance, dp);

        // two kill
        if (idx + 1 < (int)a.size())
        {
            // use only one.
            ans2 = 0 + f(a, idx + 2, !chance, dp);
        }
        else
        {
            ans2 = 0 + f(a, idx + 1, !chance, dp);
        }
    }

    return dp[chance][idx] = min(ans1, ans2);
}

// tabulation
int f_tab(vector<int> &a)
{
    int n = (int)a.size();
    vector<vector<int>> dp(2, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int chance = 0; chance <= 1; chance++)
        {
            int ans1 = 0;
            int ans2 = 0;
            if (chance == 0)
            {
                // one kill
                if (a[i] == 1)
                    ans1 = 1 + dp[!chance][i + 1];
                else
                    ans1 = 0 + dp[!chance][i + 1];

                // two kill
                if (i + 1 < (int)a.size())
                {
                    if (a[i] == 1 && a[i + 1] == 1)
                        ans2 = 2 + dp[!chance][i + 2];
                    else if (a[i] == 0 && a[i + 1] == 0)
                        ans2 = 0 + dp[!chance][i + 2];
                    else
                        ans2 = 1 + dp[!chance][i + 2];
                }
                else
                {
                    if (a[i] == 1)
                        ans2 = 1 + dp[!chance][i + 1];
                    else
                        ans2 = 0 + dp[!chance][i + 1];
                }
            }
            else
            {
                // one kill
                ans1 = 0 + dp[!chance][i + 1];

                // two kill
                if (i + 1 < (int)a.size())
                {

                    ans2 = 0 + dp[!chance][i + 2];
                }
                else
                {

                    ans2 = 0 + dp[!chance][i + 1];
                }
            }

            dp[chance][i] = min(ans1, ans2);
        }
    }

    return dp[0][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
        {
            cin >> x;
        }
        if (n == 1)
        {
            if (a[0] == 1)
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << "0\n";
            }
            continue;
        }
        vector<vector<int>> dp(2, vector<int>(n, -1));
        // 0->friend , 1->you
        // int ans = f(a, 0, 0, dp);
        int ans = f_tab(a);
        cout << ans << "\n";
    }
    return 0;
}