#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string r = "codechef"; // just do all possiblilities using all permuatation.
        bool f = true;
        sort(begin(s),end(s));

        do{
            for(int i = 0; i < 8 ; i++){
                if(r[i] == s[i]){
                    f = false;
                }
            }
            if(!f){
                f = true;
            }else{
                f = false;
                break;
            }
        }while(next_permutation(s.begin(),s.end()));
        if(f){
            cout<<"-1\n";
            continue;
        }
        cout<<s<<"\n";
    }
    return 0;
}