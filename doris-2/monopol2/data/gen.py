import sys
from random import seed, randint
import random


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default


seed(int(cmdlinearg('seed', sys.argv[-1])))
N = int(cmdlinearg('N'))
single = int(cmdlinearg('single', -1))

if N == 1:
    print(N)
    print(single)

else:
    houses = set()
    while len(houses) < N:
        houses.add(random.randint(2, 12))

    print(N)
    print(" ".join(map(str, sorted(houses))))
