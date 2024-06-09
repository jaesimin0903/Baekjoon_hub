#include <iostream>
#include <vector>
#include <deque>
using namespace std;

typedef long long ll;
int N, M;

deque<int> arr; // 로봇 위치 추적
deque<int> rail; // 내구성 추적

void rotateBelt() {
    rail.push_front(rail.back());
    rail.pop_back();
    arr.push_front(arr.back());
    arr.pop_back();
    arr[N-1] = 0; // 끝 위치에서 로봇 제거
}

void moveRobots() {
    for (int i = N-2; i >= 0; i--) {
        if (arr[i] == 1 && arr[i+1] == 0 && rail[i+1] > 0) {
            arr[i] = 0;
            arr[i+1] = 1;
            rail[i+1]--;
        }
    }
    arr[N-1] = 0; // 끝 위치에서 로봇 제거
}

void placeNewRobot() {
    if (rail[0] > 0) {
        arr[0] = 1;
        rail[0]--;
    }
}

int countWornOut() {
    int count = 0;
    for (int i = 0; i < 2*N; i++) {
        if (rail[i] == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    cin >> N >> M;
    rail.resize(2 * N);
    arr.resize(2 * N, 0);

    for (int i = 0; i < 2 * N; i++) {
        cin >> rail[i];
    }

    int rounds = 0;

    while (countWornOut() < M) {
        rounds++;
        rotateBelt();
        moveRobots();
        placeNewRobot();
    }

    cout << rounds << endl;

    return 0;
}
