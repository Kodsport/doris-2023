#!/usr/bin/env python3


from fractions import Fraction as frac


def solve(c, f):
    a, b = 0, 1
    lo, hi = c - f, c + f
    while True:
        if frac(a, b) < lo:
            a += 1
        elif frac(a, b) > hi:
            b += 1
        else:
            break
    return (a, b)


c, f = map(frac, input().split())
a, b = solve(c, f)
print(a)
print(b)
