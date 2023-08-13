#!/usr/bin/python3

class UnionFind:
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


n,m = map(int,input().split())

valid = []
invalid = []

UF = UnionFind(n)

for _ in range(m):
    x,y = map(int,input().split())
    
    x-=1
    y-=1

    if UF.find(x) == UF.find(y):
        invalid.append((x,y))
    else:
        valid.append((x,y))
        UF.union(x,y)


allGroups=set()
for i in range(n):
    allGroups.add(UF.find(i))


if len(invalid) >= len(allGroups)-1:
    print("Ja")
    print(len(allGroups)-1)

    allGroupsList = list(allGroups)
    for i in range(len(allGroups)-1):
        print(invalid[i][0]+1,      invalid[i][1]+1,
              allGroupsList[i]+1,   allGroupsList[i+1]+1)

else:
    print("Nej")
