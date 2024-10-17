#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int start, dest;
vector<pair<int, int>> graph[1010]; // 그래프의 인접 리스트
vector<int> cost(1010, 1e9); // 각 노드로 가는 최소 비용을 저장하는 벡터

int dijkstra(int s, int e) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	cost[s] = 0; // 시작점의 비용은 0
	pq.push({ 0, s }); // 우선순위 큐에 시작점 추가

	while (!pq.empty()) {
		int curVal = pq.top().first; // 현재 노드까지의 비용
		int curNode = pq.top().second; // 현재 노드
		pq.pop();

		// 이미 더 짧은 경로가 있으면 패스
		if (cost[curNode] < curVal) continue;

		// 현재 노드에서 인접한 노드 탐색
		for (int i = 0; i < graph[curNode].size(); i++) {
			int nextVal = graph[curNode][i].first; // 다음 노드까지의 비용
			int next = graph[curNode][i].second;   // 다음 노드

			// 더 짧은 경로가 있으면 업데이트
			if (cost[next] > cost[curNode] + nextVal) {
				cost[next] = cost[curNode] + nextVal;
				pq.push({ cost[next], next });
			}
		}
	}

	// s에서 e로 가는 최단 거리 반환

	return cost[e];
}

int main() {
	cin >> N >> M; // N은 노드 수, M은 간선 수

	// 그래프 입력
	for (int i = 0; i < M; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		graph[s].push_back({ v, e });
		//graph[e].push_back({ v, s }); // 양방향 그래프
	}

	// 시작점과 도착점 입력
	cin >> start >> dest;

	// 다익스트라 알고리즘 실행
	cout << dijkstra(start, dest) << endl;

	return 0;
}
