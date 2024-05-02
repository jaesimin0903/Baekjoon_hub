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
#include <map>
#include <unordered_set>
#include <unordered_map>
#include<cstring>
#include<iomanip>
using namespace std;

typedef long long ll;

int N, K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S;
    cin >> S;
    int answer = S.size() * 2;
    for (int i = S.size() - 1; i >= S.size() / 2; i--) {
        bool is_pal = true;
            //i-3 i-2 i-1 i i+1 i+2
            int t = 0;
            while (1) {
                if (i + t >= S.size()) break;
                if (S[i + t] != S[i - t - 1]) {
                    is_pal = false;
                    break;
                }
                else {
                    t++;
                }
            }
            if (is_pal) {
                if (S.size() / 2 == i) {
                    cout << S.size(); return 0;
                }
                answer = min(answer, i * 2);
            }
            is_pal = true;
            t = 1;
            while (1) {
                if (i + t >= S.size()) break;
                if (S[i + t] != S[i - t]) {
                    is_pal = false;
                    break;
                }
                else {
                    t++;
                }
           }
            if (is_pal) {
                if (S.size() / 2 == i && S.size() % 2 == 1) {
                    cout << S.size(); return 0;
                }
                answer = min(answer, i * 2 + 1);
            }
        

    }

    cout << answer;
    return 0;
}
