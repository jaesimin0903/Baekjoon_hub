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

#define MAX_SIZE  3333

int n;
int minus_one = 0;
int zero = 0;
int one = 0;
int paper[MAX_SIZE][MAX_SIZE];

int func(int size, int x, int y) {
    //cout << "func" << "\n";
    if (size == 0) {
        return 0;
    }
    bool isOK = true;
    int start = paper[y][x];
    for (int i = y; i < y+size; i++) {
        for (int j = x; j < x+size; j++) {
            if (start != paper[i][j]) {
                isOK = false;
            }
        }
    }

    if (isOK &&start == -1) {
        minus_one++;
        return 0;
    }
    else if (isOK && start == 0) {
        zero++;
        return 0;
    }
    else if (isOK && start == 1) {
        one++;
        return 0;
    }
    func(size / 3, x, y);
    func(size / 3, x , y + size / 3);
    func(size / 3, x, y + size*2 / 3);
    func(size / 3, x + size/3, y);
    func(size / 3, x + size / 3, y+size/3);
    func(size / 3, x + size / 3, y + size*2 / 3);
    func(size / 3, x + size*2 / 3, y);
    func(size / 3, x + size * 2 / 3, y+size/3);
    func(size / 3, x + size * 2 / 3, y + size*2 / 3);
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    func(n, 0, 0);
    cout << minus_one << "\n";
    cout << zero << "\n";
    cout << one << "\n";
    return 0;
}