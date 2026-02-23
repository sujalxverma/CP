#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    int odd = 0;
    int even = 0;
    for (auto &x : a)
    {
        cin >> x;
        if (x % 2)
            odd++;
        else
            even++;
    }
    sort(a.begin(), a.end());
    // 2 <= x <= (1<<64)
    // when answer is 2, if all are odd.
    if (odd == n)
    {
        cout << "2\n";
        return;
    }
    
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

