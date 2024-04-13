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
int answer = 0;

struct Fireball{
    int x,y,m,d,s;
};

// 파이어볼 생성하고 도착위치에 정보 저장

//모든 파이어볼이 위치했을 때 위치에 중봇하는 파이어볼 계산

// 중복되는 파이어볼 처리 후 나뉜 파이어볼을 움직임

// 남은 파이어볼 중복처리 후 다시 중복되는 파잉어볼 계싼

//더이상 중복이 안되면 끝

int N , M , K;
int board[51][51];
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,1,1,1,0,-1,-1,-1};
    vector<Fireball> arr_f;
map<pair<int,int>, vector<Fireball>> fire_map;
void pr(){
    for(int i =1;i<=N;i++){
        for(int j =1;j<=N;j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M >> K;
    
    fill(&board[0][0], &board[0][0] + 51*51, 0);
    for(int i =0;i<M;i++){
        Fireball f;
        int r,c,m,s,d;
        cin >> r >> c >> m >> s >> d;
        f.y = r;
        f.x = c;
        f.m = m;
        f.s = s;
        f.d = d;
        

        fire_map[{r,c}].push_back(f);
        arr_f.push_back(f);
        board[r][c]++;
    }

    while(K--){
        
        //움직이기
        // for(int i =0;i<arr_f.size();i++){
        //     if(!arr_f[i].live)continue;
        //     board[arr_f[i].y][arr_f[i].x]--;
        //     for(int j =0;j<arr_f[i].s;j++){
        //         arr_f[i].y += dy[arr_f[i].d];
        //         arr_f[i].x += dx[arr_f[i].d];
        //         if(arr_f[i].y == 0) arr_f[i].y=N;
        //         else if(arr_f[i].y == N+1) arr_f[i].y =1 ;
        //         if(arr_f[i].x == 0) arr_f[i].x=N;
        //         else if(arr_f[i].x == N+1) arr_f[i].x = 1;
        //     }
        //     board[arr_f[i].y][arr_f[i].x]++;
        // }

        map<pair<int,int>,vector<Fireball>> new_map;
        for(auto v : fire_map){
            auto [y,x] = v.first;
            for(auto fb : v.second){
                int ny = (y + dy[fb.d] * fb.s % N + N) % N;
                int nx = (x + dx[fb.d] * fb.s % N + N) % N;
                new_map[{ny,nx}].push_back(fb);
            }
        }
        fire_map.swap(new_map);

        //중복확인
        map<pair<int,int>, vector<Fireball>> new_map2;
        for(auto cell : fire_map){
            if(cell.second.size() < 2) {
                new_map2[cell.first] = cell.second;
            }
            else{
                int total_sum = 0;
                    int total_mass =0;
                    int total_speed= 0;
                    bool is_odd = false;
                    bool is_even = false;
                
                    for(int i =0;i<cell.second.size();i++){
                        total_sum++;
                        total_mass += cell.second[i].m;
                        total_speed += cell.second[i].s;
                        if(cell.second[i].d % 2 == 1) is_odd = true;
                        else is_even = true;
                    }
                    if(floor(total_mass / 5) != 0){
                        int avg_mass = floor(total_mass /5);
                        int avg_speed = floor(total_speed / total_sum);
                        int dirr;
                        if(is_even && is_odd) dirr = 1;
                        else dirr = 0;
                        for(int k = 0;k<4;k++){
                            Fireball plus;
                            plus.y = cell.first.first;
                            plus.x = cell.first.second;
                            plus.m = avg_mass;
                            plus.s = avg_speed;
                            plus.d = dirr;
                            dirr+=2;
                            new_map2[{cell.first.first,cell.first.second}].push_back(plus);
                        }
                    }

            }
        }
        fire_map.swap(new_map2);

        // for(int i =1;i<=N;i++){
        //     for(int j =1;j<=N;j++){
        //         if(board[i][j] >= 2){
                    int total_sum = 0;
                    int total_mass =0;
                    int total_speed= 0;
                    bool is_odd = false;
                    bool is_even = false;
        //             //중복되는 파이어볼 합치기
        //             for(int k = 0;k<arr_f.size();k++){
        //                 if(!arr_f[k].live)continue;
        //                 if(arr_f[k].y != i || arr_f[k].x != j)continue;
        //                 total_sum++;
        //                 total_mass+=arr_f[k].m;
        //                 total_speed+=arr_f[k].s;
        //                 if(arr_f[k].d % 2 == 1) is_odd = true;
        //                 else is_even = true;
        //                 arr_f[k].live = false;
        //                 board[i][j]--;
        //             }
        //             //질량이 0 이면 패스하고 아니면 분기되는 파이어볼 만들기
                    
        //         }
        //     }
        // }
        //pr();
    }

    for(auto v : fire_map){
        for(auto fb : v.second){
            answer += fb.m;
        }
    }
    cout << answer;

    return 0;
}