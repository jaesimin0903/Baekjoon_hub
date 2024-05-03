#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

void toggle(string& s, int index) {
    for (int i = index - 1; i <= index + 1; ++i) {
        if (i >= 0 && i < s.size()) {
            s[i] = (s[i] == '0') ? '1' : '0';
        }
    }
}

int minSwitches(string Q, string A, bool firstSwitch) {
    int n = Q.size();
    int count = 0;
    if (firstSwitch) {
        toggle(Q, 0);
        count++;
    }

    for (int i = 1; i < n; ++i) {
        if (Q[i - 1] != A[i - 1]) {
            toggle(Q, i);
            count++;
        }
    }

    return (Q == A) ? count : INT_MAX;
}

int main() {
    int N;
    cin >> N;
    string Q, A;
    cin >> Q >> A;

    int result1 = minSwitches(Q, A, true);  // 첫 번째 스위치를 누르는 경우
    int result2 = minSwitches(Q, A, false); // 첫 번째 스위치를 누르지 않는 경우

    int result = min(result1, result2);
    if (result == INT_MAX) {
        cout << -1;
    } else {
        cout << result;
    }

    return 0;
}
