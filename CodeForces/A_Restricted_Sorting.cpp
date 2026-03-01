#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    b = a;
    vector<int> c;
    sort(begin(b), end(b));
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            c.push_back(a[i]);
            c.push_back(b[i]);
        }
    }

    if ((int)c.size() == 0)
    {
        cout << "-1\n";
        return;
    }

    sort(begin(c), end(c));
    c.erase(unique(begin(c), end(c)), end(c));
    int m = (int)c.size();
    if (m == n)
    {
        cout << "1\n";
        return;
    }
    int ans = 1;
    
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