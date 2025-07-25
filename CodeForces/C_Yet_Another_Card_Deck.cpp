#include "bits/stdc++.h"
using namespace std;

/*
    Approach:
    ----------
    Given a deck of n cards, each with a color (value between 1 and 50).
    For each of q queries, we are asked for the 1-based position of the highest card (closest to the top, i.e., leftmost in array) with a given color.
    Then, we simulate taking that card and placing it on the top of the deck, adjusting the order.
    Observation:
      - Since color values are only from 1 to 50, we can use an array to track the current position (index) of the topmost card of each color.
      - When we move a color to the top, all other colors that were above it (i.e., had a lower index) now get pushed one position lower.
      - We only need to update positions in our position-array accordingly.
    Rationale:
      - For efficiency: Instead of storing the full deck, we maintain for each color 'c' the position of its current topmost instance.
      - This is possible because colors are at most 50, so updates and queries are O(50) per operation.
      - A full deck simulation with n cards and shifts/insertions would be too slow.
*/

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> topPosition(51, n + 1); // topPosition[color] = 1-based position of topmost card of this color
    vector<int> initialColors(n + 1);   // 1-based index for the deck's card colors

    // Read deck colors and store the topmost position for each color
    for (int i = 1; i <= n; i++) {
        int color;
        cin >> color;
        initialColors[i] = color;
        if (topPosition[color] == n + 1) {
            topPosition[color] = i;
        }
    }

    // Process queries
    while (q--) {
        int queryColor;
        cin >> queryColor;
        int pos = topPosition[queryColor];
        cout << pos << " ";

        // Increment indices for colors that are above (have smaller position) than current query color
        for (int c = 1; c <= 50; c++) {
            if (topPosition[c] < pos) {
                topPosition[c]++;
            }
        }
        topPosition[queryColor] = 1; // Move queried color to the top
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
