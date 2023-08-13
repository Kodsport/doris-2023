#!/usr/bin/env python3

import sys
import random


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default


def rot(b):
    return [
        [b[0][2], b[1][2], b[2][2]],
        [b[0][1], b[1][1], b[2][1]],
        [b[0][0], b[1][0], b[2][0]],
    ]


def diag_win(b):
    for _ in range(4):
        if abs(sum(e for e in (b[i][i] for i in range(3)))) == 3:
            return True
        b = rot(b)
    return False


def abdullah_won(b):
    for _ in range(4):
        if sum(b[0]) == -3 or sum(b[1]) == -3:
            return True
        if sum(e for e in (b[i][i] for i in range(3))) == -3:
            return True
        b = rot(b)
    return False


def is_over(b):
    for _ in range(4):
        if abs(sum(b[0])) == 3 or abs(sum(b[1])) == 3:
            return True
        if abs(sum(e for e in (b[i][i] for i in range(3)))) == 3:
            return True
        b = rot(b)

    is_full = True
    for i in b:
        for j in i:
            if j == 0:
                is_full = False
    return is_full


def play_random(b, turn):
    i, j = random.randint(0, 2), random.randint(0, 2)
    if b[i][j] != 0:
        return play_random(b, turn)
    else:
        ret = [col[:] for col in b]
        ret[i][j] = turn
        return ret


def generate_board(allow_diag, abdullah_may_win):
    b = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    turn = 1
    # max of several random numbers to skew the number of moves higher
    num_moves = max(random.randint(0, 9), random.randint(0, 9), 
                    random.randint(0, 9), random.randint(0, 9),
                    random.randint(0, 9), random.randint(0, 9))  
    while not is_over(b) and num_moves:
        num_moves -= 1
        b = play_random(b, turn)
        turn *= -1
    if (not allow_diag) and diag_win(b):
        return generate_board(allow_diag, abdullah_may_win)
    if (not abdullah_may_win) and abdullah_won(b):
        return generate_board(allow_diag, abdullah_may_win)
    return b


def print_board(b):
    for i in b:
        for j in i:
            if j == 0:
                print('_', end=' ')
            if j == 1:
                print('X', end=' ')
            if j == -1:
                print('O', end=' ')
        print()


assert (is_over([[0, 0, 0], [1, 1, 1], [-1, -1, 0]]))
assert (is_over([[1, 0, 0], [0, 1, 0], [0, 0, 1]]))
assert (is_over([[1, 1, 1], [0, 0, 0], [0, 0, 0]]))
assert (is_over([[0, 0, 0], [1, 1, 1], [0, 0, 0]]))

assert (diag_win([[1, 0, 0], [0, 1, 0], [0, 0, 1]]))
assert (diag_win([[0, 0, 1], [0, 1, 0], [1, 0, 0]]))
assert (diag_win([[-1, 0, 0], [0, -1, 0], [0, 0, -1]]))
assert (diag_win([[0, 0, -1], [0, -1, 0], [-1, 0, 0]]))

assert (abdullah_won([[-1, 0, 0], [0, -1, 0], [0, 0, -1]]))
assert (abdullah_won([[0, 0, -1], [0, -1, 0], [-1, 0, 0]]))


random.seed(int(cmdlinearg('seed', sys.argv[-1])))
allow_diag = not int(cmdlinearg('no_diag', 0))
abdullah_may_win = not int(cmdlinearg('abdullah_loses', 0))
print_board(generate_board(allow_diag, abdullah_may_win))
