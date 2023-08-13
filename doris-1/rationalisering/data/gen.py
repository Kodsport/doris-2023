#!/usr/bin/env python3

import sys
import random


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default


def solve(c, f):
    a = 0
    for b in range(1, 10**6 + 1):
        while a / b < c - f - 1e-9:
            a += 1
        if c - f - 1e-9 < a / b < c + f + 1e-9:
            return (a, b)
    return (0, 1)


def num_significant_digits(f: str):
    copy = f.replace('.', '')
    while copy[0] == '0':
        copy = copy[1:]
    return len(copy)


def trim(f: str):
    while num_significant_digits(f) > 6 or f[-1] == '0':
        f = f[:len(f) - 1]
    return f


def generate(max_val, b_is_1000, dec_f_exp_by):
    c, f = random.randint(0, 10**10) / 10**9, random.randint(10**3, 10**10 / (10 ** dec_f_exp_by)) / 10**11
    if b_is_1000:
        c, f = random.randint(0, 100000) / 10000, random.randint(10**3, 10**4) / 10**11
    c, f = float(trim("%.10f" % c)), float(trim("%.10f" % f))
    a, b = solve(c, f)
    if b_is_1000 and b != 1000:
        return generate(max_val, b_is_1000, dec_f_exp_by)

    if a > max_val or b > max_val:
        return generate(max_val, b_is_1000, dec_f_exp_by)

    return (c, f)


def print_solution(p):
    c, f = p
    print(trim("%.10f" % c), trim("%.10f" % f))


max_val = int(cmdlinearg("max_val", 10**6))
b_is_1000 = int(cmdlinearg("b_is_1000", 0))
dec_f_exp_by = int(cmdlinearg("dec_f_exp_by", 0))
random.seed(int(cmdlinearg("seed", sys.argv[-1])))
print_solution(generate(max_val, b_is_1000, dec_f_exp_by))