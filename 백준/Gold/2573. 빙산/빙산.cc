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

int N, M;


int ice[301][301];
bool visited[301][301];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> ice[i][j];
        }
    }
    queue<pair<int, int>> q;
    int year = 0;
    while (1) {
        int many = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                
                if (visited[i][j])continue;
                if (ice[i][j] == 0)continue;
                many++;
                if (many >= 2) {
                    cout <<  year << "\n";
                    
                    return 0;
                }
                q.push(make_pair(i, j));
                visited[i][j] = true;
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();


                    for (int k = 0; k < 4; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];

                        if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
                        if (ice[ny][nx] == 0) {
                            if(ice[y][x] != 0 && !visited[ny][nx])ice[y][x] -= 1;
                            continue;
                        }
                        if (visited[ny][nx]) continue;
                        q.push(make_pair(ny, nx));
                        visited[ny][nx] = 1;
                    }
                }
            }
        }
        if (many == 0) {
            cout << 0;
            return 0;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                visited[i][j] = 0;
            }
        }
 /*       for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << ice[i][j] << " ";
            }
            cout << "\n";
        }*/
        many = 0;
        year++;

    }
}
