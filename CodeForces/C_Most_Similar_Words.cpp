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
        int n, m;
        cin >> n >> m;

        vector<string> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int mini = 1e9;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sum = 0;

                for (int k = 0; k < m; k++)
                {
                    sum += abs(a[i][k] - a[j][k]);
                }

                mini = min(mini, sum);
            }
        }

        cout << mini << "\n";
    }

    return 0;
}
