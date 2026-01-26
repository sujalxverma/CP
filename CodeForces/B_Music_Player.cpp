#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    bool f = false;
    int v = 0;
    for(int i = 0; i < n ; i++){
        int q;
        cin >> q;
        if(q == 1){
            v++;
        }
        else if(q == 2){
            v -= (v > 0 ? 1 : 0);
        }
        else{
            f = !f;
        }

        if(f && v >= 3){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }

    }
    return 0;
}