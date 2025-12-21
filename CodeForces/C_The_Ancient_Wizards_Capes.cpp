#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll mod = 676767677;
// N
// answers  -> 0 , 1 , 2

/*
Approach Overview
-----------------

We are given an array a[1..n], where a[i] denotes the number of visible wizards
when Harry stands at position i. Each wizard wears a cape either to the left (0)
or to the right (1).

Key Observations
----------------
1) When Harry moves from position i to i+1, only wizards i and i+1 can change
   visibility. Therefore, the visibility difference satisfies:
        |a[i+1] - a[i]| <= 1
   If this condition is violated for any i, the answer is -1.

2) The change in visibility depends only on the cape directions of wizard i
   and wizard i+1:
        - both capes to the left  -> visibility increases by 1
        - both capes to the right -> visibility decreases by 1
        - capes differ            -> visibility remains the same

3) From the above, we can derive the cape transition rule:
        - If a[i] == a[i-1], the capes at i-1 and i must be different
        - If a[i] != a[i-1], the capes at i-1 and i must be the same

   Hence, once the cape direction of wizard 1 is fixed, the entire cape
   arrangement is uniquely determined.

Algorithm
---------
1) First, verify that |a[i+1] - a[i]| <= 1 for all i. If not, print -1.
2) Try both possible cape directions for wizard 1 (0 and 1).
3) For each choice, construct the cape array using the transition rule above.
4) Simulate Harry’s walk from position 1 to n, maintaining the number of visible
   wizards and checking whether it matches a[i] at every position.
5) Count how many of the two constructions are valid.

Correctness
-----------
The solution is correct because:
- Visibility changes are fully determined by adjacent cape directions.
- There are at most two possible cape configurations.
- Each configuration is explicitly verified by simulation.

Complexity
----------
For each test case:
- Time complexity: O(n)
- Space complexity: O(n)
*/



bool check(vector<int> &cape, vector<int> &a)
{

    int vis = 1;
    int n = a.size() - 1;

    for (int i = 2; i <= n; i++)
    {
        if (cape[i] == 1)
        {
            vis++;
        }
    }
    if (vis != a[1])
    {
        return false;
    }

    for (int i = 1; i < n; i++)
    {
        if (cape[i] == 1 && cape[i + 1] == 1)
        {
            vis--;
        }
        else if (cape[i] == 0 && cape[i + 1] == 0)
        {
            vis++;
        }

        if (a[i + 1] != vis)
        {
            return false;
        }
    }

    return true;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++)
    {
        if (abs(a[i + 1] - a[i]) > 1)
        {
            cout << 0 << "\n";
            return;
        }
    }

    int ans = 0;

    for (int start = 0; start <= 1; start++)
    {
        vector<int> cape(n + 1);
        cape[1] = start;

        for (int i = 2; i <= n; i++)
        {
            if (a[i] == a[i - 1])
            {
                cape[i] = !cape[i - 1];
            }
            else
            {
                cape[i] = cape[i - 1];
            }
        }

        if (check(cape, a))
        {
            ans++;
        }
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