#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.length();

    int c = 1;
    vector<pair<int, int>> p;
    int prev = s[0] - '0';
    for (int i = 1; i < n; i++)
    {
        int val = s[i] - '0';
        if (val == prev)
        {
            c++;
        }
        else
        {
            p.push_back({prev, c});
            c = 1;
            prev = val;
        }
    }
    p.push_back({prev, c});
    for (auto [x, y] : p)
    {
        // cout<<x<<" "<<y<<"\n";
    }
    int ans = 0;
    for (int i = 0; i < p.size() - 1; i++)
    {
        int v1 = p[i].first;
        int v2 = p[i + 1].first;
        if (v1 + 1 == v2)
        {
            ans += min(p[i].second, p[i + 1].second);
        }
    }
    cout << ans << "\n";
    return 0;
}