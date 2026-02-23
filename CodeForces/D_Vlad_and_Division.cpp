#include "bits/stdc++.h"
using namespace std;
using ll = long long;

/*
Goal:
We want to form groups such that within a group,
every bit position differs between the two numbers.

Observation:
If two numbers differ in every bit (for 31 bits),
then one number must be the bitwise complement of the other
within those 31 bits.

Therefore:
- Maximum size of each group is 2.
- For a number x, its partner must be its 31-bit complement.

Approach:
1. Store frequency of each number using a map.
2. Traverse the sorted array.
3. For each unused number x:
   - Compute its 31-bit complement 'num'.
   - If complement exists and is unused,
     pair them in one group.
   - Otherwise, x forms a group alone.
4. Count total number of groups.
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
        vector<ll> a(n);
        map<ll, ll> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }

        sort(begin(a), end(a));

        int ans = 0;
        for (auto &x : a)
        {
            if (mp[x] == 0)
            {
                continue;
            }
            ll num = 0;
            for (int i = 0; i < 31; i++)
            {
                if (!((1LL << i) & x))
                {
                    num |= (1LL << i);
                }
            }
            if (mp.count(num))
            {
                if (mp[num] == 0)
                {
                    ans++;
                    mp[x] -= 1;
                }
                else
                {
                    ans++;
                    mp[x] -= 1;
                    mp[num] -= 1;
                }
            }
            else
            {
                ans++;
                mp[x] -= 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}