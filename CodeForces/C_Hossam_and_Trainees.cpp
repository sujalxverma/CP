#include <algorithm>
#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
vector<int> f;
/*
-What i was doing earlier was that i was doing x > 2, but in problem it states x >= 2.
-Then logic is simple, check for only prime numbers, if any prime number freq > 1, then YES.
-At end, if not YES, then simply No.
*/
vector<int> sieve(int n) {
    vector<int> f(n + 1, 0); // mark all numbers as 0, means all are prime.
    for (int i = 2; i * i <= n; i++) {
        if (f[i] == 0) {
            // means this number i is a prime.
            // mark all factors of i to be non prime.
            for (int j = i * i; j <= n; j += i) {
                f[j] = 1;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (f[i] == 0)
            primes.push_back(i);
    }
    return primes;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (x % 2 == 0) {
            int cnt = 0;
            while (x % 2 == 0) {
                x = x / 2;
                cnt++;
            }
            mp[2]++;
            if (mp[2] > 1) {
                cout << "YES\n";
                return;
            }
        }
        for (auto &j : f) {
            if (1LL * j * j > x)
                break;
            if (j == 2)
                continue;
            if (x % j == 0) {
                mp[j]++;
                if (mp[j] > 1) {
                    cout << "YES\n";
                    return;
                }
                while (x % j == 0) {
                    x /= j;
                }
            }
        }
        if (x > 1) {
            mp[x]++;
            if (mp[x] > 1) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}
int main() {
    int t;
    cin >> t;
    f = sieve(1e6 + 10);
    while (t--) {
        solve();
    }
}