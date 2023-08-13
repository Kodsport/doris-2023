#!/usr/bin/env python3

import sys
import random


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default


def is_iterable(x):
    try:
        _ = iter(x)
    except BaseException:
        return False
    return True


def deep_copy_list(x):
    if is_iterable(x):
        return [deep_copy_list(i) for i in x]
    else:
        return x


def rot(b):
    return [
        [b[0][2], b[1][2], b[2][2]],
        [b[0][1], b[1][1], b[2][1]],
        [b[0][0], b[1][0], b[2][0]],
    ]


def is_filled_board(b):
    return sum(sum(abs(i) for i in j) for j in b) == 9


def is_won(b):
    for _ in range(4):
        if abs(sum(b[0])) == 3 or abs(sum(b[1])) == 3:
            return True
        if abs(sum(e for e in (b[i][i] for i in range(3)))) == 3:
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

    return is_filled_board(b)


def play_random(b, turn):
    i, j = random.randint(0, 2), random.randint(0, 2)
    if b[i][j] != 0:
        return play_random(b, turn)
    else:
        ret = deep_copy_list(b)
        ret[i][j] = turn
        return ret


def has_one_winner(b):
    if is_won(b):
        return False
    j = [[e if e else 1 for e in l] for l in b]
    a = [[e if e else -1 for e in l] for l in b]
    return is_won(j) + is_won(a) == 1


def generate_board(all_filled, one_winner):
    b = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    turn = 1
    not_over = []
    num_moves = max(random.randint(0, 9), random.randint(0, 9), 
                    random.randint(0, 9), random.randint(0, 9),
                    random.randint(0, 9), random.randint(0, 9))  
    while not is_over(b) and num_moves:
        num_moves -= 1
        not_over = deep_copy_list(b)
        b = play_random(b, turn)
        turn *= -1
    if all_filled and not is_filled_board(b):
        return generate_board(all_filled, one_winner)
    if one_winner and not has_one_winner(not_over):
        return generate_board(all_filled, one_winner)
    elif one_winner:
        return not_over
    if is_won(b):
        return generate_board(all_filled, one_winner)
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


l = [
    [1, -1, 1],
    [-1, 1, -1],
    [-1, 1, 0]
]


random.seed(int(cmdlinearg('seed', sys.argv[-1])))
all_filled = int(cmdlinearg('all_filled', 0))
one_winner = int(cmdlinearg('one_winner', 0))
print_board(generate_board(all_filled, one_winner))
