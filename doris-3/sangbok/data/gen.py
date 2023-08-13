#!/usr/bin/env python3

import sys
import random


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

def print_case(t, n, s):
    print(t, n)

    print(" ".join(s))

def distributed_random(max_s):
    a, b = random.randint(1, max_s), random.randint(1, max_s//60)

    return max(a // b, 1)
    


def generate(max_t, max_n, all_s_same):
    t, n = random.randint(1, max_t), random.randint(1, max_n)
    max_s = t * 60
    
    if all_s_same:
        s_all = distributed_random(max_s)
        s = [str(s_all) for _ in range(n)]
    else:
        s = [str(distributed_random(max_s)) for _ in range(n)]

    return (t, n, s)

max_t = int(cmdlinearg("max_t", 10**5))
max_n = int(cmdlinearg("max_n", 10**5))
all_s_same = int(cmdlinearg("all_s_same", 0))
random.seed(int(cmdlinearg("seed", sys.argv[-1])))
print_case(*generate(max_t, max_n, all_s_same))
