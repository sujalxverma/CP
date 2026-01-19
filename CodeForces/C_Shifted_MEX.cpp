#include "bits/stdc++.h"
using namespace std;
vector<int> a;

// Calculate MEX for a range in a vector.
int calculateMex(const std::vector<int>& vec, int start, int end) {
    std::unordered_set<int> seen;
    // Insert elements from the subrange into the set
    for (int i = start; i <= end && i < (int)vec.size(); ++i) {
        if (vec[i] >= 0) {
            seen.insert(vec[i]);
        }
    }
    // Find the smallest non-negative integer not in the set
    int mex = 0;
    while (seen.count(mex)) {
        ++mex;
    }
    return mex;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        a.resize(n);
        for (auto &x : a)
        {
            cin >> x;
        }
        sort(begin(a), end(a));
        
        // brute force.
        int max_mex = 0;
        for(int i = 0; i < n ; i++){
            int mini = a[i];
            vector<int>b = a;
            for(int j = 0; j < n ; j++){
                b[j] -= mini;
            }

            int mex = calculateMex(b,0,n);
            max_mex = max(mex , max_mex);
        }
        cout<<max_mex<<"\n";
    }
    return 0;
}