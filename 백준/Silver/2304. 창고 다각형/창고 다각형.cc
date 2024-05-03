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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int answer = 0;

    int start_idx = 1010;
    int last_idx = 0;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        start_idx = min(start_idx, n);
        last_idx = max(last_idx, n);
        cin >> arr[n];
    }

    for (int i = start_idx; i <=last_idx; i++) {
        int left=0;
        int right=0;

        for (int j = 0; j <= i - 1; j++) {
            left = max(left, arr[j]);
        }

        for (int j = i + 1; j <= last_idx + 5; j++) {
            right = max(right, arr[j]);
        }

        if ((left <= arr[i] && arr[i] <= right) || (left >= arr[i] &&  arr[i] >= right)) {
            answer += arr[i];
        }
        else if (left > arr[i] && right > arr[i]) {
            int mid = min(left, right);
            answer += mid;
        }
        else if (left <= arr[i] && arr[i] >= right) {
            answer += arr[i];
        }

        //cout << answer << " " << left << " " << right << "\n";
    }

    cout << answer;

    return 0;
}

