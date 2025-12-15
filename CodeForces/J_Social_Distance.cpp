#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int>ones;
    for(int i = 0; i < n ; i++){
        if(s[i]=='1'){
            ones.push_back(i);
        }
    }
    int g = k+1;
    int count = 0;
    for (int i = 0; i + 1 < (int)ones.size(); i++){
        int a = ones[i];
        int b = ones[i+1];
        int check = 0;
        for(int j = a+1 ; j < b ; j++){
            g--;
            if(g == 0){
                g=k+1;
                check++;
            }


        }
        if(g > 0){
            if(check>0){
                check--;
            }
        }
        count += check;
    }

    cout<<count<<"\n";
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