#!/usr/bin/env python3

# idea by William Kraft (ZekeWK)

def solve(c, f):
    a = 0
    for b in range(1, 10**6 + 1):
        while a / b < c - f:
            a += 1
        if c - f < a / b < c + f:
            return (a, b)
    return (0, 1)


c, f = map(float, input().split())
a, b = solve(c, f)

print(a)
print(b)
