#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string a,b;
        cin >> a >> b;
       

        for(int i = 0;i < n ;i++){
            if(a[i] == b[i]){
                // do nothing.
            }
            else{
                if((i+3 < n )){
                    if(a[i+3] == b[i]){
                        swap(a[i+3],a[i]);
                    }else{
                        if(i+4 < n && a[i+4] == b[i]){
                            swap(a[i+4] , a[i]);
                        }
                    }
                }
            }
        }
        bool f = true;
        for(int i = 0; i < n ; i++){
            if(a[i] != b[i]){
                f = false;
                break;
            }
        }
        if(f){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}