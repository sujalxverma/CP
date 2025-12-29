#include "bits/stdc++.h"
using namespace std;

bool f(vector<int> &a, vector<int> &b, int k)
{
    int n = a.size();
    for (int i = 0; i < n - k; i++)
    {
        if (a[i] >= b[k + i])
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, M;
        cin >> n >> M;

        vector<int> a(n), b(n);

        for (int i = 0; i < n - 1; i++)
            cin >> a[i];

        for (int &x : b)
            cin >> x;

        a[n - 1] = 1;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int s = 0, e = n - 1;
        int ans = -1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (f(a, b, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        if(ans == -1){cout<<n<<"\n";continue;}
        cout << ans << "\n";
    }
    return 0;
}
