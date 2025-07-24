#include "bits/stdc++.h"
using namespace std;

const int INF = 1e9;
int N, K;
vector<int> price;

int recursiveMinCost(int weight, int used) {
    // Base cases
    if(weight == 0) return 0;         // exactly fulfilled
    if(weight < 0) return INF;        // invalid (over buy)
    if(used == N) return INF;         // no packets left but still weight to fulfill

    int ans = INF;

    // Try every packet size available
    for(int i = 1; i <= K; i++) {
        if(price[i] == -1) continue; // packet unavailable
        int cost = recursiveMinCost(weight - i, used + 1);
        if(cost != INF) {
            ans = min(ans, cost + price[i]);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int C; cin >> C;
    while(C--) {
        cin >> N >> K;
        price.assign(K + 1, -1);
        for(int i = 1; i <= K; i++) {
            cin >> price[i];
        }

        int ans = recursiveMinCost(K, 0);
        if(ans == INF) ans = -1;
        cout << ans << "\n";
    }
    return 0;
}
