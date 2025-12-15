#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        vector<int> v(2 * n);
        int a = 1;
        int b = 2;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                v[i] = a;
                v[i + n] = b;
                a+=2;
                b+=2;
            }
            else
            {
                v[i] = b;
                v[i + n] = a;
                a+=2;
                b+=2;
            }
        }
        for(auto x : v){
            cout << x<<" ";
        }
        cout<<"\n";
    }
    return 0;
}