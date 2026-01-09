#include "bits/stdc++.h"
using namespace std;
vector<int> a;
set<int> s;
void rotate_subarray_by_one(vector<int> &a, int l, int r)
{
    if (l >= r)
        return;

    int last = a[r];
    for (int i = r; i > l; --i)
    {
        a[i] = a[i - 1];
    }
    a[l] = last;
}

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
        a.resize(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        int num = *s.begin();
        int l = 1;
        int r = 1;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == num)
            {
                r = i;
                rotate_subarray_by_one(a, l, r);
                for (int j = l; j < i; j++)
                {
                    auto it = s.find(a[j]);
                    s.erase(it);
                }
                num = *s.begin();
                l = i;
                if (num == a[i])
                {
                    s.erase(s.begin());
                    if (!s.empty())
                    {
                        num = *s.begin();
                        l++;
                        r++;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}