import sys
from random import seed, randint
import random
import itertools


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default


seed(int(cmdlinearg('seed', sys.argv[-1])))
maxQ = int(cmdlinearg('maxQ', 10**5))
maxN = int(cmdlinearg('maxN', 2*10**5))
maximal = int(cmdlinearg('maximal', 0))
spreadOut = int(cmdlinearg('spreadOut', 0))
allOrOne = int(cmdlinearg('allOrOne', 0))
N = int(cmdlinearg('N', random.randint(1, maxN)))
Q = int(cmdlinearg('Q', random.randint(1, maxQ)))

neighborhood = random.sample(range(1, 10**9 + 1), N)
friends = (random.choice((1, N)) if allOrOne else random.randint(1, N)
           for _ in range(Q))

if maximal:
    friends = (N for _ in range(Q)) 

if spreadOut:
    friends = random.sample(range(1, N+1), Q)

print(N, Q)
print(" ".join(map(str, neighborhood)))
print(" ".join(map(str, friends)))
