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
        string st;
        cin >> st;
        int s = -1;
        int e = -1;
        for (int i = 0; i < n; i++)
        {
            if (st[i] == '1')
            {
                s = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (st[i] == '0')
            {
                e = i;
                break;
            }
        }
        // cout << s<< " "<<e<<"\n";
        if (s == -1 || e == -1 || s > e)
        {
            cout << "Bob\n"; // No valid move for Alice.
            continue;
        }

        cout << "Alice\n";
        string s2 = st;
        sort(s2.begin(), s2.end());
        vector<int> idx;
        for (int i = 0; i < n; i++)
        {
            if (st[i] != s2[i])
            {
                idx.push_back(i);
            }
        }
        cout << (int)idx.size() << "\n";
        for (auto &x : idx)
        {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*

Eg : eg : 0101111111101, my code fails this case, it just selects 1, and does not check, if counter 0 exist or not.
why ? becuse it will select 1 at index 3 (0-based), but it will not check that counter 0 exist or not.

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
        string st;
        cin >> st;
        int s = -1;
        int e = -1;
        for (int i = 0; i < n; i++)
        {
            if (st[i] == '1')
            {
                s = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (st[i] == '0')
            {
                e = i;
                break;
            }
        }
        // cout << s<< " "<<e<<"\n";
        if (s == -1 || e == -1)
        {
            cout << "Bob\n"; // No valid move for Alice.
            continue;
        }
        if (s > e)
        {
            cout << "Bob\n";
            continue;
        }
        cout << "Alice\n";
        int i = 0;
        int j = n-1;
        vector<int> idx;
        while (i <= j)
        {

            if (st[i] == '1')
            {
                idx.push_back(i + 1);
                i++;
            }
            else
            {
                i++;
            }
            if (st[j] == '0')
            {
                idx.push_back(j + 1);
                j--;
            }
            else
            {
                j--;
            }
        }
        sort(begin(idx), end(idx));
        cout << (int)idx.size() << "\n";
        for (auto &x : idx)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}*/