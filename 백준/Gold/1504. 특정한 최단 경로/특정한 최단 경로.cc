#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, X;
vector<vector<int>> graph;
vector<vector<int>> dis;

void dijkstra(int start) {
	// 우선순위 큐를 사용한 다익스트라 알고리즘 구현
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	// 시작 노드로부터의 거리 초기화
	dis[start][start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cur_dist = pq.top().first;
		pq.pop();

		// 이미 더 짧은 경로가 있으면 스킵
		if (cur_dist > dis[start][cur]) continue;

		// 인접 노드들에 대해 최단 경로 업데이트
		for (int i = 1; i <= N; i++) {
			if (graph[cur][i] != 1e9 && dis[start][i] > dis[start][cur] + graph[cur][i]) {
				dis[start][i] = dis[start][cur] + graph[cur][i];
				pq.push({ dis[start][i], i });
			}
		}
	}
}

int main() {
	cin >> N >> M;

	// 그래프 및 거리 배열 초기화
	graph.assign(N + 1, vector<int>(N + 1, 1e9/2));
	dis.assign(N + 1, vector<int>(N + 1, 1e9/2));

	for (int i = 0; i < M; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		graph[s][e] = t;  // 간선 입력
		graph[e][s] = t;
	}

	int s, e;
	cin >> s >> e;
	
	dijkstra(1);
	dijkstra(s);
	dijkstra(e);


	// 결과 출력
	int path1 = dis[1][s] + dis[s][e] + dis[e][N];  // 1 -> s -> e -> N 경로
	int path2 = dis[1][e] + dis[e][s] + dis[s][N];  // 1 -> e -> s -> N 경로

	// 두 경로 모두 불가능한 경우
	if (path1 >= 1e9/2 && path2 >= 1e9/2) {
		cout << -1;
	}
	// 경로 2가 불가능한 경우 경로 1을 출력
	else if (path2 >= 1e9) {
		cout << path1;
	}
	// 경로 1이 불가능한 경우 경로 2를 출력
	else if (path1 >= 1e9) {
		cout << path2;
	}
	// 두 경로가 모두 가능할 경우 더 짧은 경로 출력
	else {
		cout << min(path1, path2);
	}

	
	return 0;
}
