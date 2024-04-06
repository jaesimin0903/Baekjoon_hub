#include <iostream>
#include <vector>
using namespace std;

int N, L;
int board[101][101];

bool checkRow(int row) {
    vector<bool> ramp(N, false); // 경사로가 이미 설치되었는지 여부
    for (int i = 1; i < N; i++) {
        int diff = board[row][i] - board[row][i-1];
        if (diff == 0) continue; // 같은 높이면 계속 진행
        if (abs(diff) > 1) return false; // 높이 차이가 1보다 크면 경사로 설치 불가
        if (diff == 1) { // 오르막 경사로
            for (int j = 1; j <= L; j++) {
                if (i-j < 0 || board[row][i-1] != board[row][i-j] || ramp[i-j]) return false;
                ramp[i-j] = true;
            }
        } else { // 내리막 경사로
            for (int j = 0; j < L; j++) {
                if (i+j >= N || board[row][i] != board[row][i+j] || ramp[i+j]) return false;
                ramp[i+j] = true;
            }
        }
    }
    return true;
}

bool checkColumn(int col) {
    vector<bool> ramp(N, false);
    for (int i = 1; i < N; i++) {
        int diff = board[i][col] - board[i-1][col];
        if (diff == 0) continue;
        if (abs(diff) > 1) return false;
        if (diff == 1) { // 오르막
            for (int j = 1; j <= L; j++) {
                if (i-j < 0 || board[i-1][col] != board[i-j][col] || ramp[i-j]) return false;
                ramp[i-j] = true;
            }
        } else { // 내리막
            for (int j = 0; j < L; j++) {
                if (i+j >= N || board[i][col] != board[i+j][col] || ramp[i+j]) return false;
                ramp[i+j] = true;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> L;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    int answer = 0;
    for (int i = 0; i < N; i++) {
        if (checkRow(i)) answer++;
        if (checkColumn(i)) answer++;
    }

    cout << answer;
    return 0;
}
