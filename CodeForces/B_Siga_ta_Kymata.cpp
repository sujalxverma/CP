#include "bits/stdc++.h"
using namespace std;
// Alright
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    string s = "";
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += "0";
    }
    string x;
    cin >> x;

    
    int z = 0;
    int o = 0;
    for (auto c : x)
    {
        if (c == '1')
        {
            o++;
        }
        else
        {
            z++;
        }
    }

   
    if (z == n)
    {
        cout << "0\n";
        return;
    }

    int minidx = -1;
    int maxidx = -1;
    for(int i = 1 ; i <= n ; i++){
        if(a[i] == 1){
            minidx = i;
        }
        else if(a[i] == n){
            maxidx = i;
        }
    }

    if(x[maxidx-1] == '1' || x[minidx-1] == '1' || x[0] == '1' || x[n-1] == '1'){
        cout<<"-1 \n";
        return ;
    }

    cout<<5<<"\n";
    cout<<1<<" "<<minidx<<"\n";
    cout<<minidx<<" "<<n<<"\n";
    cout<<maxidx<<" "<<n<<"\n";
    cout<<1<<" "<<n<<"\n";
    cout<<1<<" "<<maxidx<<"\n";
    return ;

    
   
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