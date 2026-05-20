#include "bits/stdc++.h"
using namespace std;

using i128 = __int128_t;

i128 haveb, haves, havec;
i128 b, s, c;
string a;
i128 cb, cs, cc;
i128 r;

i128 to_i128(string s) {
    i128 x = 0;
    for (char c : s) {
        x = x * 10 + (c - '0');
    }
    return x;
}

i128 f(i128 m) {
    // can m burgers be made, with the resources and rubels available.
    i128 p = r;
    i128 breq = m * b;
    i128 sreq = m * s;
    i128 creq = m * c;

    if (breq - haveb > 0) {
        p -= (breq - haveb) * cb;
    }

    if (p < 0) {
        return 0;
    }

    if (sreq - haves > 0) {
        p -= (sreq - haves) * cs;
    }

    if (p < 0) {
        return 0;
    }

    if (creq - havec > 0) {
        p -= (creq - havec) * cc;
    }

    if (p < 0) {
        return 0;
    }

    return 1;
}

void print(i128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }

    string t;

    while (x > 0) {
        t += char('0' + x % 10);
        x /= 10;
    }

    reverse(t.begin(), t.end());

    cout << t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a;

    b = 0;
    s = 0;
    c = 0;

    for (long long i = 0; i < (long long)a.length(); i++) {
        if (a[i] == 'B')
            b++;

        if (a[i] == 'C')
            c++;

        if (a[i] == 'S')
            s++;
    }

    string x;

    cin >> x;
    haveb = to_i128(x);

    cin >> x;
    haves = to_i128(x);

    cin >> x;
    havec = to_i128(x);

    cin >> x;
    cb = to_i128(x);

    cin >> x;
    cs = to_i128(x);

    cin >> x;
    cc = to_i128(x);

    cin >> x;
    r = to_i128(x);

    i128 ans = 0;
    i128 st = 0;
    i128 e = (i128)1e18;

    while (st <= e) {
        i128 m = st + (e - st) / 2;

        if (f(m)) {
            ans = m;
            st = m + 1;
        } else {
            e = m - 1;
        }
    }

    print(ans);
    cout << "\n";

    return 0;
}