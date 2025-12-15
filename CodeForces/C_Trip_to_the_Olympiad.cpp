#include "bits/stdc++.h"
using namespace std;

using ll = long long;

/*
1. First we find the M.S bit where l and r differ.
2. This bit is k.
3. It means (1<<K) is possible answer, but if (1<<k) is less than l, then we can take, [a = l | ((1<<k)-1)].
4. The kth bit still differ.
5. b = a+1.
6. c = r, if a == l, else c == l.

*/


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
       int l,r;
       cin >>  l>> r;
       int k = 31 - __builtin_clz(l ^ r);
        

       int a = (l | ((1<<k) - 1));

       int b = a + 1;
       int c =  (a==l) ? r : l;
       cout<<a<<" "<<b<<" "<<c<<"\n";
       
    }
}
