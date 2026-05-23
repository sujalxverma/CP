#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, d;
    cin >> n >> m >> d;
    vector<pair<int, int>> a(1e4 + 10);
    for (int i = 0; i < 1e4 + 10; i++) {
        a[i].first = 0;
        a[i].second = 0;
    }
    for (int i = 0; i < n * m; i++) {
        int x, cpy;
        cin >> x;
        cpy = x;

        int steps = 1;
        a[x].second++;
        x -= d;
        while (x > 0) {
            a[x].first += steps;
            a[x].second++;
            x -= d;
            steps++;
        }

        steps = 1;
        cpy += d;
        while (cpy <= 1e4) {
            a[cpy].first += steps;
            a[cpy].second++;
            cpy += d;
            steps++;
        }
    }
    int ans = 1e9;
    for (int i = 0; i < 1e4 + 10; i++) {
        if (a[i].second >= n * m) {
            ans = min(ans, a[i].first);
        }
    }
    cout << (ans == 1e9 ? -1 : ans);

    return 0;
}