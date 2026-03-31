#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<int> a;

/*
-First I implemented Bullshit on ans, but it did not worked out.

*/

bool f(int m) {
    vector<int> b((int)a.size());
    set<int> s;
    for (int i = 0; i < (int)a.size(); i++) {
        b[i] = a[i] | m;
        s.insert(b[i]);
    }
    if ((int)s.size() > 1) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int s = 0;
        int e = x;
        int ans = 0;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (f(m)) {
                ans = m;
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        cout << ans << "\n";
    }
}