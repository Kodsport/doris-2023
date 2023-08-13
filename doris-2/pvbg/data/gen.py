import sys
from random import seed, randint
import random
import re

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default


seed(int(cmdlinearg('seed', sys.argv[-1])))
maxN = int(cmdlinearg('maxN',1000000))
maxR = int(cmdlinearg('maxR',1000000000))
minR = int(cmdlinearg('minR',1))

N = int(cmdlinearg('N',random.randint(1,maxN)))


rows = []

for i in range(N):
    rows.append(random.randint(minR,maxR))


print(N)
print(" ".join(map(str,rows)))
