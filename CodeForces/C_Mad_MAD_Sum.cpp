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
        int n;
        cin >> n;
        vector<ll> a(n);
        set<ll> s;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }

        ll sum = 0;
        /*
        if all elements are distinct, then only one iteration.
        */
        // Using Brute Force.
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        }
        if ((int)s.size() == n)
        {
            // only one iteration.

            cout << sum << "\n";

            continue;
        }
        vector<ll> b(n);
        map<ll, ll> mp;
        ll maxi = 0;
        // created for first iteration.
        for (int i = 0; i < n; i++)
        {
            mp[a[i]]++;
            if (mp[a[i]] >= 2)
            {
                b[i] = max(a[i], maxi);
                maxi = max(a[i], maxi);
            }
            else
            {
                b[i] = maxi;
            }
        }

        
        
    }
    return 0;
}