#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string>g(n);
    for (int i = 0; i < n; i++) {
    cin >> g[i];
}


    // for square, simply check if two rows have equal amount of 1.
    // Else it is triangle.
    
    int prev = 0;
    int curr = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(g[i][j] == '1'){
                curr++;
            }
        }
        if(prev == 0){
            prev = curr;
            curr = 0;
        }else{
            if(curr == prev){
                cout<<"SQUARE\n";
                return ;
            }else{
                cout<<"TRIANGLE\n";
                return ;
            }
        }
    }
    cout<<"SQUARE\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}