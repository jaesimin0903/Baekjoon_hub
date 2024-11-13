#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
int N;
ll B;
vector<vector<int>> basicMat(6, vector<int>(6, 0));

vector<vector<int>> matrixPow(ll n, vector<vector<int>> v) {

    // n이 1이면 입력 행렬 v를 그대로 반환
    if (n == 1) return v;

    // n이 0이면 단위 행렬 basicMat을 반환
    if (n == 0) return basicMat;

    // n을 절반으로 나눈 결과를 재귀적으로 계산하여 저장
    vector<vector<int>> mat = matrixPow(n / 2, v);

    // 결과를 저장할 임시 행렬 tmp 초기화
    vector<vector<int>> tmp(N, vector<int>(N, 0));

    // 현재 계산된 mat 행렬을 출력하여 중간 결과 확인


    // n이 짝수인 경우
    if (n % 2 == 0) {
        // tmp에 mat * mat 결과를 저장
        for (int a = 0; a < N; a++) {
            for (int b = 0; b < N; b++) {
                int part = 0;

                // 행렬 곱셈 수행하여 part에 결과 저장
                for (int c = 0; c < N; c++) {
                    part += mat[a][c] * mat[c][b];
                }

                // 결과를 1000으로 나눈 나머지를 tmp에 저장
                tmp[a][b] = part % 1000;
            }
        }
    }
    // n이 홀수인 경우
    else {
        // tmp1에 mat * mat 결과를 저장
        vector<vector<int>> tmp1(N, vector<int>(N, 0));
        for (int a = 0; a < N; a++) {
            for (int b = 0; b < N; b++) {
                int part = 0;

                // 행렬 곱셈 수행하여 part에 결과 저장
                for (int c = 0; c < N; c++) {
                    part += mat[a][c] * mat[c][b];
                }

                // 결과를 1000으로 나눈 나머지를 tmp1에 저장
                tmp1[a][b] = part % 1000;
            }
        }

        // tmp에 tmp1 * v 결과를 저장
        for (int a = 0; a < N; a++) {
            for (int b = 0; b < N; b++) {
                int part = 0;

                // 행렬 곱셈 수행하여 part에 결과 저장
                for (int c = 0; c < N; c++) {
                    part += tmp1[a][c] * v[c][b];
                }

                // 결과를 1000으로 나눈 나머지를 tmp에 저장
                tmp[a][b] = part % 1000;
            }
        }
    }


    // 최종 계산된 tmp 행렬 반환
    return tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> B;

	vector<vector<int>> matrix(N,vector<int>(N,0));
	vector<vector<int>> ans(N, vector<int>(N, 0));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
	}
		
	

	for (int i = 0; i < N; i++) {
		basicMat[i][i] = 1;
	}

	ans = matrixPow(B, matrix);

	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			cout << ans[a][b] % 1000 << " ";
		}
		cout << "\n";
	}

	return 0;
}
