#!/usr/bin/env python3

from fractions import Fraction

MOD = 10**9+7


def simplify_fraction(f: Fraction):
    return Fraction(f.numerator % (MOD * 4), f.denominator)


def simplify(x):
    return (simplify_fraction(x[0]), simplify_fraction(x[1]))


def add(x1, x2):
    return simplify((x1[0] + x2[0], x1[1] + x2[1]))


def multiply(x1, x2):
    return simplify((x1[0] * x2[0] + 5 * x1[1] * x2[1], x1[0] * x2[1] + x1[1] * x2[0]))


def bin_exp(b, n):
    res = (Fraction(1), Fraction(0))
    while n:
        if n % 2:
            res = multiply(res, b)
        b = multiply(b, b)
        n >>= 1
    return res


def negate(x):
    return (-x[0], -x[1])


def phi_exp(n):
    return bin_exp((Fraction(1, 2), Fraction(1, 2)), n)


def psi_exp(n):
    return bin_exp((Fraction(1, 2), Fraction(-1, 2)), n)


def fib(n):
    return multiply((Fraction(0), Fraction(1, 5)), add(phi_exp(n), negate(psi_exp(n))))


def to_float(x):
    return float(x[0] + 5**0.5*x[1])


def lucas(n):
    return add(phi_exp(n), psi_exp(n))


def f(n):
    if n <= 2:
        return n
    minus_two = (Fraction(-2), Fraction(0))
    three = (Fraction(3), Fraction(0))
    one_half = (Fraction(1, 2), Fraction(0))

    return int(multiply(add(add(minus_two, multiply(three, fib(n))), lucas(n)), one_half)[0]) % MOD


n = int(input())
print(f(n))
