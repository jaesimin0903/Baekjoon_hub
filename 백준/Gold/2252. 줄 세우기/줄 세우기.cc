#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int degree[33000];
vector<int>graph[33000];

void topSort() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		cout << x << " ";

		for (int i = 0; i < graph[x].size(); i++) {
			if (--degree[graph[x][i]] == 0)q.push(graph[x][i]);
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		degree[n2]++;
		graph[n1].push_back(n2);
	}
	
	topSort();

	return 0;
}
