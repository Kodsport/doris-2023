#!/usr/bin/env python3

def lcm(a, b):
    p = a*b
    while b != 0:
        a, b = b, a % b

    return p // a

def solve(a, b, c, d):
    q = lcm(c, d)

    count = (b - a) // q

    b = b - count*q

    for i in range(a, b + 1):
        if i % q == 0:
            count += 1

    return count



a, b, c, d = map(int, input().split())
count = solve(a, b, c, d)

print(count)
