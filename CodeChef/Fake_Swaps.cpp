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
        string s, k;
        cin >> s >> k;
        int z = 0;
        int o = 0;
        for (int i = 0; i < n; i++)
        {
            if (k[i] == '0')
                z++;
            else
                o++;
        }

        if (s != k && (z == 0 || o == 0))
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}