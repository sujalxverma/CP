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
        int xorValue = 0;
        int orValue = 0;
        for(int i = 0; i < n ; i++){
            int k;
            cin >> k;
            xorValue ^= k;
            orValue |= k;
        }
        if(xorValue == orValue){
            cout<<"Bob\n";
        }else{
            cout<<"Alice\n";
        }
    }
    return 0;
}