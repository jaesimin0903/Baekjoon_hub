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

int N;
int arr[1010];
int dp[1010];
unordered_map<int,int> um;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int maxx = 0;
    int maxx_idx = -1;
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        if (maxx < dp[i]) {
            maxx = dp[i];
            maxx_idx = i;
        }
        //for (int j = 0; j < N; j++) {
        //    cout << dp[j] << " ";
        //}
        //cout << "\n";
    }

    for (int i = 0; i < N; i++) {
        if (um.find(dp[i]) != um.end()) {
            if (um[dp[i]] > arr[i]) um[dp[i]] = arr[i];
            
        }
        else {
            um[dp[i]] = arr[i];
        }
    }

    cout << maxx<< "\n";
    int max = 0;
    int target = dp[maxx_idx];
    vector<int> v;
    for (int i = maxx_idx; i >= 0; i--) {
        if (dp[i] == target) {
            v.push_back(arr[i]);
            target--;
        }
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }

    return 0;
}

