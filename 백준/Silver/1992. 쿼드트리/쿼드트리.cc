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
vector<string> v;
string ans = "";
int func(int size, int x, int y) {
    //cout << "func" << "\n";
    if (size == 0) {
        return 0;
    }

    bool isOK = true;
    char start = v[y][x];
    for (int i = y; i < y+size; i++) {
        for (int j = x; j < x+size; j++) {
            if (start != v[i][j]) {
                isOK = false;
            }
        }
    }

    if (isOK) {

        if (start == '0') {
            ans += '0';
        }
        else {
            ans += '1';
        }
        return 0;
    }
    else {
        ans += "(";
        func(size / 2, x, y);
        func(size / 2, x + size / 2, y);
        func(size / 2, x, y + size / 2);
        func(size / 2, x + size / 2, y + size / 2);
        ans += ")";
    }

    


    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }

    func(n, 0, 0);

    cout << ans;
    
    return 0;
}