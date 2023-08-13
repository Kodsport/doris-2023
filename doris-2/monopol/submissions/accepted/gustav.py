#!/usr/bin/env python3

n = int(input())
a = list(map(int, input().split()))

p = 0
for i in range(1, 7):
    for j in range(1, 7):
        if (i+j) in a:
            p += 1

print(p/36)
