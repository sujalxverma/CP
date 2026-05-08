#include "bits/stdc++.h"
using namespace std;

int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = (int)s.length();
    char prev = s[n - 1];
    char curr;
    int two = 0;
    int three = 0;
    for (int i = n - 2; i >= 0; i--) {
        curr = s[i];
        if (prev == curr) {
            two++;
        }
    }

    return 0;
}