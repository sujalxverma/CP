#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }

    sort(a.begin() + 1, a.begin() + n - 1);
    // for(auto c : a){
    //     cout<<c<<" ";
    // }
    // cout<<"\n";
    int prev = a[0];
    int canbe = a[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[n - 1] && prev * 2 >= a[i])
        {
            canbe = a[i];
        }
        else if (a[i] == a[n - 1])
        {
            if (prev * 2 < a[i])
            {
                if (canbe * 2 < a[i])
                {
                    cout << "-1\n";
                    return;
                }
                count++;
            }
            cout << count + 1 << "\n";
            return;
        }
        else if (a[i] > a[n - 1])
        {
            continue;
        }
        else
        {

            if (canbe * 2 < a[i])
            {

                cout << "-1\n";
                return;
            }
            prev = canbe;
            canbe = a[i];
            count++;
        }
    }
    cout << count + 1 << "\n";
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