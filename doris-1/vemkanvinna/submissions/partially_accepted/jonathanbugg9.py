#!/usr/bin/env python3

from itertools import permutations


def has_won(board, who):
    if sum(board[0]) == 3 * who:
        return True
    if sum(board[1]) == 3 * who:
        return True
    if sum(board[2]) == 3 * who:
        return True

    if sum(l[0] for l in board) == 3 * who:
        return True
    if sum(l[1] for l in board) == 3 * who:
        return True
    if sum(l[2] for l in board) == 3 * who:
        return True

    if sum(board[i][i] for i in range(3)) == 3 * who:
        return True
    if sum(board[i][2 - i] for i in range(3)) == 3 * who:
        return True
    return False


board = []
for _ in range(3):
    l = []
    inp = input()
    for s in inp.split():
        if s == 'X':
            l.append(1)
        elif s == 'O':
            l.append(-1)
        elif s == '_':
            l.append(0)
        else:
            exit(-1)
    board.append(l)

empty_squares = [(i, j) for i in range(3)
                 for j in range(3) if board[i][j] == 0]

johan_can_win, abdullah_can_win = False, False

for move_order in permutations(empty_squares):
    for i, j in empty_squares:
        board[i][j] = 0
    turn = 1 if len(empty_squares) % 2 else -1
    for i, j in move_order:
        if has_won(board, 1):
            johan_can_win = True
            break
        if has_won(board, -1):
            abdullah_can_win = True
            break

        # checking if someone has won before playing the move (bug)
        # wont find win for johan on last move

        board[i][j] = turn
        turn *= -1
    if johan_can_win and abdullah_can_win:
        break
if abdullah_can_win and johan_can_win:
    print("Abdullah och Johan kan vinna")
elif abdullah_can_win:
    print("Abdullah kan vinna")
elif johan_can_win:
    print("Johan kan vinna")
else:
    print("ingen kan vinna")
