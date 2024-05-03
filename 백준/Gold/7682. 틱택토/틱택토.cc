#include <iostream>
#include <string>
using namespace std;

bool check_winner(const string& board, char player) {
    // 가로 승리 조건
    for (int i = 0; i <= 6; i += 3) {
        if (board[i] == player && board[i + 1] == player && board[i + 2] == player) {
            return true;
        }
    }

    // 세로 승리 조건
    for (int i = 0; i < 3; i++) {
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
            return true;
        }
    }

    // 대각선 승리 조건
    if (board[0] == player && board[4] == player && board[8] == player) {
        return true;
    }

    if (board[2] == player && board[4] == player && board[6] == player) {
        return true;
    }

    return false;
}

string validate_tic_tac_toe(const string& board) {
    int count_X = 0, count_O = 0;
    for (char c : board) {
        if (c == 'X') count_X++;
        else if (c == 'O') count_O++;
    }

    // X는 O보다 많을 수 없고, O는 X보다 한 번 이상 많을 수 없다
    if (count_X < count_O || count_X > count_O + 1) {
        return "invalid";
    }

    bool X_wins = check_winner(board, 'X');
    bool O_wins = check_winner(board, 'O');

    // 승리 조건에 따른 판별
    if (X_wins && O_wins) {
        return "invalid";
    } else if (X_wins && count_X == count_O + 1) {
        return "valid";
    } else if (O_wins && count_X == count_O) {
        return "valid";
    } else if (!X_wins && !O_wins && count_X + count_O == 9) {
        return "valid";
    }

    return "invalid";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string board;
    while (true) {
        cin >> board;
        if (board == "end") break;
        cout << validate_tic_tac_toe(board) << endl;
    }

    return 0;
}
