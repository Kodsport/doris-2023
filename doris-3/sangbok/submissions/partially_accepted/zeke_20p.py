#!/usr/bin/env python3

t, n = map(int, input().split())
s = map(int, input().split()).__next__()

sum = ((60 * t)//s) *s
print(sum)
