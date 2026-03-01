#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), f(1e5 + 10);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        f[a[i]]++;
    }
    b = a;
    if (n <= 2)
    {
        cout << "NO\n";
        return;
    }

    sort(begin(b), end(b));
    int cnt = f[b[n - 1]];

    if (b[n - 1] != b[n - 2] && (f[b[n - 1]] == n || f[b[n - 2]] == n - 1))
    {
        cout << "NO\n";
        return;
    }

    if (n >= 2 * cnt - 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}