#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    string s;
    cin >> s;
    int n = (int)s.length();

    set<int> st;
    vector<int> fr(25, 0);
    for (int i = 0; i < n; i++)
    {
        fr[s[i] - 'a']++;
    }

    int maxi = *max_element(fr.begin(), fr.end());

    for (int i = 0; i < 26; i++)
    {
        if (fr[i] == maxi)
        {
            st.insert(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';
        if (st.find(c) == st.end())
        {
            cout << s[i] << "";
        }
        
    
    }


        cout << "\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}