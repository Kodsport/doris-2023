#!/usr/bin/python3

n,m = map(int,input().split())

#If the graph contains no cycles, then the graph must be connected if the number of edges are exactly n-1.
if m == n-1: 
    print("Ja") 
    print(0)
else:
    print("Nej")
