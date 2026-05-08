#include "bits/stdc++.h"
using namespace std;
int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, r, g;
    cin >> n >> r >> g;
    vector<pair<long long, long long>> p(n);
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
        sum += p[i].first;
    }
    sort(begin(p), end(p), [&](auto a, auto b) {
        return a.second < b.second;
    });
    if ((sum / n) >= g) {
        cout << "0\n";
        return 0;
    }
    long long count = 0;
    long long diff = (n * g - sum);
    for (long long i = 0; i < n; i++) {
        if (diff <= 0)
            break;
        count += min((r - p[i].first), diff) * p[i].second;
        diff -= min((r - p[i].first), diff);
    }
    cout << count << "\n";
    return 0;
}