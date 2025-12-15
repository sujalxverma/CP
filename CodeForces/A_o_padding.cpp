#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0 ; i < n - s.length() ; i++){
        cout<<"o";
    }
    cout<<s<<"\n";
    return 0;
}