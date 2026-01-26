#include "bits/stdc++.h"
using namespace std;

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
        string s;
        cin >> s;
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                cnt++;
                ans = max(cnt, ans);
            }
            else
            {
                ans = max(cnt, ans);
                cnt = 0;
            }
        }
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                break;
            }
            else
            {
                cnt++;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                break;
            }
            else
            {
                cnt++;
            }
        }
        ans = max(cnt, ans);
        cout << ans << "\n";
    }

    return 0;
}