#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;

    int sum = v1;
    int prev = v1;

    for(int i = 2 ; i <= t ; i++){
        // maximum amount of spped i can achieve at this point in order to reach v2 at end.
        int maxSpeed = v2 + (t-i)*d;
        // my current upped limit i can reach.
        int current = prev + d;
        // if current > maxSpeed, then take maxSpeed to reach v2 at end, otherwise ww cannot reach to v2.
        sum += min(maxSpeed , current);
        prev = current;
    }

    cout << sum << "\n";
    return 0;
}