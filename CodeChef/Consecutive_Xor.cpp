#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
#define Tasrik ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
int main ()
{
    Tasrik;
    ll t,n;
    cin>>t;
    while(t--)
    {
        // I really did not understand the logic.
        ll n;
        cin>>n;
        ll arr[n];
        for (int i = 0; i < n; i++)
            cin>>arr[i];

        ll val=arr[0];
        for (int i = 1; i < n; i++)
        {
            val^=arr[i];
        }

        if (val==0)
        {
            cout<<"YES\n";
        }
        else
        {
            if(n%2==1)
            {
                cout<<"YES\n";
            }
            else
            {
                cout<<"NO\n";
            }
        }


    }

}



