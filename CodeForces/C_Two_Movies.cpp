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
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int first = 0;
        int second = 0;
        int ans = -1e8;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == -1 && b[i] == -1)
            {
                if (first >= second)
                {
                    first--;
                }
                else
                {
                    second--;
                }
            }
            else if (a[i] == 1 && b[i] != 1)
            {
                first++;
            }
            else if (a[i] != 1 && b[i] == 1)
            {
                second++;
                // do nothing
            }
            ans = max(ans, min(first, second));
        }
        cout<<ans<<"\n";
    }
    return 0;
}