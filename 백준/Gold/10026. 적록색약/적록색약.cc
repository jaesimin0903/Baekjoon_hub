#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <deque>
#include<queue>
using namespace std;

int N, M;

int color = 0;
int non_color = 0;
int R = 0;
int G = 0;
int B = 0;
int RG = 0;
int main() {
    
    vector<string> rgb;
    vector<vector<bool>> visited(101, vector<bool>(101, false));

    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        rgb.push_back(str);
    }
    //up, down, right, left
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    queue<pair<int,int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char target;
            if (visited[i][j])continue;
            
            if (rgb[i][j] == 'R') {
                target = 'R';
                R++;
            }
            else if (rgb[i][j] == 'G') {
                target = 'G';
                G++;
            }
            else if (rgb[i][j] == 'B') {
                target = 'B';
                B++;
            }
            q.push(make_pair(i, j));
            while (!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;

                q.pop();

                if (visited[y][x]) {
                    continue;
                }

                visited[y][x] = true;

                for (int k = 0; k < 4; k++) {
                    if (y + dy[k] >= 0 && y + dy[k] < N && x + dx[k] >= 0 && x + dx[k] < N) {

                    }
                    else {
                        continue;
                    }

                    if (!visited[y+dy[k]][x+dx[k]] && rgb[y+dy[k]][x+dx[k]] == target) {
                        q.push(make_pair(y + dy[k], x + dx[k]));
                    }
                }
            }

        }
    }
    for (int i = 0; i < 101; i++) {
        fill(visited[i].begin(), visited[i].end(), false);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char target;
            if (visited[i][j])continue;
            
            if (rgb[i][j] == 'R' || rgb[i][j] == 'G') {
                RG++;
                q.push(make_pair(i, j));
            }
            
            while (!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                if (visited[y][x]) {
                    continue;
                }

                visited[y][x] = true;

                for (int k = 0; k < 4; k++) {
                    if (y + dy[k] >= 0 && y + dy[k] < N && x + dx[k] >= 0 && x + dx[k] < N) {

                    }
                    else {
                        continue;
                    }

                    if (!visited[y + dy[k]][x + dx[k]] && (rgb[y + dy[k]][x + dx[k]] == 'G' || rgb[y + dy[k]][x + dx[k]] == 'R') ) {
                        q.push(make_pair(y + dy[k], x + dx[k]));
                    }
                }
            }

        }
    }

    /*for (auto row : visited) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }*/

    color = R + G + B;
    non_color = RG + B;
    cout << color << " " << non_color;

    return 0;
}
