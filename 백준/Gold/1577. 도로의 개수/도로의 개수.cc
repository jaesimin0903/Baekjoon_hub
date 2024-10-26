#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
int N, M, K;
ll dp[110][110];

int main() {
    cin >> N >> M >> K;

    set<pair<pair<int, int>, pair<int, int>>> blocked;
    for (int i = 0; i < K; i++) {
        int sy, sx, ey, ex;
        cin >> sy >> sx >> ey >> ex;
        blocked.insert({{sy, sx}, {ey, ex}});
        blocked.insert({{ey, ex}, {sy, sx}});
    }

    dp[0][0] = 1;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i > 0 && blocked.find({{i-1, j}, {i, j}}) == blocked.end()) {
                dp[i][j] += dp[i-1][j];
            }
            if (j > 0 && blocked.find({{i, j-1}, {i, j}}) == blocked.end()) {
                dp[i][j] += dp[i][j-1];
            }
        }
    }

    cout << dp[N][M] << endl;
    return 0;
}
