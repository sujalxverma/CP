#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
using ll = long long;
vector<ll> precompute() {
    const ll LIM = 1e9;
    vector<ll> powerOf2;
    for (ll i = 1; i <= LIM; i <<= 1) {
        powerOf2.push_back(i);
    }
    int k = (int)powerOf2.size();
    vector<ll> powerOf10(k);
    for (int i = 0; i < k; i++) {
        ll num = powerOf2[i];
        ll p = 1;
        while (num > 0) {
            p *= 10;
            num = num / 10;
        }
        // number of 10s place in each number, which is power of 2.
        powerOf10[i] = p;
    }
    priority_queue<ll, vector<ll>, greater<>> pq; // min PQ.
    unordered_set<ll> vis;
    for (int i = 0; i < k; i++) {
        vis.insert(powerOf2[i]);
        pq.push(powerOf2[i]);
    }
    vector<ll> result;
    while (!pq.empty()) {
        ll val = pq.top();
        pq.pop();
        result.push_back(val);
        /*
        Say, we start with number 2, and powerOf2 has -> [1,2,4,8,16,32,64..] and so on.
        We will make numbers : [21 , 22 , 24 , 28 , 216...], and so on, and simply put them in the pq, only if there are not visited
        earlier.
        As pq will give smaller number at top, thus we greddily makes smallest numbers in this way.
        */
        for (int i = 0; i < k; i++) {
            if (val > (LIM / powerOf10[i]))
                continue; // to check we we make te concatinated number, will it be lower <= LIM.

            ll nextNum = val * powerOf10[i] + powerOf2[i];
            if (nextNum <= LIM && !vis.count(nextNum)) {
                vis.insert(nextNum);
                pq.push(nextNum);
            }
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();
    vector<ll> f = precompute();
    int n;
    cin >> n;
    n--;
    cout << f[n] << "\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}