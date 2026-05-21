#include "bits/stdc++.h"
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    if ((int)s.size() == 1) {
        cout << "0\n";
        return;
    }
    sort(begin(a), end(a));
    vector<int> tg;
    {
        int v = a[0];
        set<int> vis;
        while (true) {
            if (vis.count(v))
                break;
            vis.insert(v);
            tg.push_back(v);
            if (v == 1) {
                if (!vis.count(2))
                    tg.push_back(2);
                break;
            }
            v = (v % 2 == 0) ? (v / 2) : (v + 1);
        }
    }

    int nt = tg.size();
    vector<int> mc(nt, 0);
    vector<ll> ts(nt, 0);
    vector<pair<int, int>> sp;
    for (int i = 0; i < n; i++) {
        if (sp.empty() || sp.back().first != a[i]) {
            sp.push_back({a[i], 1});
        } else {
            sp.back().second++;
        }
    }
    for (auto &[val, freq] : sp) {
        int v = val;
        int step = 0;
        bool visited_1 = false;
        bool visited_2 = false;

        unordered_map<int, int> lp;

        while (true) {
            if (v == 1) {
                if (visited_1)
                    break;
                visited_1 = true;
            }
            if (v == 2) {
                if (visited_2 && visited_1)
                    break;
                if (v == val && visited_2)
                    break;
                visited_2 = true;
            }

            if (!lp.count(v)) {
                lp[v] = step;
            }

            v = (v % 2 == 0) ? (v / 2) : (v + 1);
            step++;
        }

        for (int t_idx = 0; t_idx < nt; t_idx++) {
            int target_val = tg[t_idx];
            if (lp.count(target_val)) {
                mc[t_idx] += freq;
                ts[t_idx] += (1LL * lp[target_val] * freq);
            }
        }
    }
    ll cnt = 1e18;
    for (int i = 0; i < nt; i++) {
        if (mc[i] == n) {
            cnt = min(cnt, ts[i]);
        }
    }

    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}