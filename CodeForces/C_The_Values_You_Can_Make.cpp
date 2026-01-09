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
    int k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    //This code only generates sums that can be made by taking any coins; it completely ignores the sum = k condition.
    bitset<100000> dp;
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        dp = dp | (dp << a[i]);
    }

    for (int i = 0; i <= k; i++)
    {
        cout << i << " ";
    }
    return 0;
}