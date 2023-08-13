#!/usr/bin/env python3

n,q = map(int,input().split())

houses = [*map(int,input().split())]

friends = [*map(int,input().split())]

houses.sort()

prefixSum = [0]

for house in houses:
    prefixSum.append(prefixSum[-1] + house)

for friend in friends:
    print(prefixSum[friend])
