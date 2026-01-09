#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int maxN = 1e5;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    vector<int> dp(maxN, 0);
    dp[0] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = sum; j >= a[i]; j--)
        {
            dp[j] = dp[j] || dp[j - a[i]];
        }
    }
    int count = 0;
    for (int i = 1; i <= sum; i++)
    {
        if (dp[i] == 1)
        {
            count++;
        }
    }
    cout << count << "\n";
    for (int i = 1; i <= sum; i++)
    {
        if (dp[i] == 1)
        {
            cout << i << " ";
        }
    }
    return 0;
}