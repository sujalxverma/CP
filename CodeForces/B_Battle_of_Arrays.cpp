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
    int n, m;
    cin >> n >> m;
    priority_queue<int> alice, bob;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      alice.push((x));
    }
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      bob.push(x);
    }

    int chance = 0; // 0 -> alice , 1 -> bob

    while (!alice.empty() && !bob.empty()) {
      if (chance == 0) {
        // alice
        int x = alice.top();
        int y = bob.top();
        alice.pop();
        bob.pop();

        if (y <= x) {
          alice.push(x);
        } else {
          bob.push(y - x);
          alice.push(x);
        }

        chance = !chance;

      } else {
        int x = bob.top();
        int y = alice.top();
        alice.pop();
        bob.pop();
        if (y <= x) {
          bob.push(x);
        } else {
          alice.push(y - x);
          bob.push(x);
        }
        chance = !chance;
      }
    }
    if (alice.empty()) {
      cout << "Bob\n";
    } else {
      cout << "Alice\n";
    }
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << "Time taken: " << duration.count() << " microseconds\n";

  return 0;
}