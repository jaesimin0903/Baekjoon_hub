#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <deque>
using namespace std;
int N;
int board[21][21];
int answer = 0;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void arr_print(int a[][21]){
    for(int i =0;i<N;i++){
        for(int j= 0;j<N;j++){
            cout << a[i][j] << " ";
        }
        //cout << "\n";
    }
    //cout << "\n";
}

void arr_copy(int a[][21], int b[][21]){
    for(int i =0;i<N;i++){
        for(int j= 0;j<N;j++){
            a[i][j] = b[i][j];
        }
    }
}

void dfs(int b[][21], int cnt){
int tmp[21][21];

    //cnt == 5 end
    if(cnt==5){
        int ans = 0;
        for(int i =0;i<N;i++){
            for(int j =0;j<N;j++){
                if(b[i][j]>ans) ans = b[i][j];
            }
        }
        //cout << "\n";
        if(answer < ans){
            //cout << "-----------------max\n";
            //arr_print(b);
            //cout << "\n";
        }
        answer = max(answer, ans);
        return;
    }

    //tmp 에 복사
    for(int i =0;i<N;i++){
        for(int j= 0;j<N;j++){
            tmp[i][j] = b[i][j];
        }
    }

    //up right down left  
        //위
        for(int j = 0;j<N;j++){
            deque<int> q;

            int part = false;
            //숫자가 같으면 더해서 큐에 삽입 아니면 바로 삽입
            for(int k = 0;k<N;k++){
                if(!q.empty() && tmp[k][j] != 0){
                    if(q.back() != tmp[k][j]){
                        q.push_back(tmp[k][j]);
                        part = true;
                    }else if(q.back()==tmp[k][j] && !part){
                        q.push_back(tmp[k][j]);
                        part = true;
                    }
                    else if(q.back() == tmp[k][j] && part){
                        int qfront = q.back() + tmp[k][j];
                        q.pop_back();
                        q.push_back(qfront);
                        part = false;
                    }
                    tmp[k][j] = 0;
                }else if(q.empty() && tmp[k][j]!=0){
                    part = true;
                    q.push_back(tmp[k][j]);
                    tmp[k][j] = 0;
                }
            }
            int t = 0;
            //큐를 순회하며 다시 보드에 저장
            while(!q.empty()){
                tmp[t][j] = q.front();
                q.pop_front();
                t++;
            }
            
        }
        // cout << " up " <<cnt<<" ";
        // arr_print(tmp);
        dfs(tmp, cnt+1);
            for(int i =0;i<N;i++){
                for(int j= 0;j<N;j++){
                    tmp[i][j] = b[i][j];
                }
            }
        //right
        for(int j = 0;j<N;j++){
            deque<int> q;
            int part = false;
            for(int k = N-1;k>=0;k--){
                if(!q.empty() && tmp[j][k] != 0){
                    if(q.back() != tmp[j][k]){
                        q.push_back(tmp[j][k]);
                        part = true;
                    }else if(q.back()==tmp[j][k] && !part){
                        q.push_back(tmp[j][k]);
                        part = true;
                    }
                    else if(q.back() == tmp[j][k] && part){
                        int qfront = q.back() + tmp[j][k];
                        q.pop_back();
                        q.push_back(qfront);
                        part = false;
                    }
                    tmp[j][k] = 0;
                }else if(q.empty() && tmp[j][k]!=0){
                    part = true;
                    q.push_back(tmp[j][k]);
                    tmp[j][k] = 0;
                }
            }
            int t = N-1;
            //큐를 순회하며 다시 보드에 저장
            while(!q.empty()){
                tmp[j][t] = q.front();
                q.pop_front();
                t--;
            }
            
        }
        // cout << " right " <<cnt<<" ";
        // arr_print(tmp);
        dfs(tmp, cnt+1);
            for(int i =0;i<N;i++){
                for(int j= 0;j<N;j++){
                    tmp[i][j] = b[i][j];
                }
            }
        //down
        for(int j = 0;j<N;j++){
            deque<int> q;
            int part = false;
            for(int k = N-1;k>=0;k--){
                if(!q.empty() && tmp[k][j] != 0){
                    if(q.back() != tmp[k][j]){
                        q.push_back(tmp[k][j]);
                        part = true;
                    }else if(q.back()==tmp[k][j] && !part){
                        q.push_back(tmp[k][j]);
                        part = true;
                    }
                    else if(q.back() == tmp[k][j] && part){
                        int qfront = q.back() + tmp[k][j];
                        q.pop_back();
                        q.push_back(qfront);
                        part = false;
                    }
                    tmp[k][j] = 0;
                }else if(q.empty() && tmp[k][j]!=0){
                    part = true;
                    q.push_back(tmp[k][j]);
                    tmp[k][j] = 0;
                }
            }
            int t = N-1;
            //큐를 순회하며 다시 보드에 저장
            while(!q.empty()){
                //cout << q.front() << " - ";
                tmp[t][j] = q.front();
                q.pop_front();
                t--;
            }
        }
        // cout << " down " <<cnt<<" ";
        // arr_print(tmp);
        dfs(tmp, cnt+1);
            //arr_copy(tmp,b);
            for(int i =0;i<N;i++){
                for(int j= 0;j<N;j++){
                    tmp[i][j] = b[i][j];
                }
            }

        //left
        for(int j = 0;j<N;j++){
            deque<int> q;
            int part = false;
            //숫자가 같으면 더해서 큐에 삽입 아니면 바로 삽입
            for(int k = 0;k<N;k++){
                if(!q.empty() && tmp[j][k] != 0){
                    if(q.back() != tmp[j][k]){
                        q.push_back(tmp[j][k]);
                        part = true;
                    }else if(q.back()==tmp[j][k] && !part){
                        q.push_back(tmp[j][k]);
                        part = true;
                    }
                    else if(q.back() == tmp[j][k] && part){
                        int qfront = q.back() + tmp[j][k];
                        q.pop_back();
                        q.push_back(qfront);
                        part = false;
                    }
                    tmp[j][k] = 0;
                }else if(q.empty() && tmp[j][k]!=0){
                    part = true;
                    q.push_back(tmp[j][k]);
                    tmp[j][k] = 0;
                }
            }
            int t = 0;
            //큐를 순회하며 다시 보드에 저장
            while(!q.empty()){
                tmp[j][t] = q.front();
                q.pop_front();
                t++;
            }
        }
        // cout << " left " <<cnt<<" ";
        // arr_print(tmp);
        dfs(tmp, cnt+1);
            for(int i =0;i<N;i++){
                for(int j= 0;j<N;j++){
                    tmp[i][j] = b[i][j];
                }
            }
    
} 

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin >> board[i][j];
        }
    }

    dfs(board,0);

    cout << answer;

    return 0;
}