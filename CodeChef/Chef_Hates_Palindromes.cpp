#include "bits/stdc++.h"
using namespace std;

void find(int n, int a){
    if(a==1){
        cout<<n<<" ";
        for(int i=0;i<n;i++)
            cout<<"a";
    }
    else if(a==2){
        if(n==1){
            cout<<"1 a";
        }
        else if(n==2){
            cout<<"1 ab"; 
        }
        else if(n==3)
            cout<<"2 abb";
        else if(n==4)
            cout<<"2 aabb";
        else if(n==5)
            cout<<"3 aabbb";
        else if(n==6)
            cout<<"3 aababb";
        else if(n==7)
            cout<<"3 aaababb";
        else if(n==8)
            cout<<"3 aaababbb";
        else{
            int q = n/6;
            int r = n%6;
            string s = "aababb";
            cout<<"4 ";
            for(int i=0;i<q;i++){
                cout<<s;
            }
            for(int i=0;i<r;i++)
                cout<<s[i];
        }
    }
    else{
        int q = n/3;
        int r = n%3;
        string s = "abc";
        cout<<"1 ";
        for(int i=0;i<q;i++)
            cout<<s;
        for(int i=0;i<r;i++)
            cout<<s[i];
    }
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a;
	    cin>>a;
	    find(n,a);
	    cout<<endl;
	}
	return 0;
}