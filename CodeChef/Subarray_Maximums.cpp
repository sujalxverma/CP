#include "bits/stdc++.h"
using namespace std;
vector<int> p;
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
        int o = 0;
        int z = 0;
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                o++;
                nums.push_back(i + 1);
            }
            else
            {
                z++;
            }
        }
        sort(nums.begin(), nums.end());
        if (o == n || z == n || s[0] == '0' || s[n - 1] == '0')
        {
            cout << "-1\n";
            continue;
        }
        p.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            p[i] = 0;
        }
        int m = (int)nums.size();

        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == '0')
            {
                int idx = lower_bound(begin(nums), end(nums), i) - nums.begin();
                p[i] = nums[idx];
            }
        }
        set<int> st;
        for (int i = 1; i <= n; i++)
        {

            st.insert(i);
        }
        for (int i = 1; i <= n; i++)
        {
            if (p[i] != 0)
            {
                st.erase(p[i]);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (p[i] == 0)
            {
                p[i] = *st.begin();
                st.erase(st.begin());
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}