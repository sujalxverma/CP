#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<int, int>> seg;
    int a = -1;
    int b = -1;
    bool f = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1' && f == false)
        {
            a = i;
            b = i;
            f = true;
        }
        else if (s[i] == '1' && f == true)
        {
            b = i;
        }
        else
        {
            if (f)
            {
                seg.push_back({a, b});
                f = false;
            }
        }
    }
    if (f)
    {
        seg.push_back({a, b});
    }
    // for (auto x : seg)
    // {
    //     cout << x.first << " " << x.second << " : ";
    // }
    // cout << "\n";

    int ans = 0;

    if (seg.size() == 0)
    {
        // zero #1.
        ans++;
        int d = k + 1;
        for (int i = 1; i < n; i++)
        {
            d--;
            if (d == 0)
            {
                ans++;
                d = k + 1;
            }
        }
        cout << ans << "\n";
        return;
    }

    // check left side.
    if (seg[0].first > 0)
    {
        int l = seg[0].first;
        int d = k + 1;
        for (int i = l - 1; i >= 0; i--)
        {
            d--;
            if (d == 0)
            {
                ans++;
                d = k + 1;
            }
        }
    }
    // check for right.
    if (seg[seg.size() - 1].second < n - 1)
    {
        int l = seg[seg.size() - 1].second;
        int d = k + 1;
        for (int i = l + 1; i < n; i++)
        {
            d--;
            if (d == 0)
            {
                ans++;
                d = k + 1;
            }
        }
    }

    // in b/w
    // for (int i = 0; i < seg.size() - 1; i++)
    // {
    //     int r1 = seg[i].second;
    //     int l2 = seg[i + 1].first;
    //     int r = l2 - r1 - 1;

    //     int st = r1 + 1;
    //     int ed = l2 - 1;
    //     int d = k + 1;
    //     int chance = 0;

    //     while (st < ed)
    //     {
    //         if (chance == 0)
    //         {
    //             // left side.
    //             d--;

    //             if (st >= ed)
    //             {
    //                 break;
    //             }
    //             st++;
    //             if (d == 0)
    //             {
    //                 ans++;
    //                 chance = 1;
    //                 d = k + 1;
    //             }
    //         }
    //         else
    //         {
    //             d--;
    //             if (st >= ed)
    //             {
    //                 break;
    //             }
    //             ed--;
    //             if (d == 0)
    //             {
    //                 ans++;
    //                 d = k+1;
    //                 chance = 0;
    //             }
    //         }
    //     }
    // }
    for (int i = 0; i + 1 < seg.size(); i++)
    {
        int r1 = seg[i].second;
        int l2 = seg[i + 1].first;

        int gap = l2 - r1 - 1;
        int can = max(0, (gap - k) / (k + 1));
        ans += can;
    }

    cout << ans << "\n";
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