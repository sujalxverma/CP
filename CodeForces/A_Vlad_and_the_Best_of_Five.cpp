#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int A=0;
        int B = 0;
        for(int i = 0; i < (int)s.length() ; i++){
            if(s[i] == 'A') A++;
            else B++;
        }

        cout<<(A > B ? 'A' : 'B')<<"\n";
    }
    return 0;
}