#include "bits/stdc++.h"
using namespace std;

struct SqrtDec {
    int size;
    vector<unordered_set<int>> v;
    SqrtDec(int n, vector<int> &a) {
        size = (int)ceil(sqrt(n));
        int blocks = (n + size - 1) / size;
        v.resize(blocks);
        for (int i = 0; i < n; i++) {
            v[i / size].insert(a[i]);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}