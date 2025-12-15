#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        map<int,int>mp;
        mp[0] = 0;
        mp[1] = 0;
        for(int i = 0; i < n ; i++){
            int a;
            cin >> a;
            mp[a%2] ++;
        }
        if(mp[1] == 0){ // no odd elemenet.
            cout<<"No\n";
        }
        
        // else if(x == n && mp[1]%2 == 1){ // need all elements, and fr. of odd is odd.
        //     cout<<"Yes\n";
            
        // }else if(x == n && mp[1]%2 == 0){
        //     cout<<"No\n";
        // }
        else{
            bool f = false;
            for(int i = 1 ; i <= mp[1] ; i++){
                if( i <= x &&  mp[0] >= x-i && i%2 == 1){
                //    cout<<i<<"\n";
                    f = true;
                    break;
                }
            }
            if(f == true){
                cout<<"Yes\n";
            }else{
                 cout<<"No\n";
            }
        }
    }
    return 0;
}