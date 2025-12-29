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
        vector<int> a(4, 0);
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            a[k % 4]++;
        }
        int steps = 0;
        int c1 = a[1];
        int c2 = a[2];
        int c3 = a[3];
        // first see, if it is pausible to remove them.
        if ((c1 + c2 * 2 + c3 * 3) % 4 != 0)
        {
            cout << "-1\n";
            continue;
        }
        // 1 step.
        steps += (c2 / 2);
        c2 = c2 % 2;
        int x = min(c3, c1);
        steps += x;
        c3 -= x;
        c1 -= x;

        // 2 step.
        if (c2 == 1)
        {
            if (c1 >= 2)
            {
                c1 -= 2;
                steps += 2;
            }
            else if (c3 >= 2)
            {
                c3 -= 2;
                steps += 2;
            }
            else
            {
                cout << "-1\n";
                continue;
            }
        }

        // 3 step.
        steps += 3 * (c3 / 4);
        steps += 3 * (c1 / 4);

        cout << steps << "\n";
    }
    return 0;
}