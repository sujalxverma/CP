#include "bits/stdc++.h"
using namespace std;

bool Takahashi(string a, string s)
{
    int n = a.length();
    bool f = false;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i] == a[j])
            {
                f = true;
                break;
            }
        }
        if (!f)
        {
            return false;
        }
        f = false;
    }
    return true;
}

bool Aoki(string a, string s)
{
    int n = a.length();
    bool f = false;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i] == a[j])
            {
                f = true;
                break;
            }
        }
        if (!f)
        {
            return false;
        }
        f = false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        bool f1 = Takahashi(a, s);
        bool f2 = Takahashi(b, s);
        if (f1 && f2)
        {
            cout << "Unknown\n";
        }
        else if (f1)
        {
            cout << "Takahashi" << "\n";
        }
        else if (f2)
        {
            cout << "Aoki\n";
        }
        else
        {
            cout << "Unknown\n";
        }
    }
    return 0;
}