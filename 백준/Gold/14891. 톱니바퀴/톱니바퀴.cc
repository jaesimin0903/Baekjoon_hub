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

//vector<tuple <long long, int, int>> graph[1000001];
//
//int V, E;
//
//vector<int> parent(100005, -1);

//int find(int x) {
//    if (parent[x] < 0) return x;
//    return parent[x] = find(parent[x]);
//}
//
//bool is_diff_group(int u, int v) {
//    u = find(u); v = find(v);
//    if (u == v) return 0;
//    if (parent[u] == parent[v])parent[u]--;
//    if (parent[u] < parent[v]) parent[v] = u;
//    else parent[u] = v;
//    return 1;
//}

int a[25][25],N,M, d, k, c,ret;

//N : 0 , S : 1
//1 : clock -1 : reverse
//1 0 1 0 1 1 1 1
//태엽은 2번, 6번 인덱스와 다른태엽이 닿는다.
//12  

//회전하기전 태엽과의 상태 
//회전이후 태엽상태

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    deque<char>gear[4];

    for (int i = 0; i < 4; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < 8; j++) {
            gear[i].push_back(str[j]);
        }
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        int target_gear;
        int rotate;

        cin >> target_gear >> rotate;

        //rotate logic
        //1,4번 가각 6번, 2번은 확인 안해됨
        
        queue<pair<int, int>> q;
        q.push({ target_gear, rotate });
        int visited[4] = { 0, };

        visited[target_gear - 1] = rotate;
        while (!q.empty()) {
            int target = q.front().first;
            int rot = q.front().second;

            q.pop();

            if (target == 4) {
                //3번에 방문안했고, 기어의 극이 다르다면
                if (visited[target - 2]==0 && gear[target - 1][6] != gear[target - 2][2]) {
                    visited[target - 2] = -rot;
                    q.push({ target - 1,-rot });
                    
                }
            }
            else if (target == 1) {
                //2번에 방문안했고, 기어의 극이 다르다면
                if (!visited[target] && gear[target - 1][2] != gear[target][6]) {
                    visited[target] = -rot;
                    q.push({ target+1,-rot });
                }
            }
            else {
                if (visited[target - 2]==0 && gear[target - 1][6] != gear[target - 2][2]) {
                    visited[target-2] = -rot;
                    q.push({ target-1,-rot });
                }
                if (visited[target]==0 && gear[target - 1][2] != gear[target][6]) {
                    visited[target] = -rot;
                    q.push({ target+1,-rot });
                }
            }
        }
        //status 

        for (int j = 0; j < 4; j++) {
            if (visited[j] != 0) {
                if (visited[j] == -1) {
                    char tmp = gear[j].front();
                    gear[j].pop_front();
                    gear[j].push_back(tmp);
                }
                else if (visited[j] == 1) {
                    char tmp = gear[j].back();
                    gear[j].pop_back();
                    gear[j].push_front(tmp);
                }
            }
        }
        /*for (int j = 0; j < 4; j++) {
            cout << visited[j] << " ";
        }
        cout << "\n";

        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 8; k++) {
                cout << gear[j][k] << " ";
            }
            cout << "\n";
        }*/

    }

    //answer
    int answer = 0;

    for (int i = 0; i < 4; i++) {
        if (gear[i].front() == '1') answer += pow(2, i);
    }
    cout << answer;
    return 0;
}

