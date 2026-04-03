#include <iostream>
#include <vector>
using namespace std;

/*
 * We have 2n cards, like 1,1,2,2,...,n,n.
 * Greedy Algo as stated :
 * If current card flipped has number x, and previously we have flipped card that has number x, then flip
 * that card as your second card, can discard both cards.
 * Otherwise, flip that card that we have never flipped so far.
 * We need to find an orientation of 2n cards, such that it takes exactly k turns to win the game.
 * If not possible, then print NO.
 * Game is won, when all cards are discarded.
 * Before flipping, i have to check if some seen cards matched.
 * If not then do the flipping process.
 */
/*
 * If k < n || k >= 2*n, then No.
 * Range for answer to be YES, is [n , 2*n-1]
 * min_delay possible is = 0.
 * max_delay possible is n-1.
 * So we greedily makes the orientation.
 * First solve for delay part, then total discards are always n.
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        // if k == n, then pattern is : 1,1,2,2,...,n,n , delay = 0.
        if (k == n) {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) {
                cout << i << " " << i << " ";
            }
            cout << "\n";
            continue;
        }
        // if k < n || k >= 2n, then no orientation possible, not enough moves.
        if (k < n || k >= 2 * n) {
            cout << "NO\n";
            continue;
        }
        // [n+1 , 2n - 1]
        // min_delay = 1,
        // max_delay = n-1
        if (1 + n <= k && k <= n + n - 1) {
            cout << "YES\n";
            int delays = k - n;
            vector<int> nums(n + 1, 2);
            cout << 1 << " " << 2 << " ";
            nums[1]--;
            nums[2]--;
            int e = 3;
            int s = 1;
            delays--;
            while (delays--) {
                cout << e << " " << s << " ";
                nums[e]--;
                nums[s]--;
                e++;
                s++;
            }
            for (int i = 1; i <= n; i++) {
                while (nums[i]--) {
                    cout << i << " ";
                }
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }
}