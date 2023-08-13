#!/usr/bin/env python3

n = int(input())

i = 1

prevprev = prev = curr = 0

while i < n+1:
  if i == 1:
    curr = 1
  elif i == 2:
    curr = 2
  else:
    curr = (prevprev + prev + 1) % (10**9+7)

  prevprev = prev
  prev = curr
  i += 1

print(curr)