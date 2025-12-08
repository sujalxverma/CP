#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int idx = 0;
    for (int i = 1; i <= n; i++)
    {
        int v = i + a[i] - 1;
        if (i != 1 && idx < i)
        {
            break;
        }
        if (idx < v)
        {
            idx = v;
        }
        // cout<<idx<<"\n";
    }
    if (idx >= n)
    {
        cout << n << "\n";
    }
    else
    {
        cout << idx << "\n";
    }
    return 0;
}