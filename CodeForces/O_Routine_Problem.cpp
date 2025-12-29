#include "bits/stdc++.h"
using namespace std;

int gcd(int a, int b)
{

    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == b && c == d)
    {
        cout << "0/1" << "\n";
        return 0;
    }
    // if (a < b)
    //     swap(a, b);
    // if (c < d)
    //     swap(c, d);

    if ((b * c < d * a))
    {
        cout << (a * d - c * b) / gcd(a * d, c * b) << "/" << (a * d) / gcd(a * d, c * b) << "\n";
    }
    else
    {
        cout << (b * c - d * a) / gcd(b * c, d * a) << "/" << (b * c) / gcd(b * c, d * a) << "\n";
    }

    return 0;
}