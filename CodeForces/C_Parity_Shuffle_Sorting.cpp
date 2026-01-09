#include "bits/stdc++.h"
using namespace std;

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
        vector<int> odd;
        vector<int> even;

        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            if (k % 2)
            {
                odd.push_back(i + 1);
            }
            else
            {
                even.push_back(i + 1);
            }
        }
        cout << n - 1 << "\n";
        if ((int)odd.size() > 0)
        {
            for (int i = 0; i < (int)odd.size() - 1; i++)
            {
                cout << odd[i] << " " << odd[(int)odd.size() - 1] << "\n";
            }
            for (int j = 0; j < (int)even.size(); j++)
            {
                if(even[j] < odd[0]){
                    cout << even[j] << " " <<  odd[0]<< "\n";
                }else{
                    cout << odd[0] << " " <<  even[j]<< "\n";
                }
            }
        }
        else
        {
            for (int j = 0; j < (int)even.size() - 1; j++)
            {
                cout << even[j] << " " << even[(int)even.size() - 1] << "\n";
            }
        }
    }
    return 0;
}