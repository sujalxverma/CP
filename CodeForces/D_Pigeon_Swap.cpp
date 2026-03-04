#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto start = high_resolution_clock::now();

  int n, q;
  cin >> n >> q;

  /*
  Op. 1 -> 1 a b -> move pigeon a from current net to net b.
  Op. 2 -> 2 a b -> swap pigeons in net a and b.
  Op. 3 -> 3 a   -> tell position of pigeon indexd a.
  */

  vector<int> location(n + 1);
  for (int i = 1; i <= n; i++)
    location[i] = i;

  while (q--) {
    int op;
    cin >> op;

    if (op == 1) {
      int pigeonA, netB;
      cin >> pigeonA >> netB;
      location[pigeonA] = netB;
    }

    if (op == 2) {
      int netA, netB;
      cin >> netA >> netB;
      for (int i = 1; i <= n; i++) {
        if (location[i] == netA) {
          location[i] = netB;
        } else if (location[i] == netB) {
          location[i] = netA;
        }
      }
    }

    if (op == 3) {
      int pigeon;
      cin >> pigeon;
      cout << location[pigeon] << "\n";
    }
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << "Time taken: " << duration.count() << " microseconds\n";

  return 0;
}