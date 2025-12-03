#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,c;
    cin >> a >> b >> c;
    vector<int>v = {a,b,c};
    sort(v.begin() , v.end());
    if(max({a,b,c}) - min({a,b,c}) < 10){
        cout<<"final"<<" "<<v[1]<<"\n";
    }
    else{
        cout<<"check again\n";
    }
    return 0;
}