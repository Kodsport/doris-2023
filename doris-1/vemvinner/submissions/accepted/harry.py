#!/usr/bin/env python3

def find_winner(board):
    for i in range(3):
        # checkar alla rader
        if sum(board[i]) == 3:
            return "Johan"
        if sum(board[i]) == -3:
            return "Abdullah"
        # checkar alla kolumner
        if sum(board[row][i] for row in range(3)) == 3:
            return "Johan"
        if sum(board[row][i] for row in range(3)) == -3:
            return "Abdullah"
    # checkar alla diagonaler
    if sum(board[i][i] for i in range(3)) == 3:
        return "Johan"
    if sum(board[i][i] for i in range(3)) == -3:
        return "Abdullah"
    if sum(board[i][2 - i] for i in range(3)) == 3:
        return "Johan"
    if sum(board[i][2 - i] for i in range(3)) == -3:
        return "Abdullah"
    return "ingen"


board = [[], [], []]
for r in range(3):
    row = list(input().split())
    for symbol in row:
        if symbol == "X":
            board[r].append(1)
        elif symbol == "O":
            board[r].append(-1)
        else:
            board[r].append(0)
vinnare = find_winner(board)
print(vinnare, "har vunnit")
