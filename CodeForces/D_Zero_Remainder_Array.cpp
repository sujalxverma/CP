#include "bits/stdc++.h"
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    ll k;
    cin >> k;
    int a[n];

    vector<int> rem;
    for (uint32_t i = 0; i < (uint32_t)n; i++)
    {
        cin >> a[i];
        a[i] = k - (a[i] % k);
        if (a[i] != k)
        {
            rem.push_back(a[i]);
        }
    }

    if ((int)rem.size() == 0)
    {
        cout << "0\n";
        return;
    }

    ll count = 0;
    sort(rem.begin(), rem.end());
    int elem = rem[0];
    int c = 1;
    for (size_t i = 1; i < rem.size(); i++)
    {
        if (rem[i] == elem)
        {
            c++;
        }
        else
        {
            count = max(count, (c - 1) * k + elem);
            elem = rem[i];
            c = 1;
        }
    }
    count = max(count, (c - 1) * k + elem);

    cout << count + 1 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}