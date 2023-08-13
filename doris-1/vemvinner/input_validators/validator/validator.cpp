#include "validator.h"
#include <cstring>

typedef long long ll;

void rotate(int board[3][3]) {
    int temp[3][3];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) temp[i][j] = board[2 - j][i];
    memcpy(board, temp, sizeof(temp));
}

int check(int board[3][3]) {
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        if (board[0][0] != 0 && board[0][0] == board[0][1] && board[0][1] == board[0][2]) ans = board[0][0];
        if (board[1][0] != 0 && board[1][0] == board[1][1] && board[1][1] == board[1][2]) ans = board[1][0];
        if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ans = board[0][0];
        rotate(board);
    }
    return ans;
}

int check_diag(int board[3][3]) {
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ans = board[0][0];
        rotate(board);
    }
    return ans;
}

void run() {
    int maxn = Arg("maxn", 100);
    int nodiag = Arg("no_diag", 0);
    int abdullah_loses = Arg("abdullah_loses", 0);
    auto allowed_chars = std::set{'O', 'X', '_', ' '};
    string sboard[] = {Line(), Line(), Line()};
    for (auto &l: sboard) {
        for (auto c: l) {
            if (!allowed_chars.count(c)) {
                die("disallowed character" + _describe(c));
            }
        }
    }
    int board[3][3]{};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            char c = sboard[i][2 * j];
            switch (c) {
                case 'X':
                    board[i][j] = 1;
                    break;
                case 'O':
                    board[i][j] = -1;
                    break;
                default:
                    break;
            }
        }
    }
    if (abdullah_loses && check(board) == -1) {
        die("abdullah won when hes not supposed to");
    }
    if (nodiag && check_diag(board) != 0) {
        die("diagonal win when no_diag=1");
    }
}