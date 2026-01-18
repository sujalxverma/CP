#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll nearest_sq = 1;
        for (ll i = 1; i * i <= n; i++)
        {
            if (i * i <= n)
            {
                nearest_sq = i;
            }
        }
        string s = "";
        for (int i = 1; i <= nearest_sq; i++)
        {
            s += 'X';
        }
        for (int i = 1; i <= nearest_sq; i++)
        {
            s += 'D';
        }
        ll diff = n - nearest_sq * nearest_sq;
        if (diff == 0)
        {
            cout << s << "\n";
            continue;
        }
        if (diff > nearest_sq)
        {
            s = "X" + s;
            diff -= (nearest_sq);
            for (int i = 0; i < diff; i++)
            {
                cout << s[i];
            }
            cout << "D";
            for (int i = diff; i < s.length(); i++)
            {
                cout << s[i];
            }
            // cout<<s;
            cout << "\n";
            continue;
        }
        for (int i = 0; i < diff; i++)
        {
            cout << s[i];
        }
        cout << "D";
        for (int i = diff; i < s.length(); i++)
        {
            cout << s[i];
        }
        // cout<<s;
        cout << "\n";
    }
    return 0;
}