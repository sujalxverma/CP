#include "bits/stdc++.h"
using namespace std;
#define no cout << "NO\n"

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
        string s;
        cin >> s;
        if (n == 2 && (s[0] == s[1]))
        {
            cout << "RH\n";
            continue;
        }
        if (n == 1 || n == 3 || (n == 2 && (s[0] != s[1])))
        {
            no;
            continue;
        }

        
    }
    return 0;
}