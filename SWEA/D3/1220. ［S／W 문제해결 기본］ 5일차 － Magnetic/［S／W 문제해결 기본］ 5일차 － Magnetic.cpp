#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T = 10;

    // freopen("input.txt", "r", stdin);

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        cin >> N;
        int arr[100][100];

        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> arr[i][j];
            }
        }

        int answer = 0;

        for (int i = 0; i < 100; i++) { // 각 열(column)에 대해 반복
            bool is_start_r = false; // 빨간 자성체가 시작했는지 여부
            for (int j = 0; j < 100; j++) {
                if (arr[j][i] == 1) { // 빨간 자성체를 만난 경우
                    is_start_r = true;
                } else if (arr[j][i] == 2 && is_start_r) { // 파란 자성체를 만나고 이전에 빨간 자성체가 있던 경우
                    answer++;
                    is_start_r = false; // 새로운 교착 상태를 찾기 위해 초기화
                }
            }
        }

        cout << "#" << test_case << " " << answer << "\n";
    }

    return 0; // 정상 종료 시 반드시 0을 리턴해야 합니다.
}
