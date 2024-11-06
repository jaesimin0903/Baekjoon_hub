#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, L;
vector<int> rest_areas;

bool canInstall(int distance) {
    int count = 0;
    for (int i = 1; i < rest_areas.size(); i++) {
        int gap = rest_areas[i] - rest_areas[i - 1];
        count += (gap - 1) / distance;  // gap을 distance로 나눠 필요한 휴게소 수 계산
    }
    return count <= M;
}

int main() {
    cin >> N >> M >> L;
    rest_areas.resize(N + 2);
    rest_areas[0] = 0;  // 고속도로 시작점
    rest_areas[N + 1] = L;  // 고속도로 끝점
    
    for (int i = 1; i <= N; i++) {
        cin >> rest_areas[i];
    }
    
    sort(rest_areas.begin(), rest_areas.end());

    int left = 1, right = L, result = L;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canInstall(mid)) {
            result = mid;  // 더 작은 거리로 시도 가능
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}
