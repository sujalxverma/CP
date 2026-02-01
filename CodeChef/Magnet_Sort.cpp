#include "bits/stdc++.h"
using namespace std;
vector<int> a;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        string s;
        cin >> s;
        bool f = true;
        // non decreasing.
        for(int i = 1; i < n ; i++){
            if(a[i-1] > a[i]){
                f = false;
                break;
            }
        }
        if(f){
            cout<<"0\n";
            continue;
        }
        int ans = 0;
        int sd = 0;
        int nd = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'S')
            {
                sd++;
            }
            else
            {
                nd++;
            }
        }
        if (nd == n || sd == n)
        {
            cout << "-1\n";
        }
        else if (s[0] == s[n - 1])
        {
            cout << "2\n";
        }
        else
        {
            cout << "1\n";
        }
    }
    return 0;
}