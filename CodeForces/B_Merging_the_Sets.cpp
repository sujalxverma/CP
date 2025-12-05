#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> v(n);
    vector<int> f(m, 0);
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;

        for (int j = 0; j < s; j++)
        {
            int k;
            cin >> k;
            f[k]++;
            v[i].insert(k);
        }
    }
    // if any number is not present in any of the set.
    for (int i = 0; i < m; i++)
    {
        if (f[i] == 0)
        {
            cout << "NO\n";
            return;
        }
    }

    // each set has unique elements, no repeition.
    set<int> superSet; // superSet.insert(s1.begin(), s1.end());
    for (int i = 1; i <= m; i++)
    {
        superSet.insert(i);
    }

    sort(v.begin(), v.end(), [](const set<int> &a, const set<int> &b)
         {
             return a.size() > b.size(); // descending sets on the basis of set size
         });

    // if first set is of size m, its YES
    if (v[0].size() == m)
    {
        cout << "YES\n";
        return;
    }

    set<int> temp;

    set_difference(
        superSet.begin(), superSet.end(),
        v[0].begin(), v[0].end(),
        inserter(temp, temp.begin()));

    superSet = std::move(temp); // store back into s1
   
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