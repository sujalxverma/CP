#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a]++;
        v[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0)
        {
            cout << n - 1 << "\n";
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                cout << i << " " << j << "\n";
            }
            return 0;
        }
    }
    return 0;
}