#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        vector<int>a(n);
        for(auto &x : a){
            cin >> x;

        }
        bool f = false;
        for(int i = 0 ; i < n -1 ; i++){
            if(a[i] > a[i+1]){
                f = true;
                break;
            }
        }
        if(f){
            cout<<"1\n";
        }
        else{
            cout<<n<<"\n";
        }
    }
    return 0;
}