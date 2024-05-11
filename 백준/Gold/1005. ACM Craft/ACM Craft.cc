#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

int T, N ,K;

ll price[1010];
ll inDgree[1010];
vector<int> a[1010];
ll dp[1010];
void topologySort() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDgree[i] == 0) {
            q.push(i); dp[i] = price[i];
        }
    }

    dp[0] = 0;
    //dp[1] = price[1];

    for (int i = 1; i <= N; i++) {
        if (q.empty()) {
            return;
        }
        int x = q.front();
        q.pop();
        for (int i = 0; i < a[x].size(); i++) {
            int y = a[x][i];
            //cout << y << " ";
            dp[y] = max(dp[x] + price[y], dp[y]);

            if (--inDgree[y] == 0) {
                //cout <<"제거 " << x << " " << y << "\n";
                q.push(y);
            }
        }
    }
}

int main() {
    
    cin >> T;
    while (T--) {
        cin >> N >> K;

        for (int i = 0; i < 1010; i++) {
            price[i] = 0;
            dp[i] = 0;
            inDgree[i] = 0;
        }
        for (int i = 1; i <= N; i++) {
            a[i].clear();
        }
        int target;
        for (int i = 1; i <= N; i++) {
            cin >> price[i];
        }

        for (int i = 0; i < K; i++) {
            int n1, n2;
            cin >> n1 >> n2;
            a[n1].push_back(n2);
            inDgree[n2]++;
        }

        cin >> target;

        /*cout << "indree ";
        for (int i = 1; i <= N; i++) {
            cout << inDgree[i] << " ";
        }
        cout << "\n";*/

        topologySort();
        //cout << "vector \n";
        //for (int i = 1; i <= N; i++) {
        //    for (int j = 0; j < a[i].size(); j++) {
        //        cout << a[i][j] << " ";
        //    }
        //    cout << "\n";
        //}

        //for (int i = 1; i <= N; i++) {
        //    cout << dp[i] << " ";
        //}
        //cout << "\n";

        cout << dp[target] <<"\n";
    }

    return 0;
}
