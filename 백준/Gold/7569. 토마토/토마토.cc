#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int N, M,H;

struct tomato {
	int x;
	int y;
	int h;
};

queue<tomato> q;
//vector<vector<vector<int>>>v(100, vector<int>(100,vector<int>(100,0)));

int v[100][100][100];

void bfs(int v[100][100][100]) {
	while (!q.empty()) {
		int i = q.front().x;
		int j = q.front().y;
		int k = q.front().h;

		q.pop();

		if (i - 1 >= 0 && v[i - 1][j][k] == 0) {
			v[i - 1][j][k] = v[i][j][k] + 1;
			q.push({ i - 1,j ,k});
		}
		if (j - 1 >= 0 && v[i ][j-1][k] == 0) {
			v[i ][j-1][k] = v[i][j][k] + 1;
			q.push({ i ,j-1 ,k});
		}
		if (i +1 <H && v[i + 1][j][k] == 0) {
			v[i + 1][j][k] = v[i][j][k] + 1;
			q.push({ i + 1,j ,k});
		}
		if (j+ 1 <N && v[i][j+1][k] == 0) {
			v[i][j+1][k] = v[i][j][k] + 1;
			q.push({ i,j+1 ,k});
		}
		if (k - 1 >= 0 && v[i][j][k - 1] == 0) {
			v[i][j][k - 1] = v[i][j][k] + 1;
			q.push({ i,j,k - 1 });
		}
		if (k + 1 <M && v[i][j][k + 1] == 0) {
			v[i][j][k + 1] = v[i][j][k] + 1;
			q.push({ i,j,k + 1 });
		}

	}
}
int main() {

	//int N, M;
	cin >> M >> 
		N>>H;



	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				int num;
				cin >> num;
				v[i][j][k] = num;
			}
		}
	}

	

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (v[i][j][k] == 1)q.push({ i,j,k });

			}
		}
	}



	bfs(v);


	int maxx = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (v[i][j][k] == 0) {
					cout << -1 << "\n";
					return 0;
				}
				if (maxx < v[i][j][k]) maxx = v[i][j][k];
			}
			
		}
		
	}

	

	cout << maxx-1 << "\n";

	return 0;
}
