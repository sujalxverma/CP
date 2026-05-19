#include "bits/stdc++.h"
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);
    for (long long i = 1; i <= n; i++)
        cin >> a[i];
    vector<long long> prefix(n + 1, 0);
    vector<long long> suffix(n + 1, a[n]);
    for (long long i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    for (long long i = n - 1; i >= 1; i--) {
        suffix[i] = suffix[i + 1] + a[i];
    }

    vector<long long> maxprefix(n + 1);
    vector<long long> idxprefix(n + 1);
    vector<long long> maxsuffix(n + 1);
    vector<long long> idxsuffix(n + 1);

    long long maxsum = prefix[k];
    long long idx = k;
    maxprefix[k] = maxsum;
    idxprefix[k] = idx;
    // construct prefix max sum.
    for (long long i = k + 1; i <= n; i++) {
        long long sum = prefix[i] - prefix[i - k];
        if (sum == maxsum) {
            maxprefix[i] = sum;
            idxprefix[i] = idx;
        } else if (sum > maxsum) {
            idx = i;
            maxsum = sum;
            maxprefix[i] = sum;
            idxprefix[i] = idx;
        } else {
            maxprefix[i] = maxsum;
            idxprefix[i] = idx;
        }
    }

    maxsum = suffix[n - k + 1];
    idx = n - k + 1;
    maxsuffix[n - k + 1] = maxsum;
    idxsuffix[n - k + 1] = idx;
    // construct suffix max sum
    for (long long i = n - k; i >= 1; i--) {
        long long sum = suffix[i] - suffix[i + k];
        if (sum == maxsum) {
            maxsuffix[i] = maxsum;
            idxsuffix[i] = i;
            idx = i;
        } else if (sum > maxsum) {
            idx = i;
            maxsum = sum;
            maxsuffix[i] = sum;
            idxsuffix[i] = idx;
        } else {
            maxsuffix[i] = maxsum;
            idxsuffix[i] = idx;
        }
    }
    long long ptr1;
    long long ptr2;
    maxsum = 0;
    // greedily check.
    for (long long i = k; i <= n - k; i++) {
        long long sum = maxprefix[i] + maxsuffix[i + 1];
        if (sum > maxsum) {
            maxsum = sum;
            ptr1 = idxprefix[i];
            ptr2 = idxsuffix[i + 1];
        } else if (sum == maxsum) {
            // do nothing
        } else {
            // do nothing
        }
    }
    cout << ptr1 - k + 1 << " " << ptr2 << "\n";
    return 0;
}