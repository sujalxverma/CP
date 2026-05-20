#include "bits/stdc++.h"
using namespace std;
void sortParityIndices(vector<int> &a) {
    vector<int> even, odd;

    // collect
    for (int i = 0; i < (int)a.size(); ++i) {
        if (i % 2 == 0)
            even.push_back(a[i]);
        else
            odd.push_back(a[i]);
    }

    // sort
    sort(even.begin(), even.end(), greater<int>()); // descending
    sort(odd.begin(), odd.end());                   // ascending

    // put back
    int e = 0, o = 0;

    for (int i = 0; i < (int)a.size(); ++i) {
        if (i % 2 == 0)
            a[i] = even[e++];
        else
            a[i] = odd[o++];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sortParityIndices(a);
        int ans = 0;
        for (int i = 0; i < n; i += 2) {
            int sum = 0;
            for (int j = i + 1; j < n; j += 2) {
                sum += a[j];
            }
            ans += sum * a[i];
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        cout << ans << "\n";
    }

    return 0;
}