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
        ll sum = 0;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (n == 2 || n == 1)
        {
            cout << sum << "\n";
            continue;
        }
        ll total = a[0];
        ll prev = a[0];
        int idx = max_element(a.begin(), a.end()) - a.begin();
        for (int i = 1; i <= idx; i++)
        {
            if (a[i] > prev)
            {
                prev = a[i];
                total += a[i];
            }
            else
            {
                total += prev;
            }
        }
        if (idx == n - 1)
        {
            cout << max(sum, total) << "\n";
            continue;
        }
        prev = a[n - 1];
        total += a[n - 1];
        for (int i = n - 2; i > idx; i--)
        {
            if (prev < a[i])
            {
                prev = a[i];
                total += a[i];
            }
            else
            {
                total += prev;
            }
        }
        cout << max(sum, total) << "\n";
    }
    return 0;
}