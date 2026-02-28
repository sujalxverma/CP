#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int>f(n+1,0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        f[x]++;
    }
    int v = n - 2;
    for (int i = 1; i * i <= v; i++)
    {
        if (v % i == 0)
        {
            if(f[i] > 0 && f[v/i] > 0){
                cout<<i<<" "<<v/i<<"\n";
                return ;
            }
           
        }
    }
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