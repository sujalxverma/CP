#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

// Returns integer cents from a string "x.yy"
int toCents(const string &s) {
    size_t dot = s.find('.');
    int whole = stoi(s.substr(0, dot));
    int frac = stoi(s.substr(dot + 1));
    return whole * 100 + frac;
}

string toStringCents(int cents) {
    ostringstream oss;
    oss << (cents / 100) << '.' << setw(2) << setfill('0') << (cents % 100);
    return oss.str();
}

int main() {
    vector<int> v(4);
    string in;
    for (int i = 0; i < 4; ++i) {
        cin >> in;
        v[i] = toCents(in);
    }
    cin >> in;
    int T = toCents(in);

    sort(v.begin(), v.end());
    int a = v[0], b = v[1], c = v[2], d = v[3];
    long long thr = 1LL * 3 * T;

    // Case: "infinite"
    if (1LL * b + c + d <= thr) {
        cout << "infinite\n";
        return 0;
    }

    int best = -1;
    auto update = [&](int L, int R, long long upper, bool lim) {
        L = max(L, 100);
        R = min(R, 2000);
        if (L > R) return;
        int hi = R;
        if (lim) hi = min(hi, (int)upper);
        if (hi < L) return;
        best = max(best, hi);
    };

    // x ≤ a: drop x and d, keep a+b+c
    if (1LL * a + b + c <= thr)
        update(INT_MIN, a, 0, false);

    // a ≤ x ≤ b : drop a and d, keep x+b+c
    update(a, b, thr - (1LL * b + c), true);

    // b ≤ x ≤ c : drop a and d, keep b+x+c
    update(b, c, thr - (1LL * b + c), true);

    // c ≤ x ≤ d : drop a and d, keep b+c+x
    update(c, d, thr - (1LL * b + c), true);

    if (best == -1)
        cout << "impossible\n";
    else
        cout << toStringCents(best) << '\n';
}
