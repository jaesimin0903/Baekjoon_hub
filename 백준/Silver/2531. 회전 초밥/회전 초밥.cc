#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, d, k, c;
    cin >> N >> d >> k >> c;
    
    vector<int> rail(N);
    for (int i = 0; i < N; i++) {
        cin >> rail[i];
    }

    unordered_map<int, int> sushi_count;
    int total_types = 0; // 현재 윈도우 내의 초밥 종류 수
    int max_types = 0;

    // 초기 윈도우 설정
    for (int i = 0; i < k; i++) {
        if (sushi_count[rail[i]]++ == 0) total_types++;
    }
    // 쿠폰 초밥 추가
    if (sushi_count[c]++ == 0) total_types++;

    max_types = total_types;

    // 슬라이딩 윈도우
    for (int i = 1; i < N; i++) {
        // 앞에서 초밥 제거
        if (--sushi_count[rail[i-1]] == 0) total_types--;

        // 뒤에 새로운 초밥 추가
        int new_sushi = rail[(i + k - 1) % N];
        if (sushi_count[new_sushi]++ == 0) total_types++;

        // 쿠폰 초밥 확인
        max_types = max(max_types, total_types + (sushi_count[c] == 0));
    }

    cout << max_types;

    return 0;
}
