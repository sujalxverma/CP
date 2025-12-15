#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x,y;
        cin >> x >> y;
        int g = y-x;
        cout<<x<<" "<<y<<" ";
        for(int i = 0 ; i < n-2 ; i++){
            cout<<y+g<<" ";
            y+=g;
        }
        cout<<"\n";
    }
    return 0;
}