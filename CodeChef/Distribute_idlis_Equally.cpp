#include "bits/stdc++.h"
using namespace std;

/*
1. Greedy Approach, just select the max and min ,and do operation on them.
2. B/c selecting them, will result in more value change.
3. when max==min, return ans.
*/

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
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % n != 0)
        {
            cout << "-1\n";
            continue;
        }
        sort(a.begin(), a.end());
        int ans = 0;
        bool f = true;
        while (f)
        {
            int mini = min_element(a.begin(), a.end()) - a.begin();
            int maxi = max_element(a.begin(), a.end()) - a.begin();

            if (mini == maxi)
            {
                break;
            }
            int value = (a[maxi] - a[mini] + 1) / 2;
            a[mini] += value;
            a[maxi] -= value;

            ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}