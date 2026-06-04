#include "bits/stdc++.h"
using namespace std;

struct SqrtDec {
    int size;
    vector<vector<int>> v;
    vector<int> d;
    SqrtDec(int n, vector<int> &a) {
        size = (int)ceil(sqrt(n));
        int blocks = (n + size - 1) / size;
        v.resize(blocks);
        for (int i = 0; i < n; i++) {
            v[i / size].push_back(a[i]);
        }
        d = a;
    }

    int query(int l, int r, int x) {
        int cl = l / size;
        int cr = l / size;
        if (cl == cr) {
            int cnt = 0;
            for (int i = l; i <= r; i++) {
                if (d[i] >= x) {
                    cnt++;
                }
            }
            return cnt;
        }
        int cnt = 0;
        for (int i = l; i <= (cl + 1) * size - 1; i++) {
            if (d[i] >= x) {
                cnt++;
            }
        }
        for (int i = cr * size; i <= r; i++) {
            if (d[i] >= x) {
                cnt++;
            }
        }
        for (int i = cl + 1; i < cr; i++) {
            vector<int> k = v[i];
            sort(begin(k), end(k));
            cnt += (int)k.size() - (lower_bound(begin(k), end(k), x) - begin(k));
        }
        return cnt;
    }
    int update(int l, int x) {
        d[l] = x;
        v[l / size] = x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SqrtDec s(n, a);

    int q;
    cin >> q;
    while (q--) {
    }

    return 0;
}