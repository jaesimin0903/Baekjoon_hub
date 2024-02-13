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


bool visited[21];
int ans = 0;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    while (true) {
        cin >> N;
        if (N == 0) break;

        vector<int> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }

        vector<int> combination;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (cnt == 6) {
                combination.push_back(1);
            }
            else {
                combination.push_back(0);
                cnt++;
            }
        }
        do {
            for (int i = 0; i < N; i++) {
                if (combination[i] == 0) {
                    cout << v[i] << " ";
                }
            }
            cout << "\n";
        } while (next_permutation(combination.begin(), combination.end()));
        cout << "\n";
    }
    return 0;
    
    
}