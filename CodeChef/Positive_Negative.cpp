#include "bits/stdc++.h"
using namespace std;

/*
1. Alice can only win, if A1 = -1 or An = -1, if on her turn, both ends are 1, she loses.
2. 
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
        vector<int> a(n);
        int idx = -1;
        int o = 0;
        for(int i = 0; i < n ; i++){
            int x;
            cin >> x;
            if(x==1){
                o++;
                idx = i;
            }
        }
        if(o == n){
            cout<<"0\n";
            continue;
        }
        if(o == 1){
            if(idx > 0 && idx < n-1){
                cout<<"3\n";
            }else{
                if(n > 2){
                    cout<<"2\n";
                }else{
                    cout<<"1\n";
                }
            }
            continue;
        }


    }
    return 0;
}