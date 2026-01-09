#include "bits/stdc++.h"
using namespace std;
vector<long long> a;
vector<long long> b;

/*
1. The optimal strategy was to find out, that it is better to choose the max element in their turn.
2. I was able to figure out this, and also thought that it is a simulation game.
3. But AI just confused me. Damn.

*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        a.resize(n);
        b.resize(m);
        priority_queue<long long> pq_Alice, pq_Bob;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            pq_Alice.push(a[i]);
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
            pq_Bob.push(b[i]);
        }
        char turn = 1; // 1 -> Alice, 0 -> Bob
        while (!pq_Alice.empty() && !pq_Bob.empty())
        {
            if (turn)
            {
                long long maxA = pq_Alice.top();
                long long maxB = pq_Bob.top();
                pq_Bob.pop();
                maxB -= maxA;
                if (maxB > 0)
                {
                    pq_Bob.push(maxB);
                }
                turn = !turn;
            }
            else
            {
                long long maxA = pq_Alice.top();
                pq_Alice.pop();
                long long maxB = pq_Bob.top();
                maxA -= maxB;
                if (maxA > 0)
                {
                    pq_Alice.push(maxA);
                }
                turn = !turn;
            }
        }

        if (!pq_Alice.empty())
        {
            cout << "Alice\n";
        }
        else
        {
            cout << "Bob\n";
        }
    }
    return 0;
}