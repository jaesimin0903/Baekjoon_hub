#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <deque>
#include<queue>
#include<string>
#include<stack>
#include <tuple>
#include <cmath>
#include <map>
#include <unordered_set>
#include<cstring>
using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int room[51][51];
bool clean[51][51];
//북동남서 0123

int y, x, N,M, arrow;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    cin >> y >> x >> arrow;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
            
            clean[i][j] = 0;
        }
    }
    int answer = 0;
    while (1) {
        //cout << y << " " << x <<" "<< arrow << "\n";
        //처음 위치가 청소가 안되어있다.
        if (!clean[y][x]) {
            clean[y][x] = 1;
            answer++;
        }

        bool is_cleaned_around = true;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
            if (room[ny][nx] == 1)continue;
            if (!clean[ny][nx] && room[ny][nx] != 1) {
                is_cleaned_around = false;
            }
        }

        //주변이 청소가 되어있다.
        if (is_cleaned_around) {
            //현재 방향에서 뒤로
            int back = arrow+2;
            if (arrow + 2 > 3) {
                back = (arrow + 2) % 4;
            }
            int ny = y + dy[back];
            int nx = x + dx[back];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
                cout << answer;
                return 0;
            }
            if (room[ny][nx] == 1) {
                cout << answer;
                return 0;
            }
            else {
                y = ny;
                x = nx;
            }
        }
        else {//청소가 되지 않은 곳이 있다.
            //반시계 90도
            for (int i = 0; i < 3; i++) {
                if (arrow == 0) {
                    arrow = 3;
                }
                else {
                    arrow--;
                }
                //앞이 청소가 안되어있나?
                int ny = y + dy[arrow];
                int nx = x + dx[arrow];
                //갈수있나?
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (room[ny][nx] == 1)continue;
                if (clean[ny][nx] == 1)continue;
                //가자
                y = ny;
                x = nx;
                break;
            }
        }
    }

    return 0;
}

