#include "bits/stdc++.h"
using namespace std;
struct pair_hash
{
    size_t operator()(const pair<int, int> &p) const
    {
        return hash<long long>()(
            ((long long)p.first << 32) ^ p.second);
    }
};
unordered_map<pair<int, int>, int, pair_hash> dp;
vector<int> a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.count(a[i] - 1))
        {
            ans = max({ans, mp[a[i] - 1] + 1, 1});
            mp[a[i]] = mp[a[i] - 1] + 1;
        }else{
            ans = max(ans , 1);
            mp[a[i]] = 1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}