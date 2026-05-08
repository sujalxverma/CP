#include "bits/stdc++.h"
using namespace std;

int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), p(n, 0), s(n, n - 1), ans(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            if (a[i] > a[p[i - 1]]) {
                p[i] = i;
            } else {
                p[i] = p[i - 1];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] < a[s[i + 1]]) {
                s[i] = i;
            } else {
                s[i] = s[i + 1];
            }
        }
        int maxIdx = p[n - 1];
        int minidx = s[maxIdx];
        ans[maxIdx] = a[maxIdx];
        for (int i = maxIdx; i < n; i++) {
            ans[i] = ans[maxIdx];
        }
        int loopidx = maxIdx - 1;
        while (loopidx >= 0) {
            maxIdx = p[loopidx];
            if (a[maxIdx] > a[minidx]) {
                ans[maxIdx] = ans[minidx];
            } else {
                ans[maxIdx] = a[maxIdx];
            }
            for (int j = maxIdx + 1; j <= loopidx; j++) {
                ans[j] = ans[maxIdx];
            }
            minidx = s[maxIdx];
            loopidx = maxIdx - 1;
        }

        for (auto &x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}