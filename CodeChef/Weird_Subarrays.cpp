#include "bits/stdc++.h"
using namespace std;
using ll = long long;
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        ll ans = 0;
        vector<int> hills;
        hills.push_back(0);
        for (int i = 1; i < n - 1; i++)
        {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                hills.push_back(i);
            }
        }
        hills.push_back(n - 1);
        ans += n; // indidvidual contribution.

        for (int i = 0; i < (int)hills.size() - 1; i++)
        {
            int len = (hills[i + 1] - hills[i] + 1);
            ans += ll(len * (len - 1) / 2);
        }
        cout << ans << "\n";
    }
    return 0;
}