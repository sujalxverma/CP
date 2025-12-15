#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (abs(p[i] - p[i + 1]) >= 2)
        {
            cout << "Yes\n";
            cout << i + 1 << " " << i + 2 << "\n";
            return;
        }
    }

    int mini = 0;
    int maxi = 0;

    for (int i = 1; i < n; i++)
    {
        if (p[i] > p[maxi])
        {
            maxi = i;
            if (p[maxi] - p[mini] >= abs(maxi - mini) + 1)
            {
                cout << "Yes\n";
                cout << min(maxi, mini) + 1 << " " << max(mini, maxi) + 1 << "\n";
                return;
            }
        }
        else if (p[i] < p[mini])
        {
            mini = i;
            if (p[maxi] - p[mini] >= abs(maxi - mini) + 1)
            {
                cout << "Yes\n";
                cout << min(maxi, mini) + 1 << " " << max(mini, maxi) + 1 << "\n";
                return;
            }
        }
    }

    cout << "No\n";
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