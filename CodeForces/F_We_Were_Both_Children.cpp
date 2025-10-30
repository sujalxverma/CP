#include "bits/stdc++.h"
using namespace std;

const long long N = 1e6 + 1;
long long arr[N];

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
        vector<long long> cnt(n + 1, 0), mx(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            if (x <= n)
                ++cnt[x];
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i; j <= n; j += i)
                mx[j] += cnt[i];
        }
        cout << *max_element(mx.begin(),mx.end()) << "\n";
    }
    return 0;
}