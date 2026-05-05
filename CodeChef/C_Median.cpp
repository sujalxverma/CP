// #include "bits/stdc++.h"
// using namespace std;

// int main(int args, char *argv[]) {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, k;
//     cin >> n >> k;
//     vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) {
//         cin >> a[i];
//     }

//     sort(begin(a) + 1, end(a));
//     // for (int i = 1; i <= n; i++) {
//     //     cout << a[i] << " ";
//     // }
//     // return 0;

//     int m = (n + 1) / 2;
//     auto idx = 0;
//     auto idx1 = lower_bound(begin(a) + 1, end(a), k) - begin(a);
//     auto idx2 = upper_bound(begin(a) + 1, end(a), k) - begin(a) - 1;
//     if (abs(m - idx1) <= abs(m - idx2)) {
//         idx = idx1;
//     } else {
//         idx = idx2;
//     }
//     if (idx1 == n + 1) {
//         cout << n + 1 << "\n";
//         return 0;
//     }

//     if (a[idx] == a[m]) {
//         cout << "0\n";
//         return 0;
//     }

//     if (a[idx] == k) {
//         if (idx < m) {
//             cout << abs(m - idx) << "\n";
//             return 0;
//         }
//         if (idx > m) {
//             if (n % 2 == 1) {
//                 cout << 2 * abs(m - idx) << "\n";
//                 return 0;
//             } else {
//                 cout << 2 * abs(m - idx) - 1 << "\n";
//                 return 0;
//             }
//         }
//     } else {
//         if (idx < m) {
//             cout << (m - idx) << "\n";
//             return 0;
//         }
//         if (idx > m) {
//             if (n % 2 == 1) {
//                 cout << 2 * abs(m - idx) << "\n";
//                 return 0;
//             } else {
//                 cout << 2 * abs(m - idx) - 1 << "\n";
//                 return 0;
//             }
//         }
//     }

//     return 0;
// }

#include "bits/stdc++.h"
using namespace std;

int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 1-based indexing.
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int ans = 0;
    bool f = false;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == k) {
            f = true;
        }
    }
    if (!f) {
        n++;
        a.push_back(k);
        ans++;
    }

    sort(begin(a) + 1, end(a));
    while (true) {
        int m = (n + 1) / 2;
        if (a[m] == k) {
            cout << ans << "\n";
            return 0;
        }
        if (a[m] < k) {
            n++;
            ans++;
            a.push_back(1e5);
        } else {
            n++;
            ans++;
            a.push_back(1);
            sort(begin(a) + 1, end(a));
        }
    }

    return 0;
}