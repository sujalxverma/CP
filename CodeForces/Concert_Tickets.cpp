#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        s.insert(k);
    }

    for(int i = 0; i < m ; i++){
        int k;
        cin >> k;
        auto it = s.lower_bound(k);
        if(*it == k){
            cout<<*it<<"\n";
            s.erase(s.find(*it)); 

        }
        else{
            if(it == s.begin()){
                cout<<-1<<"\n";
            }
            else{
                it--;
                cout<<(*it)<<"\n";
                s.erase(s.find(*it)); 
            }
        }
    }

    return 0;
}