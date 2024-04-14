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
int max_size = 0;
bool visited[101][101];

int N , Q, L;

int dy[4] = {0,1,0,-1};
int dx[4] = {-1,0,1,0};

struct Info{
    int y,x,fav_stu, empty;
};

map<int, vector<int>> students;
int cnt = 1;

int board[401][401];

void arr_print(){
    cout << "\n";
    for(int i =0;i<N;i++){
        for(int j =0;j<N;j++){
            cout << board[i][j] << " ";
        }
        cout <<"\n";
    }
    cout << "\n";
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i =0;i<N*N;i++){
        int s;
        cin >> s;
        for(int j= 0;j<4;j++){
            int num;
            cin >> num;
            students[s].push_back(num);
        }

        vector<Info> v;
        for(int row =0;row<N;row++){
            for(int col = 0;col<N;col++){
                int hope = 0;
                int e = 4;
                if(board[row][col]!=0)continue;
                for(int k = 0;k<4;k++){
                    int ny = row+dy[k];
                    int nx = col + dx[k];

                    if(ny<0 || nx < 0 || ny >= N|| nx >= N){
                        e--;
                    }
                    else if(find(students[s].begin(), students[s].end(), board[ny][nx]) != students[s].end()){
                        hope++;
                        e--;
                    }else{
                        if(board[ny][nx] != 0) e--;
                    }
                }
                Info inf;
                    inf.y = row; inf.x = col;inf.fav_stu = hope; inf.empty = e;
                    v.push_back(inf);
            }
        }

        //info vector sort
        sort(v.begin(), v.end(), [] (const Info &a, const Info &b) {
            if (a.fav_stu != b.fav_stu) 
                return a.fav_stu > b.fav_stu; // 관심 있는 사람 수가 많은 순
            if (a.empty != b.empty)
                return a.empty > b.empty;    // 빈자리 수가 많은 순
            if (a.y != b.y)
                return a.y < b.y;           // 행 번호가 작은 순
            return a.x < b.x;               // 열 번호가 작은 순
        });

        //cout << "\n";
        // for(int i =0;i<v.size();i++){
        //     cout << v[i].y << " " << v[i].x << " " << v[i].fav_stu << " " << v[i].empty << "\n";
        // }
        board[v[0].y][v[0].x] = s;
        //arr_print();
        v.clear();
    }

    //1.빈자리가 가장 많은 곳
    //2.좋아하는 학생이 앉은 자리가 옆에 있는 곳이 많은 곳
    //3.2번이 많다면 제일위 , 제일 옆 순으로 앉기

    for(int i =0;i<N;i++){
        for(int j =0;j<N;j++){
            int fav_person = 0;
            for(int k = 0;k<4;k++){
                int ny = i + dy[k];
                int nx = j + dx[k];

                if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                if(find(students[board[i][j]].begin(), students[board[i][j]].end(), board[ny][nx]) != students[board[i][j]].end()) fav_person++;
            }
            if(fav_person == 1) answer +=1;
            else if(fav_person == 2) answer += 10;
            else if(fav_person == 3) answer += 100;
            else if(fav_person == 4) answer +=1000;
        }
    }
    cout << answer;
    return 0;
}