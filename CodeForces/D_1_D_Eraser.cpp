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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int i = -1;
        int j = -1;
        for (int x = 0; x < n; x++)
        {
            if (s[x] == 'B')
            {
                i = x;
                break;
            }
        }
        for (int x = n - 1; x >= 0; x--)
        {
            if (s[x] == 'B')
            {
                j = x;
                break;
            }
        }

        if (i == -1 && j == -1)
        {
            cout << "0\n";
            continue;
        }
        
        int cnt = 0;
        int ans = 0;
        
        for(int x = i ; x <= j ; x ++){
            if(cnt == k){
                ans ++;
                cnt = 0;
            }

            if(s[x] == 'B'){
                cnt++;
            }
            else{
                if(cnt > 0){
                    cnt ++;
                }
            }
        }

        if(cnt > 0){
            ans ++;
        }

        cout<<ans<<"\n";

    }
    return 0;
}