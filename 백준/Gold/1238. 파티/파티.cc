#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, X;
vector<pair<int,int>> graph[1010];

void dijkstra() {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	int cost[1010][1010];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cost[i][j] = 1e9;
		}
	}


	for (int i = 1; i <= N; i++) {
		cost[i][i] = 0;

		pq.push({ 0,i });
		while (!pq.empty()) {
			int cur = pq.top().second;
			int val = pq.top().first;
			pq.pop();

			for (int j = 0; j < graph[cur].size(); j++) {
				int next = graph[cur][j].second;
				int nextVal = graph[cur][j].first;
				if (i != next && cost[i][next] > cost[i][cur] + nextVal) {
					cost[i][next] = cost[i][cur] + nextVal;
					pq.push({ cost[i][next], next });
				}
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		answer = max(answer, cost[i][X] + cost[X][i]);
	}
	cout << answer;
}

int main() {
	cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		graph[s].push_back({ c,e });
	}

	dijkstra();

	return 0;
}