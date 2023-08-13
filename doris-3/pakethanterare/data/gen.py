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

def print_case(t, b, tis, stores):
    print(t, b)
    print(" ".join(map(str, tis)))

    for store in stores:
        for (k, v) in store.items():
            print(k, v)

def random_name():
    str_len = random.randint(3, 10)
    return ''.join(random.choice("abcdefghijklmnopqrstuvwxyz") for x in range(str_len))

def generate(max_t, max_b, all_diff_1):
    b = random.randint(1, max_b)
    t = random.randint(1, min(max_t, 10**6// b))

    packs = dict()

    for _ in range(t):
        while (name := random_name()) in packs:
            pass

        v = random.randint(2, 10**3)

        packs[name] = v

    packs_list = list(packs)

    tis = []
    stores = [packs]

    for _ in range(b):
        ti = random.randint(1, t)
        tis.append(ti)

        pack_sel = { k : packs[k] for k in random.sample(packs_list, k=ti)}


        if all_diff_1:
            pack = random.choice(list(pack_sel))
            pack_sel[pack] = random.randint(1, packs[pack]- 1)
        else:
            for pack in pack_sel:
                if random.randint(0, 1):
                    pack_sel[pack] = random.randint(1, packs[pack])


        stores.append(pack_sel)

    return (t, b, tis, stores)


max_t = int(cmdlinearg("max_t", 10**6))
max_b = int(cmdlinearg("max_b", 10**3))
all_diff_1 = int(cmdlinearg("all_diff_1", 0))
random.seed(int(cmdlinearg("seed", sys.argv[-1])))
print_case(*generate(max_t, max_b, all_diff_1))
