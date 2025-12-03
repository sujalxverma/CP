#include "bits/stdc++.h"
using namespace std;

/*
N.
1. if a palindrome of length > 3, exist then in it, a palindrome of (2 or 3) also exist.
2. I will traverse from left to right, and will check for palindrome of length 2, if it exist , then i will replace this
   character and will mark it. Same goes for palindrome 3.
*/


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();

        int count = 0;
        vector<int>used(n,0);
        for(int i = 1; i < n ; i++){
            
            if(s[i] == s[i-1] && !used[i-1]){
                used[i] = 1;
                count++;
            }
            if(i >= 2 && s[i] == s[i-2] && !used[i-2]){
                used[i] = 1;
                count++;
            }
            
        }

        

        cout<<count<<"\n";
    }
    return 0;
}