#include "bits/stdc++.h"
using namespace std;

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
        vector<int> f(12, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            f[x]++;
        }
        int ans = 0;
        for (int i = 1; i <= 11; i++)
        {
            if (f[i] > 0)
            {
                ans = f[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}