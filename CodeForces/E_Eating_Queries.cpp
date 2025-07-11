#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

// Binary Search: Find the minimum index such that prefix sum >= query
int lower_bound_prefix(const vector<ll>& prefix, ll query) {
    int left = 0;
    int right = prefix.size() - 1;
    int answer = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (prefix[mid] >= query) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer == -1 ? -1 : answer + 1;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort in descending order
    sort(a.begin(), a.end(), greater<ll>());

    // Compute prefix sums
    vector<ll> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    // Process queries
    while (q--) {
        ll candy;
        cin >> candy;
        cout << lower_bound_prefix(prefix, candy) << '\n';
    }
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
