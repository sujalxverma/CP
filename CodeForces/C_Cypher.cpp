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
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        vector<string> g(n);
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            string s;
            cin >> s;
            g[i] = s;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < g[i].size(); j++)
            {
                if (g[i][j] == 'U')
                {
                    // move down
                    a[i] = (a[i] - 1 + 10) % 10;
                }
                else
                {
                    // move up
                    a[i] = (a[i] + 1) % 10;
                }
            }
        }

        for (auto &x : a)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}