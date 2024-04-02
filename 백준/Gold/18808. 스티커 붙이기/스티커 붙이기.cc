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

//좌상단 먼저 스티커를 붙이기
//어떻게해도 붙일수 없다면 90도 회전해서 붙이기
//어느 방향으로도 안된다면 버리기

int y, x, N,M, arrow;
int num;
int m[41][41];



int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    cin >> num;
    for (int i = 0; i < num; i++) {
        //sticker input
        int s_row, s_col;
        cin >> s_row >> s_col;

        vector<vector<int> > v;

        for (int j = 0; j < s_row; j++) {
            vector<int> col;
            for (int k = 0; k < s_col; k++) {
                int val;
                cin >> val;
                col.push_back(val);
            }
            v.push_back(col);
        }

        //sticker 붙이기
        int cnt_rot = 0;
        //4방향 다 돌았음에도 안되면 버리기
        bool check_sticker = false;

        while (cnt_rot != 4) {
            //cout << s_row << " " << s_col << "\n";
            //맵의 행렬보다 스티커의 행렬이 큰가?
            if (v.size() <= N && v[0].size() <= M) {
                //cout << "if" << "\n";
                //모든 맵에 붙일 수 있는 경우 찾기
                for (int j = 0; j + s_row <= N; j++) {
                    for (int k = 0; k + s_col <= M; k++) {
                        bool is_ok = true;

                        if (!check_sticker) {
                            //고정된 위치에서 찾는중
                            //cout << j << " " << k << "\n";
                            for (int row = 0; row < s_row; row++) {
                                for (int col = 0; col < s_col; col++) {
                                    //cout << m[j + row][k + col] << " " << v[row][col] << "\n";
                                    if (m[j + row][k + col] == 1 && v[row][col] == 1) is_ok = false;
                                }
                            }
                            //붙일수 있다면 붙이기
                            if (is_ok && !check_sticker) {
                                //cout << "스티커부착" << "\n";
                                for (int cur_row = j; cur_row < j + s_row; cur_row++) {
                                    for (int cur_col = k; cur_col < k + s_col; cur_col++) {
                                        if(m[cur_row][cur_col] != 1)
                                            m[cur_row][cur_col] = v[cur_row - j][cur_col - k];
                                    }
                                }
                                check_sticker = true;
                            }
                        }
                    }
                }
            }
            //for (int j = 0; j < N; j++) {
            //    for (int k = 0; k < M; k++) {
            //        cout << m[j][k] << " ";
            //    }
            //    cout << "\n";
            //}
            //cout << "\n";

            //붙있수없다면 돌리기
            if (!check_sticker) {
                vector<vector<int>> tmp(v[0].size(), vector<int>(v.size(), 0));
                if (cnt_rot == 0 ) {
                    for (int j = 0; j < v[0].size(); j++) {
                        for (int k = 0; k < v.size(); k++) {
                            tmp[j][k] = v[v.size()-1-k][j];
                            //cout << tmp[j][k]<< " ";
                        }
                        //cout << "\n";
                    }
                }
                else if (cnt_rot == 1) {
                    for (int j = 0;j<v[0].size();j++) {
                        for (int k = 0; k < v.size(); k++) {
                            tmp[j][k] = v[v.size()-1-k][j];
                            //cout << tmp[j][k] << " ";
                        }
                        //cout << "\n";
                    }
                }
                else if(cnt_rot == 2){
                    for (int j = 0; j < v[0].size(); j++) {
                        for (int k = 0; k < v.size(); k++) {
                            tmp[j][k] = v[v.size() - 1 - k][j];
                            //cout << tmp[j][k] << " ";
                        }
                        //cout << "\n";
                   
                    }
                }
                
                v = tmp;
                s_row = v.size();
                s_col = v[0].size();
                cnt_rot++;
            }
            else {
                break;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (m[i][j] == 1) answer++;
        }
    }
    cout << answer;
    return 0;
}

