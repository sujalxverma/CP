#include "bits/stdc++.h"
using namespace std;
using ll = long long;

/*
1. Trivial Case,
2. Place the largest odd, then place all even, say sum = X, and smallest even is sm.
3. Now, we have to place odd numbers, place two smallest odd, they vanish, and now place sum = X-sm, for this value of k.
4. Now place sum=X, again.
5. Repeat this process. If number of odd is even. They last answer is always 0. because sum becomes even.
6. Otherwise upper sum ans sm case will work fine.
*/

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
        vector<ll> odd, even;
        vector<ll> nums(n);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            ll k;
            cin >> k;
            nums[i] = k;
            if (k % 2 == 0)
            {
                even.push_back(k);
                // sum += k;
            }
            else
                odd.push_back(k);
        }
        sort(odd.rbegin(), odd.rend());
        sort(even.rbegin(), even.rend());

        if (odd.size() == 1)
        {
            ll sum = *odd.begin();
            cout << *odd.begin() << " ";
            for (auto &x : even)
            {
                sum += x;
                cout << sum << " ";
            }
            cout << "\n";
            continue;
        }
        else if (odd.size() == 0)
        {
            // cout<<*odd.begin()<<" ";
            for (auto &x : even)
            {
                cout << 0 << " ";
            }
            cout << "\n";
            continue;
        }

        else if (even.size() == 0)
        {
            ll maxi = *max_element(odd.begin(),odd.end());
            for(int i = 1 ; i <= n ; i++){
                if(i%2 == 1){
                    cout<<maxi<<" ";
                }
                else{
                    cout<<"0 ";
                }
            }
            cout << "\n";
            continue;
        }

        cout << odd[0] << " ";
        sum = odd[0];
        for (int i = 0; i < even.size(); i++)
        {
            sum += even[i];
            cout << sum << " ";
        }
        ll k = 1 + even.size();
        ll prev = even[even.size() - 1];
        while (k < n)
        {
            if (odd.size() > 2)
            {
                cout << sum - prev << " " << sum << " ";
                odd.pop_back();
                odd.pop_back();
                k += 2;
            }
            else
            {
                cout << 0 << " ";
                break;
            }
        }
        cout << "\n";
    }
    return 0;
}