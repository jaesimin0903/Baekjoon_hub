#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int item[110];
int graph[110][110];
int n, m, r;
int main()
{
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = 1e9;
		}
	}
	for (int i = 0; i < r; i++) {
		int s, e,d;
		cin >> s >> e >> d;
		graph[s][e] = d;
		graph[e][s] = d;
	}

	//floyd
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		int total = 0;
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] <= m) {
				total += item[j];
			}
		}
		answer = max(answer, total);
	}

	cout << answer;
	return 0;
}