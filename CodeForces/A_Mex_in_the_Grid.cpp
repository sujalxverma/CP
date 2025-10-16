#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void magical_spiral(int n) {
    vector<vector<int>> arr(n, vector<int>(n, -1));

    int x, y;
    if (n % 2 == 0)
        x = y = n / 2 - 1;
    else
        x = y = n / 2;

    arr[x][y] = 0;
    int value = 1, step = 1;

    int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // right, down, left, up

    while (value < n * n) {
        for (int d = 0; d < 4; ++d) {
            int steps = step;

            if (d % 2 == 1) step++; // Increase step after down or up

            int dx = dir[d][0], dy = dir[d][1];

            for (int i = 0; i < steps; ++i) {
                x += dx;
                y += dy;

                if (0 <= x && x < n && 0 <= y && y < n && arr[x][y] == -1) {
                    arr[x][y] = value;
                    value++;
                }

                if (value >= n * n) break;
            }

            if (value >= n * n) break;
        }
    }

    // Print the spiral grid
    for (const auto& row : arr) {
        for (int num : row)
            cout<< num << " ";
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        magical_spiral(n);
    }

    return 0;
}
