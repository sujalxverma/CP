#include "bits/stdc++.h"
using namespace std;
vector<long long> a;
/*
void solve(vector<long long> &a)
{
    // brute force.
    long long ans = 0;
    for (int i = 0; i < (int)a.size(); i++)
    {
        for (int j = i + 1; j < (int)a.size(); j++)
        {
            ans = max(ans, a[i] * a[j] + abs(a[i] - a[j]));
        }
    }
    cout<<ans<<"\n";
}
*/
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
        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(begin(a), end(a));

        cout << max(a[n - 1] * a[n - 2] + (a[n - 1] - a[n - 2]), a[0] * a[1] + (a[1] - a[0])) << "\n";

        // solve(a);
    }
    return 0;
}