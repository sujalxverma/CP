#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c, m, ans, count;
    cin >> a >> b >> c;
    cin >> m;
    int usb = 0;
    int ps2 = 0;
    int both = (int)c;
    vector<pair<long long, string>> arr;
    for (long long i = 0; i < m; i++)
    {
        long long k;
        string item;
        cin >> k;
        cin >> item;
        arr.push_back({k, item});
        if (item == "USB")
        {
            usb++;
        }
        else
        {
            ps2++;
        }
    }

    sort(arr.begin(), arr.end());
    ans = 0;
    count = 0;
    for (long long i = 0; i < m; i++)
    {
        if (arr[i].second == "USB" && a > 0 && usb > 0)
        {
            ans += arr[i].first;
            count++;
            a--;
            usb--;
        }
        else if (arr[i].second == "PS/2" && b > 0)
        {
            ans += arr[i].first;
            count++;
            b--;
            ps2--;
        }
        else if (arr[i].second == "USB" && usb > 0 && c > 0)
        {
            ans += arr[i].first;
            count++;
            c--;
            usb--;
        }
        
        else if (arr[i].second == "PS/2" && ps2 > 0 && c > 0)
        {
            ans += arr[i].first;
            count++;
            c--;
            ps2--;
        }
    }
    cout << count << " ";
    cout << ans << "\n";

    return 0;
}
