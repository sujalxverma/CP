#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x,y,z;
    cin >> x >> y >> z;
    if(x == y){
        cout<<x<<" ";
        for(int i = 0; i < x ; i++){
            cout<<"0 ";
        }
        cout<<"\n";

        cout<<z<<" ";
        for(int i = 0; i < z ; i++){
            cout<<"0 ";
        }
        cout<<"\n";

        cout<<z<<" ";
        for(int i = 0; i < z ; i++){
            cout<<"0 ";
        }
        cout<<"\n";
        
    }


    else{
        cout<<x+y<<" ";
        for(int i = 0; i < x ; i++){
            cout<<"1 ";
        }
        for(int i = 0; i < y ; i++){
            cout<<"0 ";
        }

        cout<<"\n";

        cout<<z<<" ";
        for(int i = 0; i < z ; i++){
            cout<<"1 ";
        }
        cout<<"\n";

        cout<<z+y<<" ";
        for(int i = 0; i < y ; i++){
            cout<<"0 ";
        }
        for(int i = 0; i < z ; i++){
            cout<<"1 ";
        }
        cout<<"\n";

    }
    return 0;
}