#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include<stack>
#include<cmath>
using namespace std;

vector<int> res;
int w = 0;
int b = 0;

void print(vector<vector<int>>v) {
    for (auto& row : v) {
        for (auto& val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}
bool isPromising(int row, int col, int n, vector<vector<bool>> visited) {
    bool result = true;
    for (int r = row - 1, t = 1; r >= 0; r--, t++) {
        if ((col - t >= 0 && visited[r][col - t]) || (col + t < n && visited[r][col + t])) {
            return false;
        }
    }
    return result;
}

void dfs(int row, int col, int cnt, char type,int n, vector<vector<int>> v, vector<vector<bool>> visited) {
    //현재위치에서 대각 좌표들 비활성화
    // 00000
    // 00100
    if (col >= n) {
        row += 1;
        if (type == 'W') {
            col = row % 2 == 0 ? 0 : 1;
        }
        else {
            col = row % 2 == 0 ? 1 : 0;
        }
    }

    if (row == n) {
        if (type == 'W') {
            w = max(w, cnt);
        }
        else {
            b = max(b, cnt);
        }
        return;
    }

    if (v[row][col] == 1) {
        visited[row][col] = true;
        if (isPromising(row, col,n,visited)) {
            dfs(row, col + 2, cnt + 1, type,n,v,visited);
        }
        visited[row][col] = false;
    }
    dfs(row, col + 2, cnt, type, n, v, visited);

}



int main() {
    //주어진 맵에서 배치 가능한모든 곳에서 dfs
    //배치했을 경우 대각방향의 위치를 움직일 수 없게 dfs 에 맵 전달
    
    int n;
    cin >> n;
    int num;
    vector<vector<int>> v(n, vector<int>(n, 0));
    vector<vector<bool>>visited(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num;
            v[i][j] = num;
        }
    }
    //visited[0][0] = true;

    dfs(0, 0, 0, 'W', n, v, visited);
    dfs(0, 1, 0, 'B', n, v, visited);

    cout << w + b;
    return 0;
}

