#!/usr/bin/env python3

import sys
import random
import math


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

def print_case(a, b, c, d):
    print(a, b, c, d)


def distributed_random(max_range):
    a, b = random.randint(1, max_range-1), random.randint(1, math.isqrt(max_range) + 1)

    return max(a // b, 1)

def generate(max_b, max_range, d_is_2_c, ac_is_1):
    b = random.randint(2, max_b)
    max_range = min(max_range, b)
    if ac_is_1:
        a = 1
    else:
        a = random.randint(b - max_range, b - 1)

    if ac_is_1:
        c = 1
        d = distributed_random(max_range)
    elif d_is_2_c:
        c = distributed_random(max_range//2)
        d = 2*c
    else:
        c = distributed_random(max_range)
        d = distributed_random(max_range)

    return (a, b, c, d)



max_b = int(cmdlinearg("max_b", 10**18))
max_range = int(cmdlinearg("max_range", 10**18))
d_is_2_c = int(cmdlinearg("d_is_2_c", 0))
ac_is_1 = int(cmdlinearg("ac_is_1", 0))
random.seed(int(cmdlinearg("seed", sys.argv[-1])))
print_case(*generate(max_b, max_range, d_is_2_c, ac_is_1))
