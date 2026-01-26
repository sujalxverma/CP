#include "bits/stdc++.h"
using namespace std;
vector<int> a, b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        b.resize(n + 1);
        a.resize(n + 1); // permuatation
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        for (int i = 1; i <= n; i++)
        {
            a[i] = i;
        }

        int ans = 0;
        do
        {

            bool f = true;
            for (int i = 1; i <= n; i++)
            {
                if (b[i] != 0 && b[i] != a[i])
                {
                    f = false;
                    break;
                }
            }
            if (!f)
            {
                continue;
            }
            else
            {
                int cnt = 0;
                for (int i = 1; i < n; i++)
                {
                    if (a[i] < a[i + 1])
                    {
                        cnt++;
                    }
                }
                if (cnt == k)
                {
                    ans++;
                }
            }

        } while (next_permutation(a.begin() + 1, a.end()));
        cout << ans << "\n";
    }
    return 0;
}