#include "validator.h"
#include <cstring>

typedef long long ll;

using board_type = array<array<int, 3>, 3>;

using board_type = array<array<int, 3>, 3>;

board_type rotate(board_type board) {
    board_type temp{};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) temp[i][j] = board[2 - j][i];
    return temp;
}

int check(board_type board) {
    if ((board[0][0] != 0) & (board[0][1] == board[0][0]) & (board[0][2] == board[0][0])) return board[0][0];
    if ((board[1][0] != 0) & (board[1][1] == board[1][0]) & (board[1][2] == board[1][0])) return board[1][0];
    if ((board[2][0] != 0) & (board[2][1] == board[2][0]) & (board[2][2] == board[2][0])) return board[2][0];
    if ((board[0][0] != 0) & (board[1][0] == board[0][0]) & (board[2][0] == board[0][0])) return board[0][0];
    if ((board[0][1] != 0) & (board[1][1] == board[0][1]) & (board[2][1] == board[0][1])) return board[0][1];
    if ((board[0][2] != 0) & (board[1][2] == board[0][2]) & (board[2][2] == board[0][2])) return board[0][2];
    if ((board[0][0] != 0) & (board[1][1] == board[0][0]) & (board[2][2] == board[0][0])) return board[0][0];
    if ((board[2][0] != 0) & (board[1][1] == board[2][0]) & (board[0][2] == board[2][0])) return board[2][0];
    return 0;
}

int num_xs(board_type const &board) {
    int res = 0;
    for (auto &row: board) {
        for (auto &element: row) {
            res += element == 1;
        }
    }
    return res;
}

vector<int> who_can_win(board_type board) {
    vector<pair<int, int>> not_filled_positions;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!board[i][j]) {
                not_filled_positions.push_back({i, j});
            }
        }
    }

    bool possible_winners[3]{};

    do {
        for (auto [r, c]: not_filled_positions)
            board[r][c] = 0;
        int turn = not_filled_positions.size() % 2 == 0 ? 2 : 1;
        for (int i = 0; i < not_filled_positions.size() && !check(board); ++i) {
            auto [r, c] = not_filled_positions[i];
            board[r][c] = turn;
            turn ^= 3;
        }
        possible_winners[check(board)] = true;
    } while (std::next_permutation(std::begin(not_filled_positions), std::end(not_filled_positions)));


    vector<int> res;
    for (int i = 1; i <= 2; ++i)
        if (possible_winners[i])
            res.push_back(i);
    return res;
}

bool abdullah_can_win(board_type board) {
    auto possible_winners = who_can_win(board);
    for (auto i: possible_winners) {
        if (i == 2) {
            return true;
        }
    }
    return false;
}

bool johan_can_win(board_type board) {
    auto possible_winners = who_can_win(board);
    for (auto i: possible_winners) {
        if (i == 1) {
            return true;
        }
    }
    return false;
}

bool is_filled(board_type board) {
    for (auto &i: board)
        for (auto j: i)
            if (!j)
                return false;
    return true;
}

void run() {
    int all_filled = Arg("all_filled", 0);
    int one_winner = Arg("one_winner", 0);

    auto allowed_chars = std::set{'O', 'X', '_', ' '};

    string sboard[] = {Line(), Line(), Line()};
    for (auto &l: sboard) {
        for (auto c: l) {
            if (!allowed_chars.count(c)) {
                die("disallowed character" + _describe(c));
            }
        }
    }
    board_type board{};
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

    if (check(board)) {
        die("noone can have won");
    }

    if (one_winner && johan_can_win(board) && abdullah_can_win(board)) {
        die("two winners when only one is allowed");
    }

    if (all_filled && !is_filled(board)) {
        die("board not filled when it's supposed to be");
    }
}