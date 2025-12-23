// #include "bits/stdc++.h"
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<int> a(n), b(m);
//     for (auto &x : a)
//     {
//         cin >> x;
//     }
//     for (auto &x : b)
//     {
//         cin >> x;
//     }

//     int count = 0;
//     vector<char> used(n, 0);

//     sort(begin(a), end(a));
//     // for(auto x : a){
//     //     cout<<x<<" ";
//     // }
//     // cout<<"\n";
//     sort(begin(b), end(b));
//     //  for(auto x : b){
//     //     cout<<x<<" ";
//     // }
//     // return 0;
//     // cout<<"\n";
//     int pointer = n - 1;
//     for (int i = m - 1; i >= 0; i--)
//     {
//         auto it = lower_bound(a.begin(), a.end(), b[i]);

//         auto idx = it - a.begin();
//         if (pointer < idx)
//         {
//             pointer--;
//             count++;
//             if (pointer < 0)
//             {
//                 break;
//             }
//             if (count == k)
//             {
//                 break;
//             }
//             continue;
//         }
//         else if (a[idx] > b[i])
//         {
//             idx--;
//         }
//         if (idx < 0)
//         {
//             break;
//         }
//         else
//         {
//             pointer = idx - 1;
//             count++;
//         }

//         if (pointer < 0)
//         {
//             break;
//         }
//         if (count == k)
//         {
//             break;
//         }
//     }

//     if (count == k)
//     {
//         cout << "Yes\n";
//     }
//     else
//     {
//         // cout<<count<<"\n";
//         cout << "No\n";
//     }

//     return 0;
// }

#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    sort(begin(a), end(a));
    vector<int> b(m);
    for (auto &x : b)
    {
        cin >> x;
    }

    sort(begin(b), end(b));

    for (int i = 0; i < k; i++)
    {
        if (a[i] > b[m - k + i])
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}