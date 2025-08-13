#include "bits/stdc++.h"

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    std::vector < int > v(3);
    v[0] = a;
    v[1] = b;
    v[2] = c;
    sort(v.begin(), v.end());
    if (v[1] - v[0] == 1) {
        cout << -1 << "\n";
        return;
    }
    if (v[2] - v[1] == 1) {
        cout << -1 << "\n";
        return;
    }
    if ((v[1] - v[0]) % 2 != 0) {
        cout << -1 << "\n";
        return;
    }
    if ((v[2] - v[1]) % 2 != 0) {
        cout << -1 << "\n";
        return;
    }
    if(v[0] == v[1]){
        cout << (v[2] - v[0])/2<<"\n";
        return ;
    }
    int gap = (v[2] - v[1] ) / 2;
    ans += gap;
    v[0] += gap;
    v[1] += gap;
    v[2]-= gap;
    ans += v[1] - v[0];
    cout<<ans<<"\n";
    return ;
    
    // while (true) {

    //     if (v[0] == v[1] && abs(v[2] - v[1]) % 2 == 0) {
    //         ans += (v[2] - v[1]) / 2;
    //         cout << ans << "\n";
    //         return;
    //     }
    //     else if (v[0] == v[1] && abs(v[2] - v[1]) % 2 != 0) {
    //         cout << -1 << "\n";
    //         return;
    //     }
    //     else if (v[2] == v[1] && abs(v[2] - v[0]) % 2 == 0) {
    //         ans += abs(v[2] - v[0]);
    //         cout << ans << "\n";
    //         return;
    //     }
    //     else if (v[2] == v[1] && abs(v[2] - v[0]) % 2 == 0) {
    //         cout << -1 << "\n";
    //         return;
    //     }


    //     ans++;
    //     v[0]++;
    //     v[1]++;
    //     v[2]--;
    //     if (v[1] - v[0] == 1) {
    //         cout << -1 << "\n";
    //         return;
    //     }
    //     if (v[2] - v[1] == 1) {
    //         cout << -1 << "\n";
    //         return;
    //     }
    //     if ((v[1] - v[0]) % 2 != 0) {
    //         cout << -1 << "\n";
    //         return;
    //     }
    //     if ((v[2] - v[1]) % 2 != 0) {
    //         cout << -1 << "\n";
    //         return;
    //     }

    // }
}

int main() {
    // your code goes here

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}