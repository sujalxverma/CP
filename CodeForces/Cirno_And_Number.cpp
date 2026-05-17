#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int a, n;
vector<int> nums;
vector<int> d;

/*
 * If size of A is say k, then optimal numbers will have size :
 * (k-1) , (k) , (k+1)
 */

void dfs(long long number, int idx, long long &ans) {
    if (idx == (int)nums.size()) {
        ans = min(ans, abs(number - a));
        return;
    }
    for (int i = 0; i < (int)d.size(); i++) {
        int x = d[i];
        if (idx == 0 && nums.size() > 1 && x == 0) {
            // avoid leading zeroes.
            continue;
        }
        if (nums[idx] == x) {
            dfs(number * 10 + x, idx + 1, ans);
        } else if (x > nums[idx]) {
            // append smallest afterwards
            long long value = number * 10 + x;
            for (int j = idx + 1; j < (int)nums.size(); j++) {
                value = value * 10 + d.front();
            }
            ans = min(ans, abs(value - a));
            break;
        } else {
            // append largest digit
            long long value = number * 10 + x;
            for (int j = idx + 1; j < (int)nums.size(); j++) {
                value = value * 10 + d.back();
            }
            ans = min(ans, abs(value - a));
            if (i + 1 < (int)d.size() && d[i + 1] < nums[idx]) {
                continue;
            }
            break;
        }
    }
    return;
}
void f(long long &ans) {
    if (nums[0] == 0) {
        ans = min(ans, 1LL * a);
    }
    // for numbers of size == size(a)
    dfs(0, 0, ans);
    // for numbers of size == size(a)-1
    if (nums.size() > 1) {
        long long value = -1;
        if (d.back() != 0) {
            value = d.back();
            for (int i = 1; i < (int)nums.size() - 1; i++) {
                value = value * 10 + d.back();
            }
            ans = min(ans, abs(value - a));
        } else {
            ans = min(ans, 1LL * a);
        }
    }
    // for number of size == size(a)+1
    {
        // starting of number should be non-zero.
        long long value = -1;
        for (auto &x : d) {
            if (x != 0) {
                value = x;
                break;
            }
        }
        if (value != -1) {
            for (int i = 1; i < (int)nums.size() + 1; i++) {
                value = value * 10 + d.front();
            }
            ans = min(ans, abs(value - a));
        }
    }
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long ans = 1e18;
        nums.clear();
        cin >> a >> n;
        d.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        sort(begin(d), end(d));
        d.erase(unique(begin(d), end(d)), end(d));
        int copy = a;
        while (copy > 0) {
            nums.push_back(copy % 10);
            copy /= 10;
        }
        if (a == 0) {
            nums.push_back(0);
        }
        reverse(begin(nums), end(nums));
        f(ans);
        cout << ans << "\n";
    }
}