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
        string s;
        cin >> s;

        int count0 = 0;
        int count1 = 0;
        int max0 = 0;
        int max1 = 0;

        int t0 = 0;
        int t1 = 0;
     
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                t0++;
                count0++;
                max0 = max(max0, count0);

                max1 = max(max1, count1);
                count1 = 0;
            }
            else
            {
                t1++;
                count1++;
                max1 = max(max1, count1);

                max0 = max(max0, count0);
                count0 = 0;
            }
        }

         max0 = max(max0, count0);
         max1 = max(max1, count1);
        int ans = 2*n;
        ans = min({ans , 2*(t0 - max0) + t1 , 2*(t1 - max1) + t0});
        cout<<ans<<"\n";

    }
    return 0;
}