#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 3)
        {
            cout << "2 1 3\n";
            continue;
        }
        vector<int> a(n + 1);
        if (n % 2 == 0)
        {
            a[n] = 1;
            a[1] = n;
            for (int i = 2; i <= n - 1; i += 2)
            {
                a[i] = i + 1;
                a[i + 1] = i;
            }
        }
        else
        {
            a[n] = 1;
            a[1] = n - 1;
            a[n - 1] = n;
            for (int i = 2; i <= n - 2; i+=2)
            {
                a[i] = i + 1;
                a[i + 1] = i;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}