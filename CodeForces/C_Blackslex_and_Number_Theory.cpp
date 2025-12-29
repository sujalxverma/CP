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

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(begin(a), end(a));
        if (a[1] - a[0] <= a[0])
        {
            cout << a[0] << "\n";
        }
        else
        {
            cout << (a[1] - a[0]) << "\n";
        }
    }
    return 0;
}