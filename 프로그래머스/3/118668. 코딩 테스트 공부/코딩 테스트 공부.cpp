#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minV(int a, int b){
    return (a < b) ? a : b;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int goalAl = alp, goalCo = cop;

    for (const auto &problem : problems) {
        goalAl = max(goalAl, problem[0]);
        goalCo = max(goalCo, problem[1]);
    }

    vector<vector<int>> dp(goalAl + 1, vector<int>(goalCo + 1, INT_MAX));
    dp[alp][cop] = 0;

    for (int i = alp; i <= goalAl; ++i) {
        for (int j = cop; j <= goalCo; ++j) {
            if (dp[i][j] == INT_MAX) continue;

            // Studying to increase alp or cop by 1
            if (i < goalAl) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            if (j < goalCo) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);

            // Solving problems to increase alp and cop
            for (const auto &problem : problems) {
                if (i >= problem[0] && j >= problem[1]) {
                    int newAl = min(goalAl, i + problem[2]);
                    int newCo = min(goalCo, j + problem[3]);
                    dp[newAl][newCo] = min(dp[newAl][newCo], dp[i][j] + problem[4]);
                }
            }
        }
    }

    return dp[goalAl][goalCo];
}