#include "bits/stdc++.h"
using namespace std;
/*
N.
1. Traverse through the string s.
2. Select the character whose first occurence is highest in index (left to right), add it to result.
3. After selecting the k characters, if result length < n , then repeat it for the rest of the array, by ignoring
   the prefix upto this index.
4. if at any point result length is n, and s still remains, then answer is YES.
5. else check for any character in the first k alphabets which did not appear. if not then YES, else NO.
*/
void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    
    bool found[k];
    memset(found , false , sizeof(found)); // set all values of array found to false;


    string res = "";
    int count = 0;
    for(auto c : s){

        if(res.length() == n){
            break;
        }
        
        
        count += (!found[c-'a']);
        found[c-'a'] = true;

        if(count == k){
            memset(found , false , sizeof(found));
            res += c;
            count = 0;
            

        }


    }


    if(res.length() == n){
        cout<<"YES\n";
        return ;
    }

    for(int i = 0; i < k ; i++){
        if(found[i] == false){

            cout<<"NO\n";
            while(res.length() < n){
                res += char(i+'a');
            }
            cout<<res<<"\n";
            return ;
        }



        
    }


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}