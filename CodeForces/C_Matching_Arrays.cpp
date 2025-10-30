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
        int k;
        cin >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int j = 0; j < n; j++)
            cin >> b[j];
        sort(a.begin(), a.end());
        sort(a.rbegin(), a.rend());

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                cnt++;
            }
        }
        if (cnt == k)
        {
        }

        if (cnt > k)
        {
            int i = 0;
            int j = n - 1;
            while (i < j)
            {

                if (a[j] < b[i] && a[i] <= b[j])
                {
                    swap(b[i], b[j]);
                    cnt--;
                    i++;
                    j--;
                    if (cnt == k)
                    {
                        break;
                    }
                }
                else if (a[j] < b[i] && a[i] > b[j])
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }
            if(cnt != k){
                cout<<"NO\n";
                return ;
            }
            map<int,int>p;
            for(int i = 0; i < n ; i ++){
                p[a[i]]
            }
            for(int i )
        }
        else
        {
            
            cout<<"NO\n";
            return ;
        }
    }
    return 0;
}