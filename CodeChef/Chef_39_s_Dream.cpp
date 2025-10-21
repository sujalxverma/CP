#include "bits/stdc++.h"
using namespace std;

// it subarray , not subsequence.
void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    std::vector<int> a(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]].push_back(i + 1);
    }

    int ans = 0;
    for (auto it : mp)
    {
        vector<int> v = it.second;
        int c = 0;
        int s = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] - v[s] + 1 > k)
            {
                c++;
                s = i;
            }
        }
        c++;
        ans += c;
    }
    cout << ans << "\n";
}

int main()
{
    // your code goes here
    int t = 1;
    // 	cin >> t;
    while (t--)
    {
        solve();
    }
}
