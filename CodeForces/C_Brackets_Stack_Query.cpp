#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int o = 0;
    int c = 0;
    stack<char> s;
    stack<char> p;

    while (n--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            char ch;
            cin >> ch;

            s.push(ch);
            p.push(ch);
            while (!p.empty() && p.top() == ')')
            {
                if (p.top() == ')')
                {
                    auto ch = p.top();
                    p.pop();
                    if (!p.empty() && p.top() == '(')
                    {
                        // pair formed.
                        p.pop();
                    }
                    else
                    {
                        p.push(ch);
                    }
                }
            }
            // if(p.size() == 1 && p.top() == ')'){
            //     cout<<"NO\n";
            // }
            if (!p.empty())
            {
                cout << "No\n";
            }
            else
            {
                cout << "Yes\n";
            }
        }
        else
        {
            if (p.empty())
            {
                s.pop();
                p.push('(');
                cout << "No\n";
            }
            else
            {
                if (p.size() == 1)
                {
                    s.pop();
                    p.pop();
                    cout << "Yes\n";
                }
                else
                {
                    s.pop();
                    p.pop();
                    cout << "No\n";
                }
            }
        }
    }
    return 0;
}