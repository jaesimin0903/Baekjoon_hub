#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    cin >> N;

    ll M;
    cin >> M;
    vector<vector<ll>> v(N, vector<ll>(N, 0));

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            v[i][j] = num;
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i<N-1 &&j == 0 ) v[i + 1][j] += v[i][j];
            if ((j < N - 1 && i == 0)) v[i][j + 1] += v[i][j];
            if(i>0 && j >0)
                v[i][j] = v[i][j] + v[i-1][j] + v[i][j-1] - v[i-1][j-1];
        }
    }



    for (int i = 0; i < M; i++) {
        int answer = 0;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == 1 && y1 == 1)
            answer = v[x2 - 1][y2 - 1];
        else if (x1 == 1) {
            answer = v[x2 - 1][y2 - 1]  - v[x2 - 1][y1 - 2];
        }
        else if (y1 == 1) {
            answer = v[x2 - 1][y2 - 1] - v[x1 - 2][y2 - 1] ;
        }
        else {
            answer = v[x2 - 1][y2 - 1] - v[x1 - 2][y2 - 1] - v[x2 - 1][y1 - 2] + v[x1 - 2][y1 - 2];

        }
        cout << answer << "\n";
    }

    //11 ~ x2y2 - 11~x1-1,y2 - 11~x2,y1-1 + 11~(x1-1,y1-1)
    //33 44
    return 0;
}
