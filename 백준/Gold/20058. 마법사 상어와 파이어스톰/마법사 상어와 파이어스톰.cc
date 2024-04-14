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

int A[101][101];
int cnt = 1;

void arr_print(){
    for(int i =0;i<N;i++){
        for(int j =0;j<N;j++){
            cout << A[i][j]<<" ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void arr_printB(int B[][101]){
    cout << "BB\n";
    for(int i =0;i<N;i++){
        for(int j =0;j<N;j++){
            cout << B[i][j]<<" ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void rotate(int y, int x, int s){
    int max_idx = pow(2,s);
    int B[101][101];
    fill(&B[0][0], &B[0][0] + 101 * 101, 0);
    for(int i = y;i<y+max_idx;i++){
        for(int j = x ;j<x+max_idx;j++){
            B[i-y][j-x] = A[i][j];
        }
    }

    for(int i = y;i<y+max_idx;i++){
        for(int j = x ;j<x+max_idx;j++){
            A[i][j] = B[max_idx+x-1-j][i-y];
        }
    }

}

void bfs(){
    for(int i =0;i<N;i++){
        for(int j= 0;j<N;j++){
            if(A[i][j] ==0 ) continue;
            queue<pair<int,int>> q;
            q.push({i,j});
            visited[i][j] = 1;
            int d = 0;
            while(!q.empty()){
                int y,x;
                tie(y,x) = q.front();
                q.pop();
                d++;
                for(int k =0;k<4;k++){
                    int ny = y+ dy[k];
                    int nx = x + dx[k];

                    if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                    if(A[ny][nx] == 0 )continue;
                    if(visited[ny][nx])continue;
                    q.push({ny,nx});
                    visited[ny][nx] = 1;
                }
            }
            max_size = max(max_size, d);
        }
    }
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> Q;
    N = pow(2,N);
    for(int i =0;i<N;i++){
        for(int j= 0;j<N;j++){
            cin >> A[i][j];
        }
    }

    while(Q--){
        cin >> L;

        //rotate
        int m_i = pow(2,L);
        for(int i = 0;i<N;i+=m_i){
            for(int j =0;j<N;j+=m_i){
                //out << i << " " << j <<"\n";
                rotate(i,j,L);
            }
        }

        //firestorm
        int tmp[101][101];
        fill(&tmp[0][0], &tmp[0][0] + 101 * 101, 0);
        for(int i =0;i<N;i++){
            for(int j= 0;j<N;j++){
                if(A[i][j] == 0) continue;
                int cnt = 0;

                for(int k = 0;k<4;k++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if(!(ny < 0 || nx < 0 || ny >= N || nx >= N )){
                        if(A[ny][nx] != 0)cnt++;
                    }

                }
                tmp[i][j] = cnt;
            }
        }

        for(int i =0;i<N;i++){
            for(int j =0;j<N;j++){
                if(tmp[i][j] < 3 && A[i][j] >0)A[i][j]--;
            }
        }

        //arr_print();
    }
        for(int i =0;i<N;i++){
            for(int j =0;j<N;j++){
                answer += A[i][j];
            }
        }
        bfs();
        cout << answer <<"\n" << max_size;

    return 0;
}