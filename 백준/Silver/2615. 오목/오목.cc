#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;



int main() {
	

	vector<vector<int>> v(20, vector<int>(20, 0));
	vector<vector<int>>visited(20, vector<int>(20, 0));
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			int num;
			cin >> num;
			v[i][j] = num;
		}
	}

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			int count = 1;
			if (visited[i][j])continue;
			if (v[i][j] == 0)continue;
			visited[i][j] = 1;
			for (int k = 1; k < 6; k++) {
				//horizon
				if (i + k < 19 && v[i][j] == v[i + k][j]) {
					count++;
				}
				else break;
			}
			if (count == 5) {
				if (i - 1 >= 0 && v[i-1][j] == v[i][j])continue;
				else {
					cout << v[i][j] << "\n";
					cout << i + 1 << " " << j + 1;
					return 0;
					break;
				}
			}
			count = 1;
			for (int k = 1; k < 6; k++) {
				//horizon
				if (j + k < 19&&v[i][j] == v[i][j+k]  ) {
					count++;
				}
				else break;
			}
			if (count == 5) {
				if (j - 1 >= 0 && v[i ][j-1] == v[i][j])continue;
				else {
					cout << v[i][j] << "\n";
					cout << i + 1 << " " << j + 1;
					return 0;
					break;
				}
				
			}
			count = 1;
			for (int k = 1; k < 6; k++) {
				//horizon
				if (i + k < 19 && j + k < 19&&v[i][j] == v[i+k][j + k] ) {
					count++;
				}
				else break;
			}
			if (count == 5) {
				if (i - 1>=0 && j - 1 >= 0 && v[i - 1][j - 1] == v[i][j]) continue;
				else {
					cout << v[i][j] << "\n";
					cout << i + 1 << " " << j + 1;
					return 0;
					break;
				}
				
			}
			count = 1;
			for (int k = 1; k < 6; k++) {
				//horizon
				if (i - k >=0 && j + k < 19&&v[i][j] == v[i - k][j + k]  ) {
					count++;
					
				}
				else break;
			}
			if (count == 5) {
				if (i +1  < 19 && j - 1 >= 0 && v[i + 1][j -1] == v[i][j]) continue;
				else {
					cout << v[i][j] << "\n";
					cout << i + 1 << " " << j + 1;
					return 0;
					break;
				}
				
			}
		}
	}

	cout << 0;
	
	return 0;
}

