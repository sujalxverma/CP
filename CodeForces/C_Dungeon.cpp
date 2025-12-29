#include "bits/stdc++.h"
using namespace std;

/*
Each sword can be used to kill only one monster, if it kills it, then max(sword, magic) gets into the weapons.
We cannot sum up some swords power and then kill a songle  monster.


1. First kill monster with c[i] > 0, cause we have chance to regain a better sword.
2. Then kill c[i] == 0, cause we will not be able to gain any sword, and will lose this sword as well.
*/
//

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        multiset<int> s;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            s.insert(x);
        }

        vector<pair<int, int>> p(m);

        for (int i = 0; i < m; i++)
        {
            cin >> p[i].first;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> p[i].second;
        }
        sort(p.begin(), p.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 if (a.first != b.first)
                     return a.first < b.first; // ascending by first
                 return a.second > b.second;   // descending by second
             });

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            if (p[i].second == 0)
                continue;
            int monster = p[i].first;
            auto it = s.lower_bound(monster);

            if (it == s.end())
                break;

            s.insert(max(p[i].second, *it));
            s.erase(it); // sword is consumed

            ans++;
        }

        for (int i = 0; i < m; i++)
        {
            if (p[i].second == 0)
            {
                int monster = p[i].first;
                auto it = s.lower_bound(monster);

                if (it == s.end())
                    break;

                // s.insert(max(p[i].second, *it));
                s.erase(it); // sword is consumed

                ans++;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}