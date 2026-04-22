#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

/*
 * We store max and min for each axis. (x and y).
 * Then we iterate all points.
 * We check if removing this points reults the rectange having equal to (n-1) blocks, then
 * either we can increase x axis or y axis, and get min area.
 * If blocks are not n-1, then just get min area by replacing with max with second max, and same for min.

 */

struct min_max {
    int mx1, mx2, mn1, mn2;
    min_max(int a, int b) {
        mx1 = a;
        mx2 = b;
        mn1 = a;
        mn2 = b;
        fix_mn();
        fix_mx();
    }

    void fix_mx() {
        if (mx1 < mx2) {
            swap(mx1, mx2);
        }
    }
    void fix_mn() {
        if (mn2 < mn1) {
            swap(mn1, mn2);
        }
    }

    void add(int point) {

        mx2 = max(mx2, point);
        mn2 = min(mn2, point);
        fix_mx();
        fix_mn();
    }

    int get_seg(int point) {
        pair<int, int> res = {mn1, mx1};
        // if point is extreme, then removing this can update the area, by taking second extreme.
        if (point == mn1) {
            res.first = mn2;
        }
        // if point is extreme, then removing this can update the area, by taking second extreme.
        if (point == mx1) {
            res.second = mx2;
        }

        return (res.second - res.first + 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> points(n);
        for (auto &x : points) {
            cin >> x.first >> x.second;
        }
        if (n <= 2) {
            cout << n << "\n";
            continue;
        }
        min_max xc(points[0].first, points[1].first);
        min_max yc(points[0].second, points[1].second);

        for (int i = 2; i < n; i++) {
            xc.add(points[i].first);
            yc.add(points[i].second);
        }

        long long ans = 1LL * xc.get_seg(-1) * yc.get_seg(-1); // get initial max and min.
        for (int i = 0; i < n; i++) {
            int x = xc.get_seg(points[i].first);
            int y = yc.get_seg(points[i].second);
            if (1LL * x * y == n - 1) {
                ans = min(ans, min(1LL * (x + 1) * y, 1LL * x * (y + 1)));
            } else {
                ans = min(ans, 1LL * x * y);
            }
        }
        cout << ans << "\n";
    }
}