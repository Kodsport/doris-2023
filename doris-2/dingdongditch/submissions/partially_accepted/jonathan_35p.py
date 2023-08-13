#!/usr/bin/env python3

n, q = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

for lim in b:
    smallest = []
    for e in a:
        if len(smallest) < lim or e < smallest[-1]:
            smallest.append(e)
            for i in reversed(range(1, len(smallest))):
                if smallest[i] < smallest[i - 1]:
                    smallest[i], smallest[i - 1] = smallest[i - 1], smallest[i]
            if len(smallest) > lim:
                smallest.pop()

    # smallest = sorted(a)[0:lim]
    print(sum(smallest))