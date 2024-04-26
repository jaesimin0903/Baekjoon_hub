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

pair<ll,ll> arr[1000010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    //자연수 n개 카드, i -> ai
    // a_x + a_y
    // a_x , a_y = a_x + a_y
    //가장 작게 만드는게 목표

    cin >> N;

    for (int i=  0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr + N);

    ll s = arr[0].first;
    ll e = arr[0].second;
    ll answer = 0;

    if (N == 1) {
        answer += abs(e - s);
    }

    for (int i = 1; i < N; i++) {
        if (arr[i].first > e) {
            answer += abs(e - s);
            s = arr[i].first;
            e = arr[i].second;
        }
        else if(e < arr[i].second){
            e = arr[i].second;
        }

        if (i == N - 1) {
            answer += abs(e - s);
        }      
        //cout << s << " " << e << "\n";
    }

    cout << answer;

    return 0;
}
