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
        vector<int> a(n);
        vector<int> fr(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i] > n) continue;
            fr[a[i]]++;
        }
        vector<int>mx(n+1,0);
        for (int i = 1; i <= n; i++)
        {
            if(fr[i] > 0){
                int j = 1 ;
                while(j * i <= n){
                    mx[j*i]+=fr[i];
                    j+=1;
                }
            }
        }

        cout << *max_element(begin(mx), end(mx)) << "\n";
    }
    return 0;
}