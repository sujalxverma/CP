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
        ll m;
        cin >> m;
        ll sum = 0;
        int idx = -1;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
           
        }

        for (int i = 0; i < n; i++)
        {

            sum += a[i];
            if (sum > m)
            {
                idx = i;
                break;
            }
        }
        if (sum <= m)
        {
            cout << "0\n";
        }
        else
        {
            cout << max_element(a.begin(), a.begin() + idx + 1) - a.begin() + 1 << "\n";
        }
    }
    return 0;
}