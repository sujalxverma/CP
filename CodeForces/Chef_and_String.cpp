#include "bits/stdc++.h"
using namespace std;

/*
1. Greedly counts the occ. of each character.
2. H can only be +1, only if there exist some C before, otherwise no use to take this H.
3. Similarly for E (H -> E) and F( E-> F).
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int c = 0;
    int h = 0;
    int e = 0;
    int f = 0;
    int n = (int)s.length();
    // cout<<n<<"\n";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'C')
        {
            c++;
        }
        else if (s[i] == 'H' && c > h)
        {
            h++;
        }
        else if (s[i] == 'E' && h > e)
        {
            e++;
        }
        else if (s[i] == 'F' && e > f)
        {
            f++;
        }
    }

    cout << f << "\n";

    return 0;
}