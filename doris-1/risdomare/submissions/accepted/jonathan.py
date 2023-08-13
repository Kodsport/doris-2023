#!/usr/bin/env python3

n, important = int(input()), input() != "antal"
print(max((a+s, (a, s)[important], i+1) for a, s, i in (list(map(int, input().split()))+[i] for i in range(n)))[2])
