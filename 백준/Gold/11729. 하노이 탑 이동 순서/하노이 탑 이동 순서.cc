#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <deque>
#include<queue>
#include<string>
#include<stack>
#include <tuple>
#include <cmath>
using namespace std;

stack<int>s1, s2, s3;

int N, M, K;

void hanoi(int a, int b,int num) {
    if (num == 1) {
        cout << a << " " << b << "\n";
        return;
    }

    //N번째 층을 3으로 옮기려면 N-1번째까지 2로 옮겨야한다.
    hanoi(a, 6 - a - b,  num - 1);
    cout << a << " " << b << "\n";
    //N번째 층을 3으로 옮기면 N-1번째까지 층을 3으로 옮겨야한다.
    hanoi(6 - a - b, b, num - 1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    cout << (1 << N) - 1 << '\n';
    //N번째 층을 3으로 옮겨야한다.
    hanoi(1, 3, N);


    return 0;
}
