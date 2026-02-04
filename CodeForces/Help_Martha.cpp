#include "bits/stdc++.h"
using namespace std;

/*
1. To tell, if it is possible to reach (x,y) from (x1,y1) by following some subsequence of string s moves.

*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> moves(4);
        // 0->UP , 1->RIGHT, 2->LEFT, 3-> DOWN
        string s;
        cin >> s;
        for (int i = 0; i < (int)s.length(); i++)
        {
            if (s[i] == 'U')
            {
                moves[0]++;
            }
            if (s[i] == 'R')
            {
                moves[1]++;
            }
            if (s[i] == 'L')
            {
                moves[2]++;
            }
            if (s[i] == 'D')
            {
                moves[3]++;
            }
        }

        int x1, y1;
        cin >> x1 >> y1; // starting points.
        int q;
        cin >> q;
        while (q--)
        {
            int x, y;
            cin >> x >> y;
            // Using Manhattan distance.
            int left = 0, right = 0, down = 0, up = 0;
            if (x1 <= x)
            {
                // right side.
                right = abs(x - x1);
            }
            else
            {
                left = abs(x - x1);
            }

            if (y1 <= y)
            {
                // upper side.
                up = abs(y - y1);
            }
            else
            {
                down = abs(y - y1);
            }
            // 0->UP , 1->RIGHT, 2->LEFT, 3-> DOWN
            if (up <= moves[0] && right <= moves[1] && left <= moves[2] && down <= moves[3])
            {
                cout << "YES ";
                cout << left + right + up + down << "\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}