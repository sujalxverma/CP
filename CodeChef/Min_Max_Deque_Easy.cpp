#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    std::deque<int> d;
    d.push_back(a[0]);
    d.push_back(a[1]);
    for (int i = 2; i < n; i++)
    {
        int k = a[i];
        if ((i & 1) == 0)
        { // Alice
            if (d.back() < d.front())
            {
                d.push_back(k);
            }
            else
            {
                d.push_front(k);
            }
        }
        else
        { // Bob
            if (d.back() < d.front())
            {
                d.push_front(k);
            }
            else
            {
                d.push_back(k);
            }
        }
    }
    cout<<min(d.front() , d.back())<<"\n";
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
