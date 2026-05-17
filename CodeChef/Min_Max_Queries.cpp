#include <array>
#include <cstdint>
#include <iostream>
const int MAX_LIMIT = 3e5 + 10;
static std::array<int, MAX_LIMIT> a;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        size_t n;
        int q;
        std::cin >> n >> q;
        for (size_t i = 1; i <= n; i++) {
            std::cin >> a[i];
        }

        while (q--) {
            std::uint16_t x;
            std::cin >> x;
            if (x == 1) {
                size_t u;
                int v;
                std::cin >> u >> v;
                a[u] = v;
            } else {
                size_t l, r;
                std::cin >> l >> r;
                int len = r - l + 1;
                if (len == 1) {
                    std::cout << a[l] << "\n";
                    continue;
                } else if (!(len & 1)) {
                    int m = len / 2;
                    std::cout << (a[l + m - 1] > a[l + m] ? a[l + m - 1] : a[l + m]) << "\n";
                } else {
                    int m = len / 2;
                    int v1 = (a[m + l - 1] > a[m + l + 1] ? a[m + l - 1] : a[m + l + 1]);
                    int v2 = (a[m + l] < v1 ? a[m + l] : v1);
                    std::cout << v2 << "\n";
                }
            }
        }
    }

    return 0;
}