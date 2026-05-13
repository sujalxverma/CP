#include "bits/stdc++.h"
using namespace std;
/*
 * We only care for last occurence of number in an array.
 * So we store elements in each array in reverse order of their last occurence.
 * eg -> [1,4,1,3,5,2,4,4] -> [4,2,5,3,1]
 * Now we will have n arrays of this form, and forms a matrix g.
 * Now sort the matrix g.
 * We have at g[0], the array with smallest starting number.
 * Then traverse this array and print number , and remove all its occurences from all other arrays.
 * Remove this array which is g[0], and sort the g again, until it becomes empty, and repeat.
 * This gives lexic smallest ans.
 */
int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            vector<int> a;
            int x;
            cin >> x;
            a.resize(x);
            for (int j = 0; j < x; j++) {
                cin >> a[j];
            }
            vector<int> vis(1e6 + 10, 0);
            for (int j = x - 1; j >= 0; j--) {
                if (vis[a[j]] == 0) {
                    vis[a[j]] = 1;
                    g[i].push_back(a[j]);
                }
            }
        }

        // for (auto &x : g) {
        //     for (auto &y : x) {
        //         cout << y << " ";
        //     }
        //     cout << "\n";
        // }
        while (!g.empty()) {
            sort(begin(g), end(g));
            for (int &x : g[0]) {
                cout << x << " ";
                for (int i = 1; i < (int)g.size(); i++) {
                    auto it = find(begin(g[i]), end(g[i]), x);
                    if (it != g[i].end()) {
                        g[i].erase(it);
                    }
                }
            }
            g.erase(g.begin());
        }
        cout << "\n";
    }

    return 0;
}