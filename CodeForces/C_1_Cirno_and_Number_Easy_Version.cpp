#include "bits/stdc++.h"
using namespace std;
#define int long long
int a, n;
long long f(vector<int> &d, vector<int> &nums, int len, int smaller) {
    long long ans = 0;
    const long long INF = (long long)4e18;

    int size = nums.size();

    if (len == size && smaller == 1) {
        int idx = upper_bound(begin(d), end(d), nums[0]) - begin(d);

        if (idx == 0)
            return INF;

        idx--;
        ans = d[idx];

        len--;
        for (int i = 0; i < len; i++) {
            ans = ans * 10 + d.back();
        }
        return ans;
    }

    else if (len == size && smaller == 0) {
        int idx = upper_bound(begin(d), end(d), nums[0]) - begin(d);

        if (idx >= (int)d.size())
            return INF;

        ans = d[idx];

        len--;
        for (int i = 0; i < len; i++) {
            ans = ans * 10 + d[0];
        }
        return ans;
    }

    // MUST COME BEFORE len < size
    else if (smaller == 3 && len == -1) {
        for (int i = 0; i < size; i++) {

            int idx = lower_bound(begin(d), end(d), nums[i]) - begin(d);

            if (idx < (int)d.size() && d[idx] == nums[i]) {
                ans = ans * 10 + d[idx];
            } else {

                long long v1 = ans;
                long long v2 = ans;

                for (int j = i; j < size; j++) {
                    v1 = v1 * 10 + d[0];
                    v2 = v2 * 10 + d.back();
                }

                if (llabs(a - v1) < llabs(a - v2))
                    return v1;
                else
                    return v2;
            }
        }

        return ans;
    }

    else if (len < size) {
        if (len == 0)
            return INF;

        for (int i = 0; i < len; i++) {
            ans = ans * 10 + d.back();
        }
        return ans;
    }

    else if (len > size) {
        if (len > 17)
            return INF;

        for (int i = 0; i < len; i++) {
            ans = ans * 10 + d[0];
        }

        if (ans > (long long)1e17)
            return INF;

        return ans;
    }

    return ans;
}

void solve() {
    cin >> a >> n;
    vector<int> d(n);
    for (auto &x : d) {
        cin >> x;
    }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    int dig = a;
    vector<int> nums;
    while (dig > 0) {
        nums.push_back(dig % 10);
        dig = dig / 10;
    }
    reverse(begin(nums), end(nums));
    if (a == 0) {
        cout << d[0] << "\n";
        return;
    }
    int len = nums.size();
    // equal and smaller
    int v1 = f(d, nums, len, 1);
    // equal and larger
    int v2 = f(d, nums, len, 0);
    // len < size
    int v3 = f(d, nums, len - 1, 0);
    // len > size
    int v4 = f(d, nums, len + 1, 0);
    int v5 = f(d, nums, -1, 3);
    cout << min({abs(a - v1), abs(a - v2), abs(a - v3), abs(a - v4), abs(a - v5)}) << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}