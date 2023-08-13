#!/usr/bin/env python3

import sys
import random


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default


def generate_pair(max_ai_bi):
    return (random.randint(0, max_ai_bi), random.randint(0, max_ai_bi))


random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n', 10**5))
unique_sums = int(cmdlinearg('unique_sums', 0))
max_ai_bi = int(cmdlinearg('max_ai_bi', 10**9))
c_is_a = int(cmdlinearg('c_is_a', 0))

print(n)
print('antal' if c_is_a else random.choice(('antal', 'storlek')))

l = []
used_pairs = set()
if unique_sums:
    used_sums = set()
    for i in range(n):
        a, b = generate_pair(max_ai_bi)
        while a + b in used_sums or (a,b) in used_pairs:
            a, b = generate_pair(max_ai_bi)
        used_sums.add(a + b)
        used_pairs.add((a,b))
        l.append((a, b))
else:
    for i in range(n // 2):
        a, b = generate_pair(max_ai_bi)
        while (a,b) in used_pairs or (b,a) in used_pairs:
            a, b = generate_pair(max_ai_bi)
        used_pairs.add((a,b))
        used_pairs.add((b,a))
        l.append((a, b))
        l.append((b, a))
    if n % 2:
        a, b = generate_pair(max_ai_bi)
        while (a,b) in used_pairs:
            a, b = generate_pair(max_ai_bi)
        l.append((a,b))
random.shuffle(l)
for a, b in l:
    print(a, b)
