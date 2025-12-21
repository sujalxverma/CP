#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, sum;
    cin >> n >> sum;
    int ogsum = sum;
    vector<int> a(n);
    for (int i = 0; i < n - 1; i++)
    {
        a[i] = 1;
        sum--;
    }
    if ((n - 1) >= (ogsum / 2))
    {
        cout << "NO\n";
        return 0;
    }
    a[n - 1] = sum;
    cout << "YES\n";
    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << "\n";
    cout << ogsum / 2 << "\n";

    return 0;
}