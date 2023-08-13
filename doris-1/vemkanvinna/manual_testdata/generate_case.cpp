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

namespace wrong {
vector<int> who_can_win(board_type board) {
    vector<pair<int, int>> not_filled_positions;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!board[i][j]) {
                not_filled_positions.push_back({i, j});
            }
        }
    }

    bool possible_winners[2]{};

    for (int i = 0; i < (1 << not_filled_positions.size()); ++i) {
        for (int j = 0; j < (int) not_filled_positions.size(); ++j) {
            board[not_filled_positions[j].first][not_filled_positions[j].second] = (1 << j) & i ? 1 : -1;
        }
        if (check(board) == 2 && num_xs(board) == 5) {
            possible_winners[0] = true;
        }
        if (check(board) == 1 && num_xs(board) == 5) {
            possible_winners[1] = true;
        }
    }

    vector<int> res;
    if (possible_winners[1])
        res.push_back(1);
    if (possible_winners[0])
        res.push_back(2);
    return res;
}
} // namespace wrong

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    board_type board{};
    vector<pair<int, int>> positions;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!board[i][j]) {
                positions.push_back({i, j});
            }
        }
    }
    srand(time(0));
    do {
        for (auto [r, c]: positions)
            board[r][c] = 0;
        int turn = positions.size() % 2 == 0 ? 2 : 1;
        for (int i = 0; i < positions.size() && !check(board); ++i) {
            auto [r, c] = positions[i];
            board[r][c] = turn;
            turn ^= 3;
            auto wrong_sol = wrong::who_can_win(board);
            auto corr_sol = who_can_win(board);
            if (corr_sol != wrong_sol && !((rand()) % 1000)) {
                for (int j = 0; j < 3; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        switch (board[j][k]) {
                            case 0:
                                std::cout << "_ ";
                                break;
                            case 1:
                                std::cout << "X ";
                                break;
                            case 2:
                                std::cout << "O ";
                                break;
                            default:
                                break;
                        }
                    }
                    std::cout << '\n';
                }
                std::cout << endl;
                return 0;
            } else {
            }
        }
    } while (std::next_permutation(std::begin(positions), std::end(positions)));
}