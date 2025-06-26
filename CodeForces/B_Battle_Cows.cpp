#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve() {
    int n, k;
    cin >> n >> k;
    k--; // zero-based indexing

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    // Find first position with rating greater than your cow's rating
    int x = n; // default to n if none found
    rep(i, 0, n) {
        if (a[i] > a[k]) {
            x = i;
            break;
        }
    }

    // Positions array: pos[i] = initial cow at position i
    vi pos(n);
    iota(pos.begin(), pos.end(), 0);

    int ans = 0;

    // Try swapping your cow with pos 0 and pos x (if x < n)
    for (int swap_pos : {0, x}) {
        if (swap_pos == n) continue; // no bigger cow found

        // Swap positions of your cow and cow at swap_pos
        swap(pos[swap_pos], pos[k]);

        // stt[u] = number of wins cow u got in tournament
        vi stt(n, 0);

        int winner = pos[0];
        rep(j, 1, n) {
            int challenger = pos[j];
            // winner is cow with higher rating
            winner = (a[winner] > a[challenger]) ? winner : challenger;
            stt[winner]++;
        }

        // Swap back to restore original positions for next iteration
        swap(pos[swap_pos], pos[k]);

        ans = max(ans, stt[k]);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}
