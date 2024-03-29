#include <string>
#include <vector>
#include<queue>
#include<tuple>
#include<iostream>
using namespace std;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int m[102][102];
bool visited[102][102];

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    characterX*=2;
    characterY*=2;

    itemX*=2;
    itemY*=2;
    //지도그리기
    for(auto vec : rectangle){
        int x1,x2,y1,y2;
        x1 = vec[0]*2;
        x2 = vec[2]*2;
        y1 = vec[1]*2;
        y2 = vec[3]*2;
        for(int i =x1;i<=x2;i++){
            m[y1][i] = 1;
            m[y2][i] = 1;
        }
        
        for(int i = y1;i<=y2;i++){
            m[i][x1] = 1;
            m[i][x2] = 1;
        }
    }
    
    //bfs
    queue<tuple<int,int,int> > q;
    q.push({characterY, characterX,0});
    visited[characterY][characterX] = 1;
    while(!q.empty()){
        int y, x, move;
        tie(y,x,move) = q.front();
        q.pop();
        
        if(y==itemY && x==itemX){
            for(int i =0;i<40;i++){
        for(int j = 0;j<40;j++){
            //cout << visited[i][j] ;
        }
        //cout << "\n";
    }
            return move/2;
        }
        
        for(int i =0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny <0 || nx < 0) continue;
            if(m[ny][nx] != 1) continue;
            if(visited[ny][nx]) continue;
            //해당 점이 내부에 있나요?
            bool is_in_rec = false;
            for(auto vec : rectangle){
                int x1,x2,y1,y2;
                x1 = vec[0]*2;
                x2 = vec[2]*2;
                y1 = vec[1]*2;
                y2 = vec[3]*2;
                if((x1<nx && nx<x2)&&(y1 <ny && ny<y2)){
                    is_in_rec = true;
                }
            }   
            if(is_in_rec) continue;
            q.push({ny,nx,move+1});
            visited[ny][nx] = 1;
        }
    }
    
    
    
    return answer;
}