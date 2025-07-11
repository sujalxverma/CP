#include <iostream>
#include <vector>

using namespace std;

bool isEven(int number) {
    return number % 2 == 0;
}

void solve() {
    int n;
    cin >> n;

    int target;
    cin >> target;

    vector<int> oddNumbers;
    vector<int> evenNumbers;

    // Fill odd numbers: 1, 3, 5, ..., up to n
    for (int i = 1; i <= n; i += 2) {
        oddNumbers.push_back(i);
    }

    // Fill even numbers: n, n-2, ..., down to 2
    for (int i = n; i >= 2; i -= 2) {
        evenNumbers.push_back(i);
    }

    if (isEven(target)) {
        // Search in even numbers
        for (int i = 0; i < evenNumbers.size(); ++i) {
            if (evenNumbers[i] == target) {
                cout << i + 1 << '\n';
                return;
            }
        }
    } else {
        // Search in odd numbers
        for (int i = 0; i < oddNumbers.size(); ++i) {
            if (oddNumbers[i] == target) {
                cout << i + 1 << '\n';
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(); // For a single test case

    return 0;
}
