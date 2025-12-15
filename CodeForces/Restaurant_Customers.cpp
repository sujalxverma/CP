#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        p.push_back({a, b});
    }
    sort(p.begin(), p.end());

    set<int> s;
    int ans = 1;
    s.insert(p[0].second);
    for (int i = 1; i < n; i++)
    {
        if (*s.rbegin() > p[i].first)
        {
            s.insert(p[i].second);
            while (*s.begin() < p[i].first)
            {
                s.erase(*s.begin());
            }
            int size = s.size();

            ans = max(ans, size);
        }else{
            s.clear();
            s.insert(p[i].second);
            ans = max(ans , 1);
        }
    }
    cout<<ans<<"\n";
    return 0;
}