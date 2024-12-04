#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector<int> labortory;
int MST[1010];
vector<pair<int, int>> graph[1010];
int parent[1010];
bool visited[1010];
int getParent(int x) {
	if (x != parent[x]) {
		return getParent(parent[x]);
	}
	return x;
}

void unite(int a, int b) {
	int pa = getParent(a);
	int pb = getParent(b);

	if (pa != pb) {
		parent[pa] = pb;
	}
}


void kruskal() {
	priority_queue < pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

	// 연구소와 연결된 친구들 먼저 pq에담기;

	for (auto labor : labortory) {
		visited[labor] = true;
		for (auto nextCity : graph[labor]) {
			pq.push({ nextCity.first, {nextCity.second, labor} });
		}
	}

	while (!pq.empty()) {
		int curCityVal = pq.top().first;
		int curCity = pq.top().second.first;
		int beforeCity = pq.top().second.second;

		pq.pop();

//		cout << curCity << " <- " << beforeCity << "\n";

		if (visited[curCity]) continue;
		unite(curCity, beforeCity);
		MST[getParent(curCity)] += curCityVal;
		visited[curCity] = true;

		for (int i = 0; i < graph[curCity].size(); i++) {
			int nextCity = graph[curCity][i].second;
			int nextCityVal = graph[curCity][i].first;

			int pn = getParent(nextCity);
			int pc = getParent(curCity);
			if (pn != pc && !visited[nextCity]) {
				//visited[nextCity] = true;
				pq.push({ nextCityVal, {nextCity, curCity} });
			}
		}
	}
}

int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int n;
		cin >> n;
		labortory.push_back(n);
	}

	for (int i = 0; i < M; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		graph[s].push_back({c,e });
		graph[e].push_back({ c,s });
	}

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	kruskal();

	int answer = 0;
	for (auto labor : labortory) {
		answer += MST[labor];
	}

	cout << answer;
	return 0;
}