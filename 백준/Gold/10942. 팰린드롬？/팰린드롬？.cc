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
using namespace std;

typedef long long ll;

int N, M;

int arr[1000010];
bool dp[2010][2010];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    cin >> M;

    for (int i = 1; i <= N; i++) {
        dp[i][i] = true;
    }

    for (int i = N; i >= 1; i--) {
        for (int j = i+1; j <= N; j++) {
            if (arr[i] == arr[j] && dp[i + 1][j - 1] == true) dp[i][j] = true;
            else if (arr[i] == arr[j] && j == i + 1) dp[i][j] = true;
            
        }
    }


    while (M--) {
        int n1, n2;
        cin >> n1 >> n2;
        cout << dp[n1][n2] << "\n";
    }

    return 0;
}
