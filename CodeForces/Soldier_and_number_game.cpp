#include "bits/stdc++.h"
using namespace std;
#define int long long

const int N = 5e6;
vector<int> f, spf;

void precompute()
{
    spf.resize(N + 1);
    f.resize(N + 1, 0);

    for (int i = 2; i <= N; i++)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;

            if (1LL * i * i <= N)
            {
                for (int j = i * i; j <= N; j += i)
                {
                    if (spf[j] == 0)
                        spf[j] = i;
                }
            }
        }
    }

    f[1] = 1;
    f[2] = 1;
    f[3] = 1;

    for (int i = 4; i <= N; i++)
    {
        int v = i;

        while (v > 1)
        {
            f[i]++;
            v /= spf[v];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        f[i] += f[i - 1];
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t;
    cin >> t;
    // for (int i = 1; i <= 6; i++)
    // {
    //     cout << f[i] << " ";
    // }
    // cout << "\n";
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << f[a] - f[b] << "\n";
    }
}