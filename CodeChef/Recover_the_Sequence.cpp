#include "bits/stdc++.h"
using namespace std;
vector<int> a;

/*
1. If first or last element is changed, then the diff set will have only 2 elements.
2. If any other element is changed, then the diff set will have only 3 elements.
3. Just simply use brute force, use evey element of set diff, and check if it matches or not.
*/

void solve()
{
    int n;
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    set<int> diff;
    for (int i = 1; i <= n - 1; i++)
    {
        diff.insert(a[i + 1] - a[i]);
    }
    if (diff.size() == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }
    else
    {
        if (diff.size() == 2)
        {
            a[1] = a[2] - (a[3] - a[2]);
            a[n] = a[n - 1] + (a[n - 1] - a[n - 2]);
            for (int i = 1; i <= n; i++)
            {
                cout << a[i] << " ";
            }
            cout << "\n";
            return;
        }

        for (auto &x : diff)
        {
            vector<int> b(n + 1);
            b[1] = a[1];
            for (int i = 2; i <= n; i++)
            {
                b[i] = b[i - 1] + x;
            }
            int cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                if (a[i] != b[i])
                {
                    cnt++;
                }
            }
            if (cnt <= 1)
            {
                for (int i = 1; i <= n; i++)
                {
                    cout << b[i] << " ";
                }
                cout << "\n";
                return;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}