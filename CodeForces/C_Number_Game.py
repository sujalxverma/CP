import sys
from collections import Counter
import bisect
from sortedcontainers import SortedList

input = lambda: sys.stdin.readline().strip()
def ints(): return list(map(int, input().split()))
def int1(): return int(input())

INF = int(1e18)

def f(a, k):
    s = SortedList(a)

    for i in range(1, k + 1):
        value = k - i + 1

        pos = s.bisect_right(value)
        if pos == 0:
            return 0  # Alice can't pick any number <= value

        s.pop(pos - 1)
        if s:
            min_val = s.pop(0)
            s.add(min_val + value)

    return 1  # Alice survives all k rounds

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()

    s, e = 1, n  # Use n instead of 1000 for realistic bounds
    ans = 0

    while s <= e:
        m = (s + e) // 2
        if f(a, m):
            ans = m
            s = m + 1
        else:
            e = m - 1

    print(ans)

if __name__ == "__main__":
    t = int1()
    for _ in range(t):
        solve()
