#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<ll> a, c;
/*
1. We greedily try to construct the array B.
2. First sort array A.
3. B[0] = A[0]
4. For index i, if any A[k] exist which is greater than summation(b[idx]), for idx : 0 to i-1, then insert A[i].
5. Else break.
6. Now all those elements of A, that remain to be inserted are the number of cursed indices.
7. Space Complexity :
   3 array used.
8. Time Complexity :
   Sort array A. ~O(NlogN)
   Using upper_bound. ~O(logN), inside loop. O(N).
   Therefore, O(NlogN)
*/

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
        a.resize(n);
        c.assign(n, -1);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        vector<ll> b;
        b.push_back(a[0]);
        c[0] = 1;
        ll sum = a[0];
        for (int i = 1; i < n; i++)
        {
            auto it = upper_bound(a.begin(), a.end(), sum);
            if (it == a.end())
            {
                break;
            }
            else
            {
                c[it - a.begin()] = 1;
                b.push_back(a[it - a.begin()]);
                sum += b.back();
            }
        }
        // now simply insert elements that remains.
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {

            if (c[i] == -1)
            {
                b.push_back(a[i]);
                cnt++;
            }
        }

        cout << cnt << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}