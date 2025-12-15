#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        mp[k]++;
    }
    if (mp[1] == 0)
    {

        for (int i = 0; i < mp[2]; i++)
        {
            cout << 2 << " ";
        }
        cout << "\n";
        return 0;
    }
    if (mp[2] == 0)
    {

        for (int i = 0; i < mp[1]; i++)
        {
            cout << 1 << " ";
        }
        cout << "\n";
        return 0;
    }
    cout << "2 1" << " ";
    for (int i = 0; i < mp[2] - 1; i++)
    {
        cout << "2 ";
    }
    for (int i = 0; i < mp[1] - 1; i++)
    {
        cout << "1 ";
    }
    cout << "\n";
    return 0;
}