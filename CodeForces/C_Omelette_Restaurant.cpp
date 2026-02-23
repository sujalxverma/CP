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
        int n, d;
        cin >> n >> d;

        vector<int> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        deque<pair<long long,int>> q;

        for (int i = 0; i < n; i++)
        {
            // 1️⃣ Add eggs
            q.push_back({a[i], i});

            // 2️⃣ Consume eggs (FIFO)
            long long need = b[i];
            while (need > 0)
            {
                auto &front = q.front();
                if (front.first <= need)
                {
                    need -= front.first;
                    q.pop_front();
                }
                else
                {
                    front.first -= need;
                    need = 0;
                }
            }

            // 3️⃣ Remove expired eggs
            while (!q.empty() && i - q.front().second >= d)
            {
                q.pop_front();
            }
        }

        long long ans = 0;
        for (auto &x : q)
            ans += x.first;

        cout << ans << "\n";
    }
}