#!/usr/bin/env python3

def solve(a, b, c, d):
    count = 0
    for i in range(a, b + 1):
        if i % c == 0 and i % d == 0:
            count += 1

    return count



a, b, c, d = map(int, input().split())
count = solve(a, b, c, d)

print(count)
