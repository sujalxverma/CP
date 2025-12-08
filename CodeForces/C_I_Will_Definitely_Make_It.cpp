#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> b;
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > a[k])
        {
            s.insert(a[i]);
        }
    }
    for (auto x : s)
    {
        b.push_back(x);
    }
    if (b.size() == 0)
    {
        cout << "YES\n";
        return;
    }
    sort(b.begin(), b.end());
    int w = 0;
    int current = a[k];

    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] - current > current - w)
        {
            cout << "NO\n";
            return;
        }
        else
        {
            w = b[i] - current + w;
            current = b[i];
        }
        // cout<<current<<" "<<w<<"\n";
    }
    cout << "YES\n";
    
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