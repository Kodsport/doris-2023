#include <algorithm>
#include <array>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    board_type board{};
    int x_count = 0, o_count = 0;
    for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
            char x;
            cin >> x;
            if (x == 'X') {
                ++x_count;
                board[j][k] = 1;
            } else if (x == 'O') {
                ++o_count;
                board[j][k] = 2;
            }
        }
    }

    vector<int> possible_winners = who_can_win(board);

    switch (possible_winners.size()) {
        case 0:
            std::cout << "ingen kan vinna\n";
            break;
        case 1:
            if (possible_winners[0] == 1) {
                std::cout << "Johan kan vinna\n";
            } else {
                std::cout << "Abdullah kan vinna\n";
            }
            break;
        case 2:
            std::cout << "Abdullah och Johan kan vinna\n";
            break;
        default:
            return -1;
            break;
    }
}