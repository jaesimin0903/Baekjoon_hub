#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

int N, M;

bool visited[51];

int maxChickenDis = INT_MAX;


void dfs(vector<pair<int, int>>& house, vector<pair<int, int>>& chicken, int count,int idx, vector<pair<int,int>>ans) {
    if (count == M) {
        //for (auto& val : ans) {
        //    cout << val.first << " " << val.second << " ";
        //}
        //cout << "\n";
        int chickenDis = 0;
        for (int i = 0; i < house.size(); i++) {
            int houseChiken = INT_MAX;
            for (int j = 0; j < ans.size(); j++) {
                //가장 거리가 짧은 놈 고르기
                if (houseChiken > abs(ans[j].first - house[i].first) + abs(ans[j].second - house[i].second)) {
                    houseChiken = abs(ans[j].first - house[i].first) + abs(ans[j].second - house[i].second);
                }
            }
            //cout << houseChiken << "\n";
            chickenDis += houseChiken;
            
        }
        if (maxChickenDis > chickenDis) {
            maxChickenDis = chickenDis;
        }
        return;
    }

    if (idx > chicken.size()-1) {
        return;
    }

    for (int i = idx; i < chicken.size(); i++) {
        //cout << i << " "<< count << "\n";
        if (!visited[i]) {
            visited[i] = true;
            ans.push_back(chicken[i]);
            dfs(house, chicken, count + 1, i+1, ans);
            ans.pop_back();
            visited[i] = false;
        }
       // cout << "==========" << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> N >> M;

    vector<pair<int, int>>chicken;
    vector<pair<int, int>>house;
    vector<vector<int>>map(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                house.push_back({ i,j });
            }
            else if (map[i][j] == 2) {
                chicken.push_back({ i,j });
            }
        }
    }
    vector<pair<int,int>> answer;

    /*for (auto& val : chicken) {
        cout << val.first << " " << val.second << " ";
    }*/
    //cout << "\n";
    dfs(house, chicken, 0, 0, answer);

    cout << maxChickenDis;
    

    return 0;
}
