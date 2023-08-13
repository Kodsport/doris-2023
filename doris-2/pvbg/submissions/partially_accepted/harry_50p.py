#!/usr/bin/env python3

n = int(input())

rows = [*map(int,input().split())]

t = 1

while 1:
    
    for peashooters in rows:

        if t > peashooters:
            print(t)
            exit()
    
    t += 1
