#include "bits/stdc++.h"
using namespace std;

/*
 Segment Tree for frequency counting
 Index = compressed salary
 Value = number of employees with that salary
*/
struct SegmentTree {
    int size;
    vector<int> tree;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, 0);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] += v;   // frequency update (+1 or -1)
            return;
        }
        int m = (lx + rx) >> 1;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int sum(int l, int r, int x, int lx, int rx) {
        if (rx <= l || r <= lx) return 0;
        if (l <= lx && rx <= r) return tree[x];
        int m = (lx + rx) >> 1;
        return sum(l, r, 2 * x + 1, lx, m)
             + sum(l, r, 2 * x + 2, m, rx);
    }

    int sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> salary(n);
    for (int i = 0; i < n; i++)
        cin >> salary[i];

    vector<pair<char, pair<int,int>>> queries(q);
    vector<int> values;

    // collect values for compression
    for (int x : salary)
        values.push_back(x);

    for (int i = 0; i < q; i++) {
        char op;
        cin >> op;
        if (op == '!') {
            int k, x;
            cin >> k >> x;
            --k; // to 0-based
            queries[i] = {op, {k, x}};
            values.push_back(x);
        } else {
            int a, b;
            cin >> a >> b;
            queries[i] = {op, {a, b}};
            values.push_back(a);
            values.push_back(b);
        }
    }

    // coordinate compression
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    auto get_id = [&](int x) {
        return lower_bound(values.begin(), values.end(), x) - values.begin();
    };

    SegmentTree st;
    st.init(values.size());

    // build initial frequencies
    for (int x : salary)
        st.set(get_id(x), +1);

    // process queries
    for (auto &qq : queries) {
        char op = qq.first;
        if (op == '!') {
            int idx = qq.second.first;
            int new_salary = qq.second.second;

            // remove old salary
            st.set(get_id(salary[idx]), -1);

            // add new salary
            salary[idx] = new_salary;
            st.set(get_id(new_salary), +1);
        } else {
            int a = qq.second.first;
            int b = qq.second.second;

            int l = lower_bound(values.begin(), values.end(), a) - values.begin();
            int r = upper_bound(values.begin(), values.end(), b) - values.begin();

            cout << st.sum(l, r) << "\n";
        }
    }

    return 0;
}
