#include "bits/stdc++.h"
using namespace std;

using i128 = __int128_t;

i128 read() {
    string s;
    cin >> s;

    i128 x = 0;
    int sign = 1;
    int i = 0;

    if (s[0] == '-') {
        sign = -1;
        i = 1;
    }

    for (; i < (int)s.size(); i++) {
        x = x * 10 + (s[i] - '0');
    }

    return x * sign;
}

void print(i128 x) {

    if (x == 0) {
        cout << 0;
        return;
    }

    if (x < 0) {
        cout << '-';
        x = -x;
    }

    string s;

    while (x > 0) {
        s += char('0' + x % 10);
        x /= 10;
    }

    reverse(s.begin(), s.end());

    cout << s;
}

i128 k;

i128 isqrt(i128 x) {

    i128 s = 0;
    i128 e = 10000000000LL; // 1e10

    i128 ans = 0;

    while (s <= e) {

        i128 m = s + (e - s) / 2;

        if (m * m <= x) {
            ans = m;
            s = m + 1;
        } else {
            e = m - 1;
        }
    }

    return ans;
}

bool f(i128 m) {
    return (m - isqrt(m)) >= k;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        k = read();

        i128 s = 1;
        i128 e = (i128)1e20;

        i128 ans = 0;

        while (s <= e) {

            i128 m = s + (e - s) / 2;

            if (f(m)) {
                ans = m;
                e = m - 1;
            } else {
                s = m + 1;
            }
        }

        print(ans);
        cout << '\n';
    }
}