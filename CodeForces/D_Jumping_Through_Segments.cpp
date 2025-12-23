#include "bits/stdc++.h"
using namespace std;

bool f(vector<pair<int,int>>& a, int k)
{   
    pair<int,int>seg = {0,0};
    int n = (int)a.size();
    for(int j = 1 ; j <= n ; j++){
        int i = j-1;
        seg.first -= k;
        seg.second += k;

        seg.first = max(seg.first , a[i].first);
        seg.second = min(seg.second , a[i].second);

        if(seg.first > seg.second){
            return false;
        }

    }

    return true;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first;
            cin >> p[i].second;
        }

        int s = 0;
        int e = 1e9;
        int ans = 0;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (f(p, m))
            {
                ans = m;
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}