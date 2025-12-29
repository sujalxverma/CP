#include "bits/stdc++.h"
using namespace std;
using ll = long long ;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll s = 1;
    ll e = 1e9;    

    while(s < e){
        ll m = s+(e-s)/2;

        // print query  
        cout<<"? "<<m<<"\n";
        cout.flush();

        // read response
        string res ;
        cin >> res;

        // check condition and update logic.
        if(res == "YES"){
            s = m+1;
        }else{
            e = m;
        }
    }

    cout<<"! "<<s<<"\n";
    cout.flush();

    return 0;
}