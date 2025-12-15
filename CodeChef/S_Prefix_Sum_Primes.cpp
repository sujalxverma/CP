#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    string s = "1 1 1 2 ";

    int times1 = mp[1] / 3;
    int times2 = mp[2];

    if (times1 >= times2)
    {
        for (int i = 0; i < times2; i++)
        {
            cout << s;
        }
        // every 2 is used.
        mp[1] -= (times2 * 3);
        for (int i = 0; i < mp[1]; i++)
        {
            cout << "1 ";
        }
        cout << "\n";
        return 0;
    }

    else
    {
        for (int i = 0; i < times1; i++)
        {
            cout << s;
        }
        mp[1] -= (times1 * 3);

        mp[2] -= times1;

        
        
    }

    return 0;
}