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

ll arr[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    //자연수 n개 카드, i -> ai
    // a_x + a_y
    // a_x , a_y = a_x + a_y
    //가장 작게 만드는게 목표

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    while (M--) {
        sort(arr, arr + N);
        ll sum = arr[0] + arr[1];
        arr[0] = sum;
        arr[1] = sum;
    }
    ll answer = 0;
    for (int i = 0; i < N; i++) {
        answer += arr[i];
    }

    cout << answer;

    return 0;
}
