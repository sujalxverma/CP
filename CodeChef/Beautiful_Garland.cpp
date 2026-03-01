#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

void solve()
{
    string s;
    cin >> s;
    int n = (int)s.length();

    int r = 0;
    int g = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
            r++;
        else
            g++;
    }
    if (g != r)
    {
        cout << "no\n";
        return;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == s[(i + 1) % n])
        {
            cnt++;
        }
    }
    if (cnt > 2)
    {
        cout << "no\n";
    }
    else
    {
        cout << "yes\n";
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