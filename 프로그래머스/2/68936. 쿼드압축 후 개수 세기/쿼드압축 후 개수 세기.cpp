#include <string>
#include <vector>
#include <iostream>

using namespace std;

int zero = 0;
int one = 0;

void dq(vector<vector<int>> &arr, int row, int col, int size){
    //사이즈 만큼 이중 포문 돌려서 1로 혹은 0으로 아님 둘다 아닌 경우 판단
    //1 오어 0 -> 카운트하고 함수 종료
    // 아니면 분할
    
    int init = -1;
    bool is_divide = false;
    for(int i = row;i<row+size;i++){
        for(int j = col;j<col+size;j++){
            if(init == -1) init = arr[i][j];
            else{
                if(init != arr[i][j] && !is_divide){
                    //분할
                    //if(size/2 < 1)return;
                    is_divide = true;
                    dq(arr, row,col,size/2);
                    dq(arr,row+size/2,col,size/2);
                    dq(arr,row,col+size/2, size/2);
                    dq(arr,row+size/2, col+size/2, size/2);
                    break;
                }
            }
        }
    }
    if(is_divide) return;
    if(init == 0) zero++;
    else one++;
    return ;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int size = arr.size();
    //분할정복으로 문제 풀기
    int init = -1;
    bool is_divide = false;
    bool is_loopend = false;
    for(int i = 0;i<arr.size();i++){
        for(int j =0;j<arr.size();j++){
            if(init == -1){
                init = arr[i][j] ;
            }else{
                if(init != arr[i][j] && !is_divide){
                    //분할
                    is_divide = true;
                    dq(arr, 0,0,size/2);
                    dq(arr,0+size/2,0,size/2);
                    dq(arr,0,0+size/2, size/2);
                    dq(arr,0+size/2, 0+size/2, size/2);
                    break;
                }
            }
        }
    }
    if(!is_divide){
        if(init == 0) zero++;
        else one++;
    }

    
    answer.push_back(zero);
    answer.push_back(one);
    
    return answer;
}