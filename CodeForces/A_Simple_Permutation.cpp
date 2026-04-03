#include <iostream>
#include <vector>
using namespace std;
/*
 * Create a permutation such that.
 * Ci = ceil((p1 + p2 + p3 ... + pi)/i)
 * And there are atleast floor(n / 3) - 1, prime numbers in array C.
 * A permutation always exist.
 *
 * Lemma (Bertrand's postulate): For each positive integer 𝑥, there is a prime 𝑝 inside the interval [𝑥,2𝑥].
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
    // vector<int> primes;
    // for (int i = 2; i <= n; i++) {
    //     if (f[i] == 0)
    //         primes.push_back(i);
    // }
    return f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<int> f = sieve(1e5 + 10);
    while (t--) {
        int n;
        cin >> n;
        if (n == 2) {
            cout << "2 1\n";
            continue;
        }
        int s = n / 3;
        int e = (2 * n + 2) / 3;
        int p = 0;
        for (int i = s; i <= e; i++) {
            if (f[i] == 0) {
                p = i;
                break;
            }
        }
        vector<int> nums(n + 1, 0);
        s = 1;
        cout << p << " ";
        nums[p] = 1;
        while ((p - s) >= 1 && (p + s) <= n) {
            cout << p - s << " " << p + s << " ";
            nums[p - s]++;
            nums[p + s]++;
            s++;
        }
        for (int i = 1; i <= n; i++) {
            if (nums[i] == 0) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
}