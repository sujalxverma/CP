#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >>t;
    while(t--){
        string s;
        cin >> s;
        if(s == "abc"){
            cout<<"YES\n";
            continue;
        }
        swap(s[0] , s[1]);
        if(s == "abc"){
            cout<<"YES\n";
            continue;
        }
        swap(s[0] , s[1]);
        swap(s[1] , s[2]);
        if(s == "abc"){
            cout<<"YES\n";
            continue;
        }
        swap(s[1] , s[2]);

        swap(s[2] , s[0]);
        if(s == "abc"){
            cout<<"YES\n";
            continue;
        }
        swap(s[2] , s[0]);
        cout<<"NO\n";



    }
    return 0;
}