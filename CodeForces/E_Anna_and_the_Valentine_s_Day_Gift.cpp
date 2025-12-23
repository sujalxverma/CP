#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int countDigits(long long n)
{
    if (n == 0)
        return 1;
    n = llabs(n);

    int cnt = 0;
    while (n > 0)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}
pair<int, int> countDigitsAndTrailingZeroes(long long n)
{
    if (n == 0)
    {
        // 0 has 1 digit and 0 trailing zeroes by convention
        return {1, 0};
    }

    n = llabs(n);

    int trailingZeroes = 0;
    while (n % 10 == 0)
    {
        trailingZeroes++;
        n /= 10;
    }

    int digitsWithoutTrailingZeroes = 0;
    while (n > 0)
    {
        digitsWithoutTrailingZeroes++;
        n /= 10;
    }

    return {trailingZeroes, digitsWithoutTrailingZeroes};
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v;
    vector<pair<int, int>> havez;
    int sum = 0;
    // if (n == 1)
    // {
    //     int k;
    //     cin >> k;
    //     if (k <= 10)
    //     {
    //         cout << "Anna\n";
    //         return;
    //     }
    //     pair<int, int> p = countDigitsAndTrailingZeroes(k);
    //     if (p.second >= m + 1)
    //     {
    //         cout << "Sasha\n";
    //         return;
    //     }
    //     cout << "Anna\n";
    //     return;
    // }
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (k % 10 == 0)
        {
            havez.push_back(countDigitsAndTrailingZeroes(k));
        }
        else
        {
            v.push_back(k);
        }
    }

    sort(havez.rbegin(), havez.rend());
    bool f = true;
    for (int i = 0; i < (int)havez.size(); i++)
    {
        if (f == true)
        {
            // Anna
            sum += havez[i].second;
            f = false;
        }
        else
        {

            sum += (havez[i].first + havez[i].second);
            f = true;
            if (sum >= m + 1)
            {
                cout << "Sasha\n";
                return;
            }
        }
    }

    for (int i = 0; i < (int)v.size(); i++)
    {
        sum += countDigits(v[i]);
    }
    if (sum >= m + 1)
    {
        cout << "Sasha\n";
        return;
    }
    cout << "Anna\n";
    return;
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