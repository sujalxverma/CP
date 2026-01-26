#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            a[i] = i;
        }
        int ans = 0;
        vector<int> ct(n + 1), cd(n + 1);

        do
        {
            vector<int> b(n + 1);
            for (int i = 1; i <= n; i++)
            {
                b[a[i]] = i;
            }
            int c = 0;
            for (int i = 1; i <= n - 1; i++)
            {
                if (a[i] < a[i + 1])
                {
                    c++;
                }
            }
            for (int i = 1; i <= n - 1; i++)
            {
                if (b[i] > b[i + 1])
                {
                    c++;
                }
            }
            // ans = max(ans,c);
            if (c > ans)
            {
                ans = c;
                // ct = a;
                for (int i = 1; i <= n; i++)
                {
                    ct[i] = a[i];
                    cd[i] = b[i];
                }
            }

        } while (next_permutation(a.begin() + 1, a.end()));
        for (int i = 1; i <= n; i++)
        {
            cout << ct[i] << " ";
        }
        cout<<"\n";
        for (int i = 1; i <= n; i++)
        {
            cout << cd[i] << " ";
        }
        cout << "\n";
        cout << ans << "\n";
    }
    return 0;
}