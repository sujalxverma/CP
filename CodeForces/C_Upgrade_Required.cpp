#include "bits/stdc++.h"
using namespace std;

/*
Inner loop total: O(n)

(because o increases from 1 → n exactly once)

Outer loop: O(q)

(because each query is processed once)

Overall time complexity
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<int>v(n+1 , 1);
    int o = 1;
    while(q--){
        int a,b;
        cin >> a >> b;
        int r = 0;

        while(o <= a){
            r += v[o];
            v[b] += v[o];
            o++;
        }
        cout<<r<<"\n";
    }
    return 0;
}