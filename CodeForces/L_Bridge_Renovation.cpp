#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    // 18,21,25
    // from 2 planks of 60, 3 pieces for (18 and 21) can be removed.

    int count = 0;
    if(n%3 == 0){
        count += 2*(n/3);
        count += (n/2);
        if(n%2 == 1){
            count++;
        }
    }
    else if(n%3 == 1){
        count += 2*(n/3) + 1;
        count += (n/2) ;
        if(n%2 == 1){
            count++;
        }
    }else{
        count += 2*(n/3) + 2;
        count += (n/2);
    }


        
    cout<<count<<"\n";
    return 0;
}