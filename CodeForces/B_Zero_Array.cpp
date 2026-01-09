#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ll sum = 0;
    vector<int> a(n);
    priority_queue<int, vector<int>, greater<int>> min_pq;
    priority_queue<int> max_pq;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        max_pq.push(a[i]);
        min_pq.push(a[i]);
    }
    if (sum % 2 != 0)
    {
        cout << "NO\n";
        return 0;
    }
    if (1LL * (*max_element(a.begin(), a.end())) * 2 > sum)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }

    return 0;
}