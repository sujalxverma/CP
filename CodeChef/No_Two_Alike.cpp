#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
    }
    vector<int> fr(n + 1, 0);        // contain freq of each element
    vector<pair<int, int>> p(n + 1); // contain range of duplicates
    for (int i = 1; i <= n; i++)
    {
        fr[a[i]]++;
        if (fr[a[i]] == 1)
        {
            p[a[i]].first = i;
            p[a[i]].second = i;
        }
        else
        {
            p[a[i]].second = i;
        }
    }

    sort(p.begin() + 1, p.end());

    vector<pair<int, int>> ans;
    pair<int, int> prev;
    for (auto [x, y] : p)
    {
        if (x != 0 && y != 0)
        {

            prev = {x, y};
            break;
        }
    }
    for (auto &[x, y] : p)
    {
        if (x == 0 && y == 0)
            continue;
        if (x <= prev.second)
        {
            prev.first = min(prev.first, x);
            prev.second = max(prev.second, y);
        }
        else
        {
            ans.push_back(prev);
            prev = {x, y};
        }
    }

    ans.push_back(prev);

    set<int> s;
    int count = 0;
    for (auto [x, y] : ans)
    {
        if (x == y)
        {

            continue;
        }
        for (int i = x; i <= y; i++)
        {
            s.insert(a[i]);
        }
        count += (int)s.size();
        s.clear();
    }
    cout << count << "\n";
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