#include "bits/stdc++.h"
using namespace std;
vector<int> a;
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
            cin >> x;
        // best -> slowest. worst -> fastest
        vector<int> pref_max(n);
        pref_max[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            pref_max[i] = max(pref_max[i - 1], a[i]);
        }
  
        vector<int> b;
        for (int i = 0; i < n; i++)
        {
            int cnt = 1;
            for (int j = 0; j < i; j++)
            {
                if (a[j] > a[i])
                {
                    cnt++;
                }
            }
            for (int j = i+1; j < n; j++)
            {
                if (a[j] < pref_max[i])
                {
                    cnt++;
                }
            }
            b.push_back(cnt);
        }
        for(auto &x : b){
            cout<<x<<" ";
        }
        cout<<"\n";
        // return 0;
        cout << *min_element(b.begin(), b.end()) << " " << *max_element(b.begin(), b.end()) << "\n";
    }
    return 0;
}