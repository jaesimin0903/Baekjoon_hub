#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N;
int L[1000010];

bool canDistribute(int length) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        count += L[i] / length;
    }
    return count >= M;
}

int main() {
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    sort(L, L + N);

    int left = 1, right = L[N-1];
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (canDistribute(mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result;
    return 0;
}
