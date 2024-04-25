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

pair<int, int> arr[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr + N, [](const pair<int, int>& a, const pair<int, int>& b) {
        if(a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
        });

    int answer = 0;
    
    int s = arr[0].first;
    int e = 0;



    for (int i = 0; i < N; i++) {
        if (e <= arr[i].first) { 
            answer++;
            s = arr[i].first;
            e = arr[i].second;
        }
    }

    cout << answer;

    return 0;
}
