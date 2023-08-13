#!/usr/bin/env python3

def solve(a, b, c, d):
    q = d

    return b // q - (a - 1) // q



a, b, c, d = map(int, input().split())
count = solve(a, b, c, d)

print(count)
