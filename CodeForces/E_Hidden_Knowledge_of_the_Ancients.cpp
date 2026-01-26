#include "bits/stdc++.h"
using namespace std;
vector<int> a, b;

/*
1. The range should be b/w l and r.
2. So, we can calculate the first index x where dsitinct element is k.
3. And y is last index where distinct element is k.
4. Now there are cases, like :
5. maybe x and y both lie within, l and r.
6. or it can be they overlap, or completely out of range.
7. say, for index i -> l <= j-i+1 <= r.
8. therefore, l+i-1 <= j <= r+i-1.
9. Thus roughly : 
10. L = min(x,j-i+1) , R = max(y,r+i-1)
11. ans += (R-L+1)
*/


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, l, r;
        cin >> n >> k >> l >> r;
        a.resize(n);
        for (auto &x : a)
            cin >> x;
        b = a;
        sort(begin(b), end(b));
        b.erase(unique(begin(b), end(b)), end(b));
        int size = (int)b.size();
        for (int i = 0; i < n; i++)
        {
            a[i] = lower_bound(begin(b), end(b), a[i]) - begin(b);
        }
        vector<int> fr_x(n + 1, 0);
        vector<int> fr_y(n + 1, 0);
        int x = 0;
        int y = 0;
        int distinct_x = 0;
        int distinct_y = 0;

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            while (y < n && distinct_y <= k)
            {
                if (fr_y[a[y]] == 0)
                {
                    if (distinct_y == k)
                        break;
                    distinct_y++;
                }
                fr_y[a[y]]++;
                y++;
            }
            while (x < n && distinct_x < k)
            {
                fr_x[a[x]]++;
                if (fr_x[a[x]] == 1)
                {
                    distinct_x++;
                }

                x++;
            }

            if (distinct_x == k)
            {
                int L = max(l + i - 1, x - 1);
                int R = min(r + i - 1, y - 1);

                if (L <= R)
                {
                    ans += 1LL * (R - L + 1);
                }
            }

            fr_x[a[i]]--;
            fr_y[a[i]]--;

            if (fr_x[a[i]] == 0)
            {
                distinct_x--;
            }
            if (fr_y[a[i]] == 0)
            {
                distinct_y--;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}