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

int N, S;

vector<int> v;

bool visited[21];
int ans = 0;
void part_sum(int idx, int sum) {
    if (visited[idx]) {
        return;
    }

    if (sum == S) {
        ans++;
    }

    visited[idx] = 1;

    for (int i = idx; i < N; i++) {
        if (visited[i])continue;
        part_sum(i, sum + v[i]);
        visited[i] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    for (int i = 0; i < N; i++) {
        int sum = 0;
        part_sum(i,sum+v[i]);
        visited[i] = 0;
    }


    cout << ans;
    
    return 0;
}