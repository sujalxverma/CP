#include "bits/stdc++.h"
using namespace std;

// f(i): best total starting from index i.
// mapIndex[val] = sorted indices where a[idx] == val
// mapPosition[idx] = position of idx in mapIndex[a[idx]]
int f(const vector<int> &a, int index,
      vector<int> &dp,
      const unordered_map<int, vector<int>> &mapIndex,
      const unordered_map<int, int> &mapPosition)
{
    int n = (int)a.size();
    if (index >= n)
        return 0; // base [1]
    if (dp[index] != -1)
        return dp[index]; // memo [5]

    int nottake = f(a, index + 1, dp, mapIndex, mapPosition); // skip [1]

    int take = 0;
    int current = a[index];
    auto it = mapIndex.find(current);
    if (it != mapIndex.end())
    {                                            // positions list exists [6]
        const vector<int> &posList = it->second; // sorted absolute indices [1]
        auto itPos = mapPosition.find(index);
        if (itPos != mapPosition.end())
        {                                                 // guard instead of .at [3][4]
            int position = itPos->second;                 // index in posList [2]
            int lastPosInList = position + (current - 1); // need current copies total [1]
            if (lastPosInList < (int)posList.size())
            {
                int lastIdx = posList[lastPosInList];                        // absolute index in a [1]
                int nextIndex = lastIdx + 1;                                 // move to element after the group [1]
                take = current + f(a, nextIndex, dp, mapIndex, mapPosition); // commit group [1][5]
            }
        }
    }

    return dp[index] = max(nottake, take); // store and return [5]
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    // Build value -> positions list (sorted by construction)
    unordered_map<int, vector<int>> mapIndex;
    mapIndex.reserve(n * 2);
    for (int i = 0; i < n; ++i)
    {
        mapIndex[a[i]].push_back(i); // stores all indices at which a[i] is located.
    }

    // Build absolute index -> position in its value list
    unordered_map<int, int> mapPosition;
    mapPosition.reserve(n * 2);
    for (auto &kv : mapIndex)
    {
        const vector<int> &v = kv.second;
        for (int i = 0; i < (int)v.size(); ++i)
        {
            mapPosition[v[i]] = i; // stores the position of index 'i' in the element's vector.
            // a[i] ke vector mein ye index kis position par hai.
        }
    }

    vector<int> dp(n, -1);
    int ans = f(a, 0, dp, mapIndex, mapPosition);
    cout << ans << '\n';
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
}
