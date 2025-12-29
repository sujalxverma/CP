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
        if (k == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
            cout << "\n";
            continue;
        }
        int x = -1;
        int y = -1;
        for (int i = 1; i <= n; i++)
        {
            if ((i ^ k) <= n && (i ^ k) >= 1)
            {
                x = i;
                y = (i ^ k);
                break;
            }
        }
        if (x == -1)
        {
            cout << "-1\n";
            continue;
        }
        if(x>y){
            swap(x,y);
        }
        //    cout<<x<<" "<<y<<"\n";

        //    now range [x+1,y-1]

        int z = 0;
        for(int i = 0; i <= floor(log2(k))+1 ;i++){
            if((1<<i) & k){
                z = i;
            }
        }
        for(int i = x+1 ; i <= y ; i++){
            if((i & (1<<z))){
                z = i;
                break;
            }
        }

        for(int i = 1 ; i <= x-1 ; i++){
            cout<<i<<" ";
        }
        for(int i = x+1 ; i < z ; i++){
            cout<<i<<" ";
        }
        cout<<y<<" "<<x<<" "; 

        for(int i = z ; i < y ; i++){
            cout<<i<<" ";
        }
        for(int i = y+1 ; i <= n ; i++){
            cout<<i<<" ";
        }
        cout<<"\n";

    }
    return 0;
}