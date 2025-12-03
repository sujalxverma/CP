#include "bits/stdc++.h"
using namespace std;

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
        int count = 0;
        int cow = 0;

        while (4 * cow <= n)
        {
            if ((n - (4 * cow)) % 2 == 0)
            {

                count++;
            }
            cow++;
        }
        cout << count << "\n";
    }
    return 0;
}