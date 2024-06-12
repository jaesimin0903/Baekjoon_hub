#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> direction[3] = {
    {1,0}, {0,1}, {-1,-1}
};

int arr[1010][1010];
int N;

bool check(int ny, int nx){
    return ny < 0 || nx < 0 || ny >= N || nx >= N;
}

vector<int> solution(int n) {
    vector<int> answer;
    N = n;
    fill(&arr[0][0], &arr[0][0] + 1010 * 1010, -1);
    
    int row = 0, col = 0;
    arr[row][col] = 1;
    
    int num = 2;
    int dir = 0;
    while(1){
        //해당 방향으로 갈 수 있는가?
        //있으면, 가기 row col 업데이트
        //없으면, 방향 전환
        //      방향전환이 2회 이상이면 종료
        int ny = row +direction[dir].first;
        int nx = col + direction[dir].second;
        if(check(ny,nx) || arr[ny][nx] != -1){
            dir++;
            dir %= 3;
            ny = row +direction[dir].first;
            nx = col + direction[dir].second;  
        }
        row = ny;
        col = nx;
        if(arr[ny][nx] == -1)
        {arr[ny][nx] = num;
        num++;}
        else{
            break;
        }
        
        
    }
    
    for(int i = 0;i<N;i++){
        for(int j =0;j<N;j++){
            if(arr[i][j] == -1) break;
            else answer.push_back(arr[i][j]);
        }
    }
    
    return answer;
}
