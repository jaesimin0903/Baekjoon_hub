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

int N, M, K;


bool visited[100005];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    queue<pair<int,int>> q;

    q.push(make_pair(N,0));
    visited[N] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();
        //cout << cur << " "<<time << "\n";
        if (cur == M) {
            cout << time;
            return 0;
        }
        
        /*for (int i = 1; cur * pow(2, i) <= M; i++) {
            int pow_cur = cur * pow(2, i);
            if (pow_cur <= M) {
                if (!visited[pow_cur]) {
                    q.push(make_pair(pow_cur, time));
                    visited[pow_cur] = true;
                }
            }
        }*/
        
        if (cur * 2<= 100000) {
            if (!visited[cur * 2]) {
                q.push(make_pair(cur * 2, time));
                visited[cur * 2] = true;
            }
        }

        if (cur - 1 >= 0) {
            if (!visited[cur - 1]) {
                q.push(make_pair(cur - 1, time + 1));
                visited[cur - 1] = true;
            }
        }
        if (cur + 1 <= M) {
            if (!visited[cur + 1]) {
                q.push(make_pair(cur + 1, time + 1));
                visited[cur + 1] = true;
            }
        }
        
    }


    return 0;
}
