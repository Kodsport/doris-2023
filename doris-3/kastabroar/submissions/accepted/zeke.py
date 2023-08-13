#!/usr/bin/python3

import sys
sys.setrecursionlimit(10**9)

n, m = map(int, input().split())

edges = [[] for _ in range(n)]

for _ in range(m):
    i, j = map(lambda x: int(x) - 1, input().split())
    edges[i].append(j)
    edges[j].append(i)

seen = [False for _ in range(n)]
remove = set()

def dfs(i, p):
    if seen[i]:
        if (i, p) not in remove and (p, i) not in remove:
            remove.add((i, p))
        return

    seen[i] = True

    for j in edges[i]:
        if j == p:
            continue

        dfs(j, i)

comps = []

for i in range(n):
    if seen[i]:
        continue

    comps.append(i)
    dfs(i, None)

k = len(comps) - 1


if k > len(remove):
    print("Nej")
else:
    print("Ja")
    print(k)

    for (i, (u, v)) in zip(comps[1:], remove):
        print(u + 1, v + 1, 1, i + 1)
