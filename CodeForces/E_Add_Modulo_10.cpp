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
        vector<int> f(10, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            f[a[i] % 10]++;
        }
        sort(a.begin(), a.end());
        set<int> s;
        if (f[5] > 0 || f[0] > 0)
        {
            for (int i = 0; i < n; i++)
            {
                a[i] += (a[i] % 10);
                s.insert(a[i]);
            }
            if ((int)s.size() > 1)
            {
                cout << "NO\n";
            }
            else if ((int)s.size() == 1)
            {
                cout << "YES\n";
            }
        }
        
        else
        {
            // make all uninary digit to be 2.
            for (int i = 0; i < n; i++)
            {
                if (a[i] % 2 != 0)
                {
                    a[i] += (a[i] % 10);
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 1; j <= 4; j++)
                {
                    if (a[i] % 10 == 2)
                    {
                        break;
                    }
                    else
                    {
                        a[i] += (a[i] % 10);
                    }
                }
                s.insert(a[i] % 20);
            }
            if ((int)s.size() > 1)
            {
                cout << "NO\n";
            }
            else if ((int)s.size() == 1)
            {
                cout << "YES\n";
            }
        }
    }
    return 0;
}