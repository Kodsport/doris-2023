#!/usr/bin/env python3

def solve(packs, stores):
    diffs = []
    for store in stores:
        diff = 0
        for (k, v) in store.items():
            diff += packs[k] - v
        diffs.append(diff)

    return diffs


t, b = map(int, input().split())

tis = list(map(int, input().split()))

packs = dict()
for _ in range(t):
    name, v = input().split()
    packs[name] = int(v)

stores = []

for i in range(b):
    pack_sel = dict()
    for _ in range(tis[i]):
        name, v = input().split()
        pack_sel[name] = int(v)
    stores.append(pack_sel)

diffs = solve(packs, stores)

for diff in diffs:
    print(diff)
