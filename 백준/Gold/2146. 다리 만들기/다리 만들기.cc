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


int land[101][101];
int land_idx[101][101];
bool visited[101][101];
bool visited_idx[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> ans;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> land[i][j];
        }
    }

    //2차원 배열을 순회하면서 땅이 몇개인지 파악하고 각 행렬의 1이 속하는 땅의 번호를 기입
    int idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited_idx[i][j])continue;
            if (land[i][j] != 1)continue;
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            visited_idx[i][j] = true;
            idx++;
            land_idx[i][j] = idx;

            while (!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;

                q.pop();

                for (int k = 0; k < 4; k++) {
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
                    if (visited_idx[ny][nx])continue;
                    if (land[ny][nx] == 0)continue;
                    q.push(make_pair(ny, nx));
                    visited_idx[ny][nx] = true;
                    land_idx[ny][nx] = idx;
                }
            }
        }
    }

    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << land_idx[i][j] << " ";
        }
        cout << "\n";
    }*/

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j])continue;
            if (land[i][j] != 1)continue;

            queue<pair<int, int>> q;
            //주변에 0이 있는 1인 시작점 찾아서 큐에 넣기
            bool check = false;
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
                if (land[ny][nx] == 0) {
                    if (land_idx[ny][nx] != land_idx[i][j])
                    {
                        check = true;
                    }
                }
                else {
                    continue;
                }
            }

            

            if (check) {
                q.push(make_pair(i, j));
                visited[i][j] = true;
            } 

            while (!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;

                q.pop();

                bool check = false;
                for (int k = 0; k < 4; k++) {
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
                    if (visited[ny][nx]) continue;
                    if (land[ny][nx] == 0) {
                        if (land_idx[ny][nx] != land_idx[i][j])
                        {
                            q.push(make_pair(ny, nx));
                            visited[ny][nx] = true;
                        }
                    }else if (land[ny][nx] == 1) {
                        if (land_idx[ny][nx] != land_idx[i][j]) {
                            ans.push_back(abs(ny - i) - 1 + abs(nx - j));
                            break;
                        }
                    }
                    
                }
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if(land[i][j] == 0)visited[i][j] = 0;
                }
            }
            
        }
    }

    cout << *min_element(ans.begin(), ans.end());
}
