#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, N;
    if (!(cin >> H >> W >> N)) return 0;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    unordered_set<int> called;
    called.reserve(N * 2);
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        called.insert(x);
    }

    int ans = 0;
    for (int i = 0; i < H; ++i) {
        int cnt = 0;
        for (int j = 0; j < W; ++j) {
            if (called.count(A[i][j])) ++cnt;
        }
        ans = max(ans, cnt);
    }

    cout << ans << '\n';
    return 0;
}

     
