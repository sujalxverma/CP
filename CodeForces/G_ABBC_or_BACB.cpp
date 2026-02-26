#include "bits/stdc++.h"
using namespace std;

/*
1. If number of B is 1, then choose max length A segment.
2. If number of B is  >=  number of A segments, then answer is number of A.
3. Else the answer is (number of A - minSeg length)
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int a = 0;
        int b = 0;
        for (auto &X : s)
        {
            if (X == 'A')
                a++;
            else
                b++;
        }
        int n = (int)s.length();
        if (a == n || b == n)
        {
            cout << "0\n";
            continue;
        }

        vector<int> seg;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A')
            {
                cnt++;
            }
            else
            {
                if (cnt > 0)
                {
                    seg.push_back(cnt);
                    cnt = 0;
                }
            }
        }
        if (cnt > 0)
        {
            seg.push_back(cnt);
        }

        int minSeg = *min_element(begin(seg), end(seg));

        if (b >= (int)seg.size())
        {
            cout << a << "\n";
        }
        else
        {
            cout << a - minSeg << "\n";
        }
    }
    return 0;
}