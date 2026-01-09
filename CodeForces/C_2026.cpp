#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int count = 0;
    vector<int> ans;

    for (int i = 1; 1LL * i * i < n; i++) {              // key fix: prevent negative under sqrt
        long long ii = 1LL * i * i;
        long long rem = n - ii;                          // rem >= 1 here

        int maxNum = (int) sqrtl((long double)rem);

        // guard against rare floating rounding
        while (1LL * maxNum * maxNum > rem) maxNum--;
        while (1LL * (maxNum + 1) * (maxNum + 1) <= rem) maxNum++;

        if (maxNum <= i) break;

        for (int j = i + 1; j <= maxNum; j++) {
            count++;
            ans.push_back((int)(ii + 1LL * j * j));
        }
    }

    cout << count << "\n";
    sort(ans.begin(), ans.end());
    for (int x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}
