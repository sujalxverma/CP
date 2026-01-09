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
        vector<int> a(n), b(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                swap(a[i], b[i]);
            }
        }
        bool f = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            cout << "Yes\n";
            continue;
        }
        f = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (b[i] > b[i + 1])
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            cout << "Yes\n";
            continue;
        }

        bool switch1 = false;
        bool switch2 = false;
        bool crack = false;
        for (int i = n - 1; i >= 1; i--)
        {
            if (switch2 == true)
            {
                if (a[i - 1] > a[i])
                {
                    crack = true;
                }
                else
                {
                    // no problem
                }
            }
            else if (b[i - 1] > b[i] && switch1 == false)
            {
                // means we need to switch.
                if (b[i] < a[i - 1])
                {
                    crack = true;
                    break;
                }
                else
                {
                    switch1 = true;
                    swap(b[i - 1], a[i - 1]);
                }
            }
            else if (b[i - 1] > b[i] && switch1 == true && switch2 == false)
            {
                // need to go up.
                if (a[i] > b[i])
                {
                    crack = true;
                    break;
                }
                switch2 = true;
            }
        }

        if (crack)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }
    return 0;
}
