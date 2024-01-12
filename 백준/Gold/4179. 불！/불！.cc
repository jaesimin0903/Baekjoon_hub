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
vector<int> ans;
bool visited[1001][1001] = { 0, };
int dis[1001][1001] = { 0, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {


    cin >> N >> M;


    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            //maze[i][j] = 0;
            dis[i][j] = -1;
        }
    }

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        maze.push_back(str);
    }

    int minn = 1000001;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ( maze[i][j] == 'F') {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                dis[i][j] = 0;
                visited[i][j] = 1;
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    //cout << y << " " << x << " "<< dis[y][x]<<"\n";
                    q.pop();

                    for (int h = 0; h < 4; h++) {
                        int ny = y + dy[h];
                        int nx = x + dx[h];

                        if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
                            continue;
                        }
                        if (maze[ny][nx] == '#')continue;
                        if (visited[ny][nx]) continue;

                        if (dis[ny][nx] != -1)dis[ny][nx] = min(dis[ny][nx], dis[y][x] + 1);
                        else dis[ny][nx] = dis[y][x] + 1;
                        visited[ny][nx] = 1;

                        q.push(make_pair(ny, nx));
                    }
                }
                for (int k = 0; k < 1001; k++) {
                    fill(visited[k], visited[k] + 1001, 0);
                }
            }
            
        }
    }

    //for (int i = 0; i < N; i++) {
    //    for (int j = 0; j < M; j++) {
    //        cout << dis[i][j] << " ";
    //    }
    //    cout << "\n";
    //}

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            
            if (maze[i][j] == 'J') {
                queue<pair<int, int>> q;

                q.push(make_pair(i, j));
                dis[i][j] = 0;
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    //cout << y << " " << x << " "<< dis[y][x]<<"\n";
                    q.pop();

                    for (int h = 0; h < 4; h++) {
                        int ny = y + dy[h];
                        int nx = x + dx[h];

                        if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
                            ans.push_back(dis[y][x] + 1);
                            continue;
                        }
                        if (maze[ny][nx] == '#')continue;
                        
                        if (dis[ny][nx] != -1 &&dis[ny][nx] <= dis[y][x] + 1) continue;


                        dis[ny][nx] = dis[y][x] + 1;
                        q.push(make_pair(ny, nx));
                    }
                }
            }
        }
    }




    if (ans.empty()) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    else {
        cout << *min_element(ans.begin(), ans.end());
    }
    

    return 0;
}
