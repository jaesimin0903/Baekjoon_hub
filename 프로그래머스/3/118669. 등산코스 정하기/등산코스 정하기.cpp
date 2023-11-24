#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <climits>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<vector<pair<int, int>>> graph(n + 1);
    unordered_map<int, bool> isSummit;

    // 그래프 생성
    for (auto& path : paths) {
        graph[path[0]].push_back({path[1], path[2]});
        graph[path[1]].push_back({path[0], path[2]});
    }

    for (int summit : summits) {
        isSummit[summit] = true;
    }

    vector<int> intensity(n + 1, INT_MAX); // 각 정점까지의 최소 난이도
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 출발점(게이트) 초기화
    for (auto& gate : gates) {
        intensity[gate] = 0;
        pq.push({0, gate});
    }

    // 다익스트라 알고리즘
    while (!pq.empty()) {
        int currentIntensity = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (intensity[currentNode] < currentIntensity) continue;

        if (isSummit[currentNode]) continue; // 산봉우리에 도달하면 더 이상 탐색하지 않음

        for (auto& edge : graph[currentNode]) {
            int nextNode = edge.first;
            int nextIntensity = max(currentIntensity, edge.second);

            if (nextIntensity < intensity[nextNode]) {
                intensity[nextNode] = nextIntensity;
                pq.push({nextIntensity, nextNode});
            }
        }
    }

    // 결과 생성
    vector<int> answer = {*summits.begin(), intensity[*summits.begin()]};
    for (auto& summit : summits) {
        if (intensity[summit] < answer[1] || (intensity[summit] == answer[1] && summit < answer[0])) {
            answer = {summit, intensity[summit]};
        }
    }

    return answer;
}
