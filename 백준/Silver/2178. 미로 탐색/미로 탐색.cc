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
//int maze[101][101] = { 0, };
vector<string> maze;
bool visited[501][501] = { 0, };
int dis[101][101] = { 0, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {


    cin >> N >> M;


    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            //maze[i][j] = 0;
            dis[i][j] = -1;
        }
    }

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        maze.push_back(str);
    }

    queue<pair<int,int>> q;

    



    int max = 0;
    int many = 0;
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 1; j++) {
            int ans = 0;
            if (dis[i][j]==-1 && maze[i][j] == '1') {
                //many++;
                q.push(make_pair(i, j));
                dis[i][j] = 1;
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    //cout << y << " " << x << " "<< dis[y][x]<<"\n";
                    q.pop();
     
                    for (int h = 0; h < 4; h++) {
                        int ny = y + dy[h];
                        int nx = x + dx[h];
                        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                        if (dis[ny][nx]>-1) continue;
                        if (maze[ny][nx] == '0')continue;
                        dis[ny][nx] = dis[y][x] +1;
                        q.push(make_pair(ny, nx));
                    }
                }
            }
        }
    }
    cout << dis[N - 1][M - 1];

    return 0;
}
