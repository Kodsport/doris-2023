#!/usr/bin/env python3

def solve(t, s):
    s_max = 60*t

    s.sort()
    sum = 0

    for e in s:
        sum += e

        if sum > s_max:
            sum -= e
            break

    return sum



t, n = map(int, input().split())
s = list(map(int, input().split()))
sum = solve(t, s)

print(sum)
