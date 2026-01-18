#include "bits/stdc++.h"
using namespace std;


int main()
{
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        deque<char> dq;
        bool v=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(v==0){
                if(s[i]=='a'|| s[i]=='e' || s[i]=='i'|| s[i]=='o'||s[i]=='u'){
                    c++;
                    v=1;
                    dq.push_front(s[i]);
                }
                else{
                    dq.push_back(s[i]);
                }
            }
            else{
                if(s[i]=='a'|| s[i]=='e' || s[i]=='i'|| s[i]=='o'||s[i]=='u'){
                    c++;
                    v=0;
                    dq.push_back(s[i]);
                    
                }
                else{
                    dq.push_front(s[i]);
                }
            }
        }
        
        string ans="";
        for(int i=0;i<s.length();i++){
            if(c%2==1){
                
                ans+=(dq.back());
                dq.pop_back();
            }
            else{
                ans+=(dq.front());
                dq.pop_front();
            }
        }
        
        cout<<ans<<endl;
    }
}