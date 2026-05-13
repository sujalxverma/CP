#include "bits/stdc++.h"
using namespace std;
int n, x;
vector<int> u, v;
int f(int m) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (u[i] + v[i] == x)
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    u.resize(n);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> u[i] >> v[i];
    }

    int ans = 0;
    int s = 0;
    int e = 1e9;
    while (s <= e) {
        int m = s + (e - s) / 2;
    }
    return 0;
}