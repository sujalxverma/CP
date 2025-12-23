#include "bits/stdc++.h"
using namespace std;

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
        vector<int> b;
        vector<int> c;
        int x = 1e8; // b
        int y = 1e8; // c

        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            if (x <= y)
            {
                if (k <= x)
                {
                    b.push_back(k);
                    x = k;
                }
                else if (k > y)
                {
                    b.push_back(k);
                    x = k;
                }
                else
                {
                    c.push_back(k);
                    y = k;
                }
            }
            else
            {
                if (k <= y)
                {
                    c.push_back(k);
                    y = k;
                }
                else if (k > x)
                {
                    c.push_back(k);
                    y = k;
                }
                else
                {
                    b.push_back(k);
                    x = k;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < (int)b.size() - 1; i++)
        {
            if (b[i] < b[i + 1])
            {
                count++;
            }
        }
        for (int i = 0; i < (int)c.size() - 1; i++)
        {
            if (c[i] < c[i + 1])
            {
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}