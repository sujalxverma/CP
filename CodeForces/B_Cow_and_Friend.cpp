#include "bits/stdc++.h"
using namespace std;

/*
1. If x is already present in jumps, then return 1.
2. it will take at least max(2,ceil(x/d)) , d = maxJump.
3. say if x = 11 , and d = 5, then max(2,3) = 3.
4. but if x = 11 and d = 6, then max(2,2) = 2.
5. why ? b/c, i can take 6, then make any arranagement such that, the next jump required is present in 
   its jump set.
6. Think in terms of vector.
*/


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x;
        cin >> x;
        set<int>s;
        bool f = false;
        for(int i = 0; i < n ; i++){
            int k;
            cin >> k;
            s.insert(k);
            if( k == x){
                f = true;
            }
        }
        if(f){
            cout<<"1\n";
            continue;
        }
        else{
            int d = *s.rbegin();
            cout<<max(2 , (x+d-1)/d)<<"\n";
        }
    }
    return 0;
}