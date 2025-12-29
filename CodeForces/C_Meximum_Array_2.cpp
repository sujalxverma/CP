#include "bits/stdc++.h"
using namespace std;

/*
1. Neutral -> -1, put any value.
2. Min -> 0, put k.
3. Mex -> put a[i] = i%k , works, b/c a/c to constraints every mex range is atleast 'k' indices long int this probem.
4. Both -> put any value. (>= k).
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = k;
        }

        vector<int> check(n, -1);
        // 0->min  , 1->mex , 2->both.(no problem)

        while (q--)
        {
            int i, l, r;
            cin >> i >> l >> r;
            l--;
            r--;
            if (i == 2)
            {
                for (int j = l; j <= r; j++)
                {
                    if (check[j] == -1)
                    {
                        check[j] = 1; // mex
                    }
                    else if (check[j] == 0)
                    {
                        check[j] = 2;
                    }
                }
            }
            else
            {
                for (int j = l; j <= r; j++)
                {
                    if (check[j] == -1)
                    {
                        check[j] = 0; // min
                    }
                    else if (check[j] == 1)
                    {
                        check[j] = 2; // overlap.
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (check[i] == 2 || check[i] == -1)
            {
                a[i] = k + 1;
            }
            else if (check[i] == 1)
            {
                a[i] = (i + 1) % k;
            }
            else if (check[i] == 0)
            {
                a[i] = k;
            }
        }

        for (auto &x : a)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}