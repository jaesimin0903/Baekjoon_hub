#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
vector<string> v;
bool visited[1010][1010];

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	int ans = 0;
	//위에 가로로
	for (int i = 0; i < N; i++) {
		int art = 0;
		for (int j = 0; j < M; j++) {
			if (v[i][j] == '.' && !visited[i][j] && v[i - 1][j] == 'X') {
				art++;
				visited[i][j];
				if (art == 2) {
					ans++;
					art = 0;
				}
			}
			else {
				art = 0;
			}
		}
	}

	fill(&visited[0][0], &visited[0][0] + 1010 * 1010, false);

	for (int i = 0; i < N; i++) {
		int art = 0;
		for (int j = 0; j < M; j++) {
			if (v[i][j] == '.' && !visited[i][j] && v[i + 1][j] == 'X') {
				art++;
				visited[i][j];
				if (art == 2) {
					ans++;
					art = 0;
				}
			}
			else {
				art = 0;
			}
		}
	}

	fill(&visited[0][0], &visited[0][0] + 1010 * 1010, false);

	for (int j = 0; j < M; j++) {
		int art = 0;
		for (int i = 0; i < N; i++) {
			if (v[i][j] == '.' && !visited[i][j] && v[i][j+1] == 'X') {
				art++;
				visited[i][j];
				if (art == 2) {
					ans++;
					art = 0;
				}
			}
			else {
				art = 0;
			}
		}
	}

	fill(&visited[0][0], &visited[0][0] + 1010 * 1010, false);

	for (int j = 0; j < M; j++) {
		int art = 0;
		for (int i = 0; i < N; i++) {
			if (v[i][j] == '.' && !visited[i][j] && v[i][j -1] == 'X') {
				art++;
				visited[i][j];
				if (art == 2) {
					ans++;
					art = 0;
				}
			}
			else {
				art = 0;
			}
		}
	}

	cout << ans;

	return 0;
}
