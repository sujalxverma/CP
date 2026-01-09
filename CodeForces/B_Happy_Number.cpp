#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    while (n > 0)
{
    int sum = 0;
    int copy = n;

    while (copy > 0)
    {
        int d = copy % 10;
        sum += d * d;
        copy /= 10;
    }

    n = sum;

    if (n == 1)
    {
        cout << "Yes\n";
        return 0;
    }
    else if (n < 10)
    {
        cout << "No\n";
        return 0;
    }
}

    return 0;
}