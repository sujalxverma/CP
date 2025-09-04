#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }
    vector<int> modulo(n);
    for (int i = 0; i < n; i++)
    {
        modulo[i] = prefix[i] % n;
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[modulo[i]].push_back(i + 1);
    }

    for (int i = 0; i < n; i++)
    {
        if (modulo[i] == 0)
        {
            cout << i + 1 << "\n";
            for (int j = 1; j <= i + 1; j++)
            {
                cout << j << " ";
            }
            cout << "\n";
            return;
        }
    }
     for (int i = 0; i < n; i++)
    {
        if (a[i] % n == 0)
        {
            cout << 1 << "\n";
            cout << i + 1 << "\n";
            return;
        }
    }
    for (auto it : mp)
    {
        if (it.second.size() >= 2)
        {
            cout << it.second.back() - it.second.front() + 1 << endl;
            for (auto i = it.second.front(); i <= it.second.back(); i++)
            {
                cout << i << " ";
            }
            cout << "\n";
            return;
        }
    }
   
    cout << -1 << "\n";
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
