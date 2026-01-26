#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, s;
    cin >> p >> s;

    vector<pair<int, int>> ans;

    for (int i = 0; i < p; i++)
    {
        vector<pair<int, int>> problem(s);

        // read scores
        for (int j = 0; j < s; j++)
            cin >> problem[j].first;

        // read solved counts
        for (int j = 0; j < s; j++)
            cin >> problem[j].second;

        // sort by score
        sort(problem.begin(), problem.end());

        int cnt = 0;
        for (int j = 1; j < s; j++)
        {
            if (problem[j].second < problem[j - 1].second)
                cnt++;
        }

        ans.push_back({cnt, i + 1});
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < p; i++)
        cout << ans[i].second << "\n";

    return 0;
}
