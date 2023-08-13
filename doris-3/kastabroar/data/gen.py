#!/usr/bin/env python3

import sys
import random
from random import randint


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

n = int(cmdlinearg("maxn", 10**5))
m = int(cmdlinearg("maxm", 10**5))
mode = cmdlinearg("mode")


random.seed(int(cmdlinearg("seed", sys.argv[-1])))

# Stolen from https://github.com/cheran-senthil/PyRival/blob/master/pyrival/data_structures/DisjointSetUnion.py
class UF:
    def __init__(self, n):
        self.parent = list(range(n))

    def find(self, a):
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a:
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a

    def union(self, a, b):
        self.parent[self.find(b)] = self.find(a)

uf = UF(n)

edges = set()
edgecnt=0

def genrandom(cnt):
    for i in range(cnt):
        while True:
            a,b = randint(0, n-1), randint(0, n-1)
            if a==b:
                continue
            if a>b:
                a,b=b,a
            if (a,b) in edges:
                continue
            edges.add((a,b))
            break

def genacyclic(cnt):
    for i in range(cnt):
        while True:
            a,b = randint(0, n-1), randint(0, n-1)
            if a==b:
                continue
            if a>b:
                a,b=b,a
            if (a,b) in edges:
                continue
            if uf.find(a)==uf.find(b):
                continue
            uf.union(a,b)
            edges.add((a,b))
            break

if mode=="impossible":
    genrandom(n-randint(2,5))
elif mode=="random":
    genrandom(randint(n-1, m))
elif mode=="forest":
    genacyclic(n-randint(2,5))
elif mode=="tree":
    genacyclic(n-1)
elif mode=="cliques":
    s = int(n**0.5)
    snode = 0
    while len(edges) < m:
        k = randint(s//10, s)
        for i in range(snode, snode+k):
            for j in range(i+1, snode+k):
                edges.add((i,j))
        snode+=k
    while len(edges) > m:
        edges.pop()
    n = m
else:
    raise RuntimeError(f"Invalid mode {mode}")

print(n,len(edges))
for edge in edges:
    a,b=edge
    if randint(1,2)==1:
        a,b=b,a
    print(a+1,b+1)