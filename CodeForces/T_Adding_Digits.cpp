#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, n;
    cin >> a >> b >> n;
    int num = -1;
    for (int i = 0; i <= 9; i++)
    {
        if ((a * 10 + i) % b == 0)
        {
            num = i;
            break;
        }
    }
    if (num == -1)
    {
        cout << "-1\n";
        return 0;
    }

    cout << a;
    cout << num;

    for (int i = 0; i < n - 1; i++)
    {
        cout << 0;
    }
    cout << "\n";
    return 0;
}