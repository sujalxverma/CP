#include <iostream>
#include <vector>

#define gcd(a, b) ([](int x, int y) { while (y != 0) { int t = y; y = x % y; x = t; } return x; })(a, b)

std::vector<std::vector<int>> pairsCoprime(1001);

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> indexMap(1001, 0);
    int maxElement = 0;
    // store the max index of the numbers where they are present.
    for (int i = 0; i < n; i++)
    {
        int val;
        std::cin >> val;
        maxElement = std::max(maxElement, val);
        indexMap[val] = i + 1;
    }

    int result = 0;
    for (int i = 1; i <= maxElement; ++i)
    {
        if (indexMap[i] == 0)
            continue;
        for (int j : pairsCoprime[i])
        {
            if (indexMap[j] == 0)
                continue;
            result = std::max(result, indexMap[i] + indexMap[j]);
        }
    }

    if (result == 0)
        std::cout << -1 << '\n';
    else
        std::cout << result << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // Precompute all the pairs of coprime from 1 to 1000.
    for (int i = 1; i <= 1000; ++i)
    {
        for (int j = 1; j <= 1000; ++j)
        {
            if (gcd(i, j) == 1)
            {
                pairsCoprime[i].push_back(j);
            }
        }
    }

    long long t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
