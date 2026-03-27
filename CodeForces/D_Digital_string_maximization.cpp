#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        string ans = "";

        int n = s.length();
        int i = 0;

        while (i < n) {
            if (s[i] == '#') {
                i++;
                continue;
            }

            int j = i;
            int idx = i;
            int num = s[i] - '0';
            int value = num;

            int processed = 0; // FIXED (was 1)

            while (j < n && processed <= (9 - num)) {
                if (s[j] == '#') {
                    j++;
                    continue;
                }

                int val = (s[j] - '0') - processed;
                if (val > value) {
                    value = val;
                    idx = j;
                }

                j++;
                processed++;
            }

            // append correctly
            ans += char('0' + value); // FIXED

            if (idx == i) {
                i++;
            } else {
                s[idx] = '#';
            }
        }

        cout << ans << "\n";
    }
}