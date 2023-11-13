#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include<stack>
#include<cmath>
using namespace std;

vector<int> res;
int w = 0;
int b = 0;

void print(vector<vector<int>>v) {
    for (auto& row : v) {
        for (auto& val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}
bool isPromising(int row, int col, int n, vector<vector<bool>> visited) {
    bool result = true;
    for (int r = row - 1, t = 1; r >= 0; r--, t++) {
        if ((col - t >= 0 && visited[r][col - t]) || (col + t < n && visited[r][col + t])) {
            return false;
        }
    }
    return result;
}

int ans = 0;

void dfs(vector<pair<int,int>> eggs,int n,int idx, int sum) {
    //오른쪽 끝일때
    if (idx >= n) {
        int cnt=0;
        for (int i = 0; i < n; i++) {
            if (eggs[i].first <= 0) {
                cnt++;
            }
        }
        if (cnt > ans) ans = cnt;
        return;
    }

    //던지려는 계란이 깨졌을때
    if (eggs[idx].first <= 0) {
        dfs(eggs, n, idx + 1, sum);
        return;
    }

    bool check = false;
    for (int i = 0; i < n; i++) {
        //던지려는 계란과 타겟이 동일하지 않다면
        if (i != idx) {
            vector<pair<int, int>> copy = eggs;

            //타겟이 깨지지 않았다면
            if (eggs[i].first > 0) {
                copy[i].first -= eggs[idx].second;
                copy[idx].first -= eggs[i].second;

                int dfsSum = sum;
                check = true;
                if (copy[i].first <= 0) {
                    dfsSum++;
                }
                if (copy[idx].first <= 0) {
                    dfsSum++;
                }
                dfs(copy, n, idx + 1, dfsSum);

            }
        }
    }

    if (!check) dfs(eggs, n, n, sum);

    
    
}



int main() {
    //주어진 맵에서 배치 가능한모든 곳에서 dfs
    //배치했을 경우 대각방향의 위치를 움직일 수 없게 dfs 에 맵 전달
    
    int n;
    cin >> n;
    int hp, weight;

    vector<pair<int, int>>eggs;

    for (int i = 0; i < n; i++) {
        cin >> hp >> weight;
        eggs.push_back({hp, weight});
    }
    
    int sum = 0;

    dfs(eggs,n,0, sum);
    
    cout << ans;

    return 0;
}

