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

    cin >> N;

    string A[110];
    bool dp[110];
    fill(&dp[0], &dp[0] + 110, false);
    dp[0] = true;
    
    for (int i = 0; i < N; i++) {
        string s;
        cin >> A[i];
    }

    for (int i = 0; i < S.size(); i++) {
        if (dp[i]) {
            for (int j = 0; j < N; j++) {
                int len = A[j].size();
                int end = i + len;
                if (end <= S.size() && S.substr(i, len) == A[j]) {
                    //cout << end << "\n";
                    dp[end] = true;
                }
            }
        }
    }

    cout << dp[S.size()];

    return 0;
}
