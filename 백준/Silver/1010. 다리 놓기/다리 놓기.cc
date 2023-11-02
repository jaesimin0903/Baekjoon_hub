#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;



ll c[30][30];

void combination() // n >= m
{
	for (int i = 1; i < 30; i++) {
		c[i][i] = 1;
		c[i][1] = i;
	}
	for (int i = 2; i < 30; i++) {
		for (int j = 2; j < 30; j++) {
			if (i > j)
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
}

int main()
{
	int T, N, M;
	cin >> T;
	int* count = new int[T];
	combination();

	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		count[i] =  c[M][N];
	}
	for (int i = 0; i < T; i++) {
		cout << count[i] << '\n';
	}
	return 0;
}