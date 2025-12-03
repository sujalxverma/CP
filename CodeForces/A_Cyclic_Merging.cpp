#include "bits/stdc++.h"
using namespace std;

/*
No, I do not understand the solution.

We consider a simple strategy: repeatedly merge the smallest element onto the smaller of its two neighbours.

We will prove this greedy is correct: For any merge sequence, consider the smallest element 𝑚𝑛
, it must be merged into a larger element at some point in the future. However, its neighbour will not be smaller, which means that we can simply modify the merge sequence to merge 𝑚𝑛
 into its neighbours at the very first.

Further observation will show that this value is equal to ∑𝑛−1𝑖=1max(𝑎𝑖,𝑎𝑖+1)+max(𝑎𝑛,𝑎1)−max(𝑎1,𝑎2,⋯,𝑎𝑛)
. A brief sketch of the proof is as follows: It can be shown that we can break the ring into a sequence at an arbitrary maxima, since the maxima will not be merged into others.

For the problem on a sequence, consider each element 𝑎𝑖
, find the closest element 𝑎𝑥
 to the left of 𝑎𝑖
, such that 𝑎𝑥>𝑎𝑖
 (when equal, break ties according to index). If there are elements between 𝑎𝑥
 and 𝑎𝑖
, then it's clear that in performing the aforementioned greedy, at some point we will merge everything in 𝑎𝑥+1,𝑎𝑥+2,⋯,𝑎𝑖
 into a single element, and then merge it into 𝑎𝑖
. Therefore the answer will be increased by 𝑎𝑖
 if 𝑎𝑖−1<𝑎𝑖
. The same thing will happen to the right of 𝑎𝑖
. Therefore the answer is ∑𝑛−1𝑖=1[𝑎𝑖≥𝑎𝑖+1]𝑎𝑖+[𝑎𝑖<𝑎𝑖+1]𝑎𝑖+1
, which can be rephrased as ∑𝑛−1𝑖=1max(𝑎𝑖,𝑎𝑖+1)
, which in turn is the formula above.

However, this is not needed to pass the problem. We expected participants to pass using doubly linked lists, sets, or any other data structures which can support the operations needed.

Time Complexity: 𝑂(𝑛)
 or 𝑂(𝑛log𝑛)
.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>a(n);
        for(auto &x : a){
            cin >> x;
        }
        int ans = 0;
        for(int i = 0 ; i < n - 1 ; i++){
            ans += max(a[i],a[i+1]);
        }
        ans += max(a[0] , a[n-1]);
        ans -= *max_element(a.begin(),a.end());
        cout<<ans<<"\n";
        
    }
    return 0;
}