#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <deque>
#include<queue>
#include<string>
#include<stack>
#include <tuple>
using namespace std;

int N, M, K;


int land[201][201];

int visited[201][201][31];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int kx[8] = { -2,-2,-1,-1,1,1,2,2 };
int ky[8] = { 1,-1,2,-2,2,-2,1,-1 };


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K;
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> land[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 30; k++) {
                visited[i][j][k] = -1;
            }
        }
    }
    queue<tuple<int,int,int>> q;
    
   
    q.push({ 0,0,K });
    visited[0][0][K] = 0;

    while (!q.empty()) {
        int y, x, knight;
        
        tie(y,x,knight) = q.front();
        //cout << y << " " << x << " "<< length << " "<<knight<<"\n";
        q.pop();

        
        
        // 말 여러번 한 후 원숭이 하면 원숭이 먼저하고 말 하는 경우 때문에 방문처리를 다르게 해야한다.

        if (knight != 0) {
            for (int i = 0; i < 8; i++) {
                int nx = x + kx[i];
                int ny = y + ky[i];
                if (land[ny][nx] == 1)continue;
                if (nx < 0 || ny < 0 || nx >= M || ny >= N)continue;
                if (visited[ny][nx][knight-1] != -1) continue;
                
                q.push({ ny,nx,knight - 1 });
                visited[ny][nx][knight-1] = visited[y][x][knight] + 1;
                
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (land[ny][nx] == 1)continue;
            if (nx < 0 || ny < 0 || nx >= M || ny >= N)continue;
            if (visited[ny][nx][knight] != -1)continue;

            q.push({ ny,nx,knight });
            visited[ny][nx][knight] = visited[y][x][knight]+1;
        }
    }
    int mn = 0x7f7f7f7f;
    for (int i = 0; i < 30; i++) {
        if (visited[N - 1][M - 1][i] == -1) continue;
        mn = min(mn, visited[N - 1][M - 1][i]);
    }

    if (mn == 0x7f7f7f7f) cout << -1;
    else cout << mn;
    return 0;
}
