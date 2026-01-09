#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        if(y == 0){
            if(x%2 == 0){
                cout<<"Bob\n";
            }else{
                cout<<"Alice\n";
            }
        }
        else if(x == 0){
            cout<<"Bob\n";
        }
        else if(x%2 == 0){
            cout<<"Bob\n";
        }else{
            cout<<"Alice\n";
        }
    }
    return 0;
}