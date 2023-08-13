#!/usr/bin/env python3

def lcm(a, b):
    p = a*b
    while b != 0:
        a, b = b, a % b

    return p // a

def solve(a, b, c, d):
    q = lcm(c, d)

    return b // q - (a - 1) // q



a, b, c, d = map(int, input().split())
count = solve(a, b, c, d)

print(count)
