#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <deque>
#include <tuple>
#include <utility>
#include <map>
using namespace std;
double answer = 0;

int N , M , K;

int dy[4] = {0,1,0,-1};
int dx[4] = {-1,0,1,0};
double board[500][500];
int cnt = 1;

//태풍 이동경로 만들기

double sand_wind[5][5]={
    {0,0,0.02,0,0},
    {0,0.1,0.07,0.01,0},
    {0.05,0,0,0,0},
    {0,0.1,0.07,0.01,0},
    {0,0,0.02,0,0}
};

void rotate_sand_wind() {
    double temp[5][5]; // 임시 배열을 생성

    // 90도 회전을 위한 새로운 값 계산 및 임시 배열에 저장
    for(int i =0;i<5;i++){
        for(int j =0;j<5;j++){
            temp[i][j] = sand_wind[i][j];
        }
    }

    for(int i =0;i<5;i++){
        for(int j =0;j<5;j++){
            sand_wind[i][j] = temp[j][4-i];
        }
    }   
}

void arr_print(){
    for(int i =0;i<N;i++){
        for(int j =0;j<N;j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
//태풍 방향에 따른 모래 날리기 회전

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int tt =0;
    for(int i =0;i<N;i++){
        for(int j =0;j<N;j++){
            cin >> board[i][j];
            tt+=board[i][j];
        }
    }
    
    int start_y = N/2;
    int start_x = N/2;

    int t = 4;
    int c = 0;
    int flag= 0;
    int dir = 0;
    while(!(start_y == 0 && start_x == 0)){
        
        for(int i =0;i<cnt;i++){
            start_y += dy[dir];
            start_x += dx[dir];

            
            if(board[start_y][start_x] == 0){ 
                if(start_x == 0 && start_y == 0){
                break;
            }
                continue;}
            else{
                double target_sand = board[start_y][start_x];
                int t_x,t_y;
                int lost_sand = 0;
                for(int row = 0;row < 5;row++){
                    for(int col = 0;col < 5;col++){
                        int sand_to_move = floor(target_sand * sand_wind[row][col]);
                        if(start_x+col-2 < 0 || start_x+col-2 >= N || start_y + row -2 < 0 || start_y+row-2 >= N){
                            answer += floor(target_sand * sand_wind[row][col]);
                            //if(sand_wind[row][col] != 1)lost_sand += floor(target_sand * sand_wind[row][col]);
                            //continue;
                        }else{
                        // if(start_y == start_y+row-2 && start_x == start_x +col -2 ) {
                        //     board[start_y][start_x] = floor(target_sand * sand_wind[row][col]);  
                        //     //lost_sand += floor(target_sand * sand_wind[row][col]);
                        // }
                        // else if(sand_wind[row][col] == 1){
                        //     t_y = start_y + row -2, t_x = start_x + col -2;
                        // }
                        // else  {
                        //     lost_sand +=floor(target_sand * sand_wind[row][col]);
                        //     board[start_y + row - 2][start_x + col -2] += floor(target_sand * sand_wind[row][col]);}
                            board[start_y + row -2][start_x + col -2] += sand_to_move;
                        }
                        lost_sand += sand_to_move;
                    }
                }
                // board[start_y][start_x] = 0;
                // if(t_y >=0 && t_y < N && t_x >= 0 && t_x < N)board[t_y][t_x] += target_sand - lost_sand;
                // cout << "t-sand " << target_sand << " , l-sand " << lost_sand <<"\n";
                if(start_y + dy[dir] >= 0 && start_y + dy[dir] < N && start_x + dx[dir] >= 0 && start_x + dx[dir] < N) board[start_y + dy[dir]][start_x+dx[dir]] += target_sand- lost_sand;
                board[start_y][start_x] = 0;
            }
            if(start_x == 0 && start_y == 0){
                break;
            }
        }

    c++;
        //cnt 만큼 움직이면 방향전환
        if(c == 2){
            cnt++;
            c= 0;
        }
        //cout << c << " " << cnt << " " << dir<< "\n";
        dir++;
        dir%=4;
        rotate_sand_wind();
    }

    for(int i =0;i<N;i++){
        for(int j =0;j<N;j++){
            tt -= board[i][j];
        }
    }

    cout << tt;

    return 0;
}