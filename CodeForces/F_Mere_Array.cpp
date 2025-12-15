#include "bits/stdc++.h"
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << "YES\n";
        return;
    }

    int mini = *min_element(a.begin(), a.end());
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % mini == 0)
        {
            b.push_back(a[i]);
        }
    }
    if (a[0] % mini != 0)
    {
        cout << "NO\n";
        return;
    }
    int g = 0;
    for (int i = 0; i < b.size(); i++)
    {
        g = gcd(g, b[i]);
    }
    if (g != mini)
    {
        cout << "NO\n";
        return;
    }
    vector<int> c = a;
    sort(c.begin(), c.end());
    for (int i = 0; i < n; i++)
    {
        if (a[i] % mini != 0)
        {
            if(c[i] != a[i]){
                cout<<"NO\n";
                return ;
            }
        }
       
    }

    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}