#include <cstring>
#include <iostream>

using namespace std;

void rotate(int board[3][3]) {
    int temp[3][3];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) temp[i][j] = board[2 - j][i];
    memcpy(board, temp, sizeof(temp));
}

int check_johan(int board[3][3]) {
    if (board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1) return 1;
    if (board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1) return 1;
    if (board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1) return 1;

    if (board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1) return 1;
    if (board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1) return 1;
    if (board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1) return 1;

    if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) return 1;
    if (board[2][0] == 1 && board[1][1] == 1 && board[0][2] == 1) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    int board[3][3]{};
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
                board[j][k] = -1;
            }
        }
    }
    int ans = check_johan(board);
    if (ans == 1) {
        cout << "Johan har vunnit\n";
    } else {
        cout << "ingen har vunnit\n";
    }
}
