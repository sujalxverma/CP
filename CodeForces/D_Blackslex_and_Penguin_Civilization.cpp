#include "bits/stdc++.h"
using namespace std;
using ll = long long;

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
        vector<int> p;
        p.push_back((1LL << n) - 1);
        vector<int>a((1<<n),0);
        a[(1LL<<n)-1] = 1;
        for (int i = n - 1; i >= 1; i--)
        {
            ll mask = (1LL << i) - 1;
            for (int j = mask; j <= ((1LL << n) - 1); j++)
            {
                if ((mask & j) == mask && a[j] == 0)
                {
                    p.push_back(j);
                    a[j]= 1;
                }
            }
        }
        for(int i = 0 ; i <= (((1LL << n) - 1)) ; i+= 2){
            p.push_back(i);
        }
        for (auto x : p)
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}

// #include "bits/stdc++.h"
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;

//         // print 2^n - 1
//         cout << ((1LL << n) - 1) << " ";

//         for (int i = 1; i <= n; i++) {
//             for (int j = 0; j < (1 << i); j += 2) {
//                 long long val = 1LL * j * (1LL << (n - i)) + (1LL << (n - i)) - 1;
//                 cout << val << " ";
//             }
//         }
//         cout << '\n';
//     }

//     return 0;
// }
