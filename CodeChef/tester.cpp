#include "tester.h"
#include <algorithm>
#include <numeric>
#include <random>

static std::mt19937 rng(std::random_device{}());

std::vector<int> createRandomArray(int n, int l, int r) {
    std::vector<int> per(n);
    std::uniform_int_distribution<int> dist(l, r);

    for (int i = 0; i < n; i++)
        per[i] = dist(rng);

    return per;
}

std::vector<int> createPermutation(int n) {
    std::vector<int> per(n);
    std::iota(per.begin(), per.end(), 1);
    std::shuffle(per.begin(), per.end(), rng);
    return per;
}
