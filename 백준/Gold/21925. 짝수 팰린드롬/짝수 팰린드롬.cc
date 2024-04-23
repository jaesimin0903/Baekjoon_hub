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
    stack<int>s;
    vector<int> v;
    int answer = 0;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        if (s.empty()) { s.push(arr[i]); v.push_back(arr[i]); }
        else {
            if (s.top() == arr[i]) {
                s.pop();
                v.push_back(arr[i]);
                if (s.empty()) {
                    int idx = 0;
                    
                    for (int j = i; j > i - (v.size()-1); j--) {
                        //cout << v[idx] << " " << arr[j] << "\n";
                        if (v[idx] != arr[j]) {
                            cout << -1;
                            return 0;
                        }idx++;
                    }
                    answer++;
                    v.clear();
                }
            }
            else {
                s.push(arr[i]);
                v.push_back(arr[i]);
            }
        }
    }

    if (s.empty()) {
        cout << answer;
    }
    else {
        cout << -1;
    }

    return 0;
}
