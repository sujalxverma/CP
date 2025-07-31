#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vec;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define yes cout << "YES\n"
#define no cout << "NO\n"

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

inline bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i*i <= num; i += 2)
        if (num % i == 0) return false;
    return true;
}

inline int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

inline int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

void solve() {
    int n, targetSum;
    cin >> n >> targetSum;

    vec values(n);
    int currentSum = 0;
    int countZero = 0, countOne = 0, countTwo = 0;

    rep(i, 0, n) {
        cin >> values[i];
        currentSum += values[i];
        if (values[i] == 0) countZero++;
        else if (values[i] == 1) countOne++;
        else if (values[i] == 2) countTwo++;
    }

    int difference = targetSum - currentSum;

    if (difference < 0 || difference == 1) {
        bool firstPrinted = false;
        rep(i, 0, countZero) {
            if (firstPrinted) cout << ' ';
            cout << 0;
            firstPrinted = true;
        }
        rep(i, 0, countTwo) {
            if (firstPrinted) cout << ' ';
            cout << 2;
            firstPrinted = true;
        }
        rep(i, 0, countOne) {
            if (firstPrinted) cout << ' ';
            cout << 1;
            firstPrinted = true;
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll testCases;
    cin >> testCases;
    while (testCases--) {
        solve();
    }

    return 0;
}
