#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//(1,1) ~ (N,N) 인 2차원배열
//배열의 범위가 넘어가게되더라도 반대쪽과 멀어진다

//비바라기 N,1 N,2 N-1,1 N-1,2 생성
//M번의 이동 명령 (d: 방향, s: 거리)
//8방 이동

//1. 구름이동
//2. 비뿌리기 (비뿌린 곳에 2증가)
//3. 비뿌려진 곳의 대각선 방향에 물이 있다면 있는 수만큼 증가
//4. 물이 2이상인 곳에 구름 생김

//queue 를 사용해서 구름의 위치를 저장

int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int dx[8] = { -1,-1,0,1,1,1,0,-1 };

bool oob(int y, int x, int N) {
    return y < 0 || x < 0 || y >= N || x >= N;
}

int mod(int a, int b) {
    return (a % b + b) % b;
}

void print_arr(int arr[][60], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int arr[60][60];
    int M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    queue<pair<int, int>> q;
    q.push({ N - 1,0 });
    q.push({ N - 1,1 });
    q.push({ N - 2,0 });
    q.push({ N - 2,1 });
    for (int i = 0; i < M; i++) {
        int d, s;
        cin >> d >> s;

        bool visited[60][60];
        fill(&visited[0][0], &visited[0][0] + 60 * 60, false);

        queue<pair<int, int>> tmp;
        while (!q.empty()) {
            int y, x;
            y = q.front().first;
            x = q.front().second;
            q.pop();

            int ny = mod(y + dy[d - 1] * s, N);
            int nx = mod(x + dx[d - 1] * s, N);
            
            arr[ny][nx]++;
            tmp.push({ ny,nx });
        }



        //tmp 큐 에서 대각선 방향 물있는지 확인 후 더하고 방문 확인
        while (!tmp.empty()) {
            int y, x;
            y = tmp.front().first;
            x = tmp.front().second;
            tmp.pop();
            visited[y][x] = true;
            for (int i = 1; i < 8; i += 2) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (oob(ny, nx,N))continue;
                if (arr[ny][nx] == 0)continue;
                arr[y][x]++;
            }
        }



        //전체 순회하면서 방문하지 않고 2이상인 모든 점 큐에 넣기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j])continue;
                if (arr[i][j] < 2)continue;
                arr[i][j] -= 2;
                q.push({ i,j });
            }
        }


    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans += arr[i][j];
        }
    }

    cout << ans;

    return 0;
}
