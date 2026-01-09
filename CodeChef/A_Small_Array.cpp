#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<double> a(n);
    for (auto &x : a)
        cin >> x;
    double ans = (double)1e9;
    vector<double> prefix(n);
    vector<double> suffix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] + a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            ans = min(ans, (i > 0 ? prefix[i - 1] : 0) + (prefix[j] - (i > 0 ? prefix[i - 1] : 0)) / (x) + (j < n - 1 ? suffix[j + 1] : 0));
        }
    }
    cout << ans << "\n";
    return 0;
}