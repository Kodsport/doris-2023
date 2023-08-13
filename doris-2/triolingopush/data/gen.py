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

nMax = int(cmdlinearg('maximum', 1000000000000000000))

nMin = int(cmdlinearg('minimum', 1))

N = int(cmdlinearg('N', random.randint(nMin,nMax)))

print(N)
