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
        vector<int>a(n),b(n);
        int ali = 0;
        int mai = 0;
        for(int i = 0; i < n ; i++){
            cin >> a[i];
            ali ^= a[i];
        }
        for(int i = 0; i < n ; i++){
            cin >> b[i];
            mai ^= b[i];
        }

        for(int i = 0 ; i < n ; i++){
            if((i&1) == 0){
                // ali
                if( (ali) < (ali^a[i]^b[i])){
                    ali = ali^a[i]^b[i];
                    mai = mai^a[i]^b[i];
                }
            }
            else{
                // mai
                if( (mai) < (mai^a[i]^b[i])){
                    ali = ali^a[i]^b[i];
                    mai = mai^a[i]^b[i];
                }

            }
        }
        if(ali == mai){
            cout<<"Tie\n";
        }
        else if(ali < mai){
            cout<<"Mai\n";
        }
        else{
            cout<<"Ajisai\n";
        }

    }
    return 0;
}