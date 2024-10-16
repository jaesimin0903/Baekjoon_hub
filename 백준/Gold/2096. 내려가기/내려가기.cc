#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001][3] = { 0 };
int N;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	// 현재와 이전 값을 저장할 1차원 배열
	int prevMax[3], currMax[3];
	int prevMin[3], currMin[3];

	// 초기 값 설정
	prevMax[0] = arr[0][0];
	prevMax[1] = arr[0][1];
	prevMax[2] = arr[0][2];

	prevMin[0] = arr[0][0];
	prevMin[1] = arr[0][1];
	prevMin[2] = arr[0][2];

	for (int i = 1; i < N; i++) {
		// 최대값 계산
		currMax[0] = max(prevMax[0], prevMax[1]) + arr[i][0];
		currMax[1] = max({ prevMax[0], prevMax[1], prevMax[2] }) + arr[i][1];
		currMax[2] = max(prevMax[1], prevMax[2]) + arr[i][2];

		// 최소값 계산
		currMin[0] = min(prevMin[0], prevMin[1]) + arr[i][0];
		currMin[1] = min({ prevMin[0], prevMin[1], prevMin[2] }) + arr[i][1];
		currMin[2] = min(prevMin[1], prevMin[2]) + arr[i][2];

		// 이전 값을 현재 값으로 갱신
		for (int j = 0; j < 3; j++) {
			prevMax[j] = currMax[j];
			prevMin[j] = currMin[j];
		}
	}

	// 최종 결과 출력
	cout << max({ prevMax[0], prevMax[1], prevMax[2] }) << " ";
	cout << min({ prevMin[0], prevMin[1], prevMin[2] }) << endl;

	return 0;
}
