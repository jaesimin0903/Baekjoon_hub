#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[1010];
int N, M;
int getParent(int v) {
	if (parent[v] == v) return v;
	return parent[v] = getParent(parent[v]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a == b) return 1;
	return 0;
}

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator <(Edge& edge) {
		return this->distance < edge.distance;
	}
};
	vector<Edge> v;

void kruskal() {

	sort(v.begin(), v.end());

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!findParent(v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance;
			unionParent(v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}

	cout << sum << "\n";
}

int main() {
	
	cin >> N >> M;
	
	for (int i = 1;i<=N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i ++ ) {
		int s, e, w;
		cin >> s >> e >> w;

		v.push_back(Edge(s, e, w));
	}

	kruskal();


	return 0;
}