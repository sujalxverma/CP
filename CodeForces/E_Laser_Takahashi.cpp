#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct point
{
    ll x, y;
};

ll cross(const point &a, const point &b)
{
    return a.x * b.y - a.y * b.x;
}

bool compare(const point &a, const point &b)
{
    bool f1 = (a.y > 0 || (a.y == 0 && a.x > 0));
    bool f2 = (b.y > 0 || (b.y == 0 && b.x > 0));

    if (f1 != f2)
        return f1 > f2; // upper half first

    ll c = cross(a, b);
    if (c != 0)
        return c > 0; // smaller angle first

    return false; // equal angle
}

void sorting(vector<point> &p)
{
    sort(p.begin(), p.end(), compare); // ascending
 
    reverse(p.begin(),p.end()); // descending
}

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
        int m;
        cin >> m;
    }
    return 0;
}