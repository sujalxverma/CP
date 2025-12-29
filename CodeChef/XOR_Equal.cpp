#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long n, X;
        cin >> n >> X;

        unordered_map<long long, long long> mp;
        long long maxF = 0;
        long long moves = (long long)1e18;
        vector<ll> a(n);

        for (long long i = 0; i < n; i++)
        {
            long long k;
            cin >> k;
            mp[k]++;
            maxF = max(maxF, mp[k]);
            a[i] = k;
        }
        if(X == 0){
            cout<<maxF<<" "<<0<<"\n";
            continue;
        }
        for (auto &[key, cnt] : mp)
        {
            ll count_xor = 0;
            for (int i = 0; i < n; i++)
            {
                if ((a[i] ^ X) == key)
                {
                    count_xor++;
                }

            }

                if (count_xor + cnt > maxF)
                {
                    maxF = count_xor + cnt;
                    moves = count_xor;
                }
                else if (count_xor + cnt == maxF)
                {
                    moves = min(count_xor, moves);
                }
        }

        if (moves == (long long)1e18)
        {
            moves = 0;
        }

        cout << maxF << " " << moves << "\n";
    }
    return 0;
}

#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        long long X;
        cin >> N >> X;

        vector<long long> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        unordered_map<long long, int> freq;
        for (int i = 0; i < N; i++)
            freq[A[i]]++;

        int max_count = 0;
        int min_ops = INT_MAX;

        for (auto &p : freq)
        {
            long long num = p.first;
            int count_orig = freq[num];
            int count_xor = 0;
            if (X != 0)
            {
                for (int i = 0; i < N; i++)
                {
                    if ((A[i] ^ X) == num)
                        count_xor++;
                }
            }
            int total = count_orig + count_xor;
            if (total > max_count)
            {
                max_count = total;
                min_ops = count_xor;
            }
            else if (total == max_count)
            {
                min_ops = min(min_ops, count_xor);
            }
        }
        cout << max_count << " " << min_ops << "\n";
    }
}