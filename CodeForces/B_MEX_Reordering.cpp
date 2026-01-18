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
        int o = 0;
        int z = 0;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            if (k == 0)
                z++;
            else if (k == 1)
            {
                o++;
            }
        }
        if (z == 1)
        {
            cout << "Yes\n";
        }
        else if (z > 1 && o >= 1)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}