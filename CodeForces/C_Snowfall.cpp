#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % 6 == 0) {
                b.push_back(x);
            } else {
                a.push_back(x);
            }
        }
        for (int i = 0; i < (int)b.size(); i++) {
            cout << b[i] << " ";
        }
        sort(begin(a), end(a));
        vector<int> two, three, notty;
        for (int i = 0; i < (int)a.size(); i++) {
            if (a[i] % 2 == 0) {
                two.push_back(a[i]);
            } else if (a[i] % 3 == 0) {
                three.push_back(a[i]);
            } else {
                notty.push_back(a[i]);
            }
        }
        if ((int)two.size() < (int)three.size()) {
            for (int i = 0; i < (int)two.size(); i++) {
                cout << two[i] << " ";
            }
            for (int i = 0; i < (int)notty.size(); i++) {
                cout << notty[i] << " ";
            }
            for (int i = 0; i < (int)three.size(); i++) {
                cout << three[i] << " ";
            }
            cout << "\n";

        } else {
            for (int i = 0; i < (int)three.size(); i++) {
                cout << three[i] << " ";
            }

            for (int i = 0; i < (int)notty.size(); i++) {
                cout << notty[i] << " ";
            }

            for (int i = 0; i < (int)two.size(); i++) {
                cout << two[i] << " ";
            }

            cout << "\n";
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}