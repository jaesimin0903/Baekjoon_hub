#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <deque>
#include<queue>
#include<string>
#include<stack>
using namespace std;

int N, M,T;

int L;
int paper[501][501] = { 0, };

bool visited[501][501] = { 0, };

int main() {


    cin >> N >> M;


    for (int i = 0; i < 501; i++) {
        for (int j = 0; j < 501; j++) {
            paper[i][j] = 0;
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;
            paper[i][j]  = num;
        }
    }

    queue<pair<int,int>> q;

    

    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };

    int max = 0;
    int many = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int ans = 0;
            if (!visited[i][j] && paper[i][j] == 1) {
                many++;
                q.push(make_pair(i, j));
                visited[i][j] = 1;
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    //if (visited[y][x]) continue;
                    ans++;
                 
                    for (int h = 0; h < 4; h++) {
                        int ny = y + dy[h];
                        int nx = x + dx[h];
                        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                        if (visited[ny][nx]) continue;
                        if (paper[ny][nx] == 0)continue;
                        visited[ny][nx] = 1;
                        q.push(make_pair(ny, nx));
                    }
                }
            }
            if (max < ans) max = ans;
        }
    }
    cout << many << "\n";
    cout << max;

    return 0;
}
