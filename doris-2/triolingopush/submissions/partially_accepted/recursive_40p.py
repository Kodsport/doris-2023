#!/usr/bin/env python3

def solve(n):
    return n if n <= 2 else solve(n - 1) + solve(n - 2) + 1


print(solve(int(input())))
