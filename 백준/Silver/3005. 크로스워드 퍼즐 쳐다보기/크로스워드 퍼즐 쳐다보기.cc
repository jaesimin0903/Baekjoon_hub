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
#include<cstring>
using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int room[51][51];
bool clean[51][51];
//북동남서 0123

int y, x, N,M, arrow;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    vector<string> v;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }

    queue<tuple<int, int, int>> q;
    vector<string> ans;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            //cout << i << " " << j;
            if (v[i][j] != '#') {
                int t = 1;
                string ss = "";
                if (j - 1 < 0 || (j - 1 >= 0 && v[i][j-1] == '#')) {
                    ss = "";
                    ss += v[i][j];
                    while (j + t < M && v[i][j+t] != '#'  ) {
                        ss += v[i][j+t];
                        t++;
                    }
                    if(ss.size()>1)ans.push_back(ss);
                }
                
                if (i - 1 < 0 || (i - 1 >= 0 && v[i - 1][j] == '#')) {
                    t = 1;
                    ss = "";
                    ss += v[i][j];
                    while (i+t<N &&v[i + t][j] != '#') {
                        ss += v[i + t][j];
                        t++;
                    }
                    if (ss.size() > 1)ans.push_back(ss);
                }
                
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans[0];

    return 0;
}

