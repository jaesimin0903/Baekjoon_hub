#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    // freopen("input.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N, M, K;
        cin >> N >> M >> K;
        vector<int> arrival_times(N);
        for (int i = 0; i < N; i++) {
            cin >> arrival_times[i];
        }
        sort(arrival_times.begin(), arrival_times.end());

        string answer = "Possible";
        int current_breads = 0;
        
        for (int i = 0; i < N; i++) {
            int current_time = arrival_times[i];
            
            // current_time까지 만들어진 총 빵의 개수
            int breads_made = (current_time / M) * K;
            current_breads = breads_made - i; // i는 0부터 시작하므로 i+1명이 아니라 i로 처리
            if (current_breads < 1) {
                answer = "Impossible";
                break;
            }
        }

        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0; // 정상 종료 시 반드시 0을 리턴해야 합니다.
}
