#!/usr/bin/env python3


#somehow getting 70p, debugging rn

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


emptySquares=set()
for r in range(3):
    for c in range(3):
        if board[r][c] == 0:
            emptySquares.add((r,c))



def simulate_game(board,emptySquares):
    JohanVann=False
    AbdullahVann=False

    if emptySquares:

        #om antalet tomma rutor kvar är udda innebär det att det är Johans drag
        if len(emptySquares)%2 == 1:
            piece = 1
        else:
            piece = -1

        for x,y in emptySquares:
            emptySquares.remove((x,y))
            board[x][y] = piece
            winner = find_winner(board)


            if winner == "Johan":
                JohanVann = True

            elif winner == "Abdullah":
                AbdullahVann = True

            else:
                J,A = simulate_game(board,emptySquares)
                if J:
                    JohanVann = True
                if A:
                    AbdullahVann = True

            emptySquares.add((x,y))
            board[x][y] = 0  #reset the board back to how it looked before


    else:
        winner = find_winner(board)
        if winner=="Johan":
            JohanVann=True

        elif winner=="Abdullah":
            AbdullahVann=True



    return JohanVann,AbdullahVann


JohanVann, AbdullahVann = simulate_game(board,emptySquares)


if JohanVann and AbdullahVann:
    print("Abdullah och Johan kan vinna")
elif JohanVann:
    print("Johan kan vinna")
elif AbdullahVann:
    print("Abdullah kan vinna")
else:
    print("ingen kan vinna")
