#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int N;
ll arr[100010];

ll bs(int r) {
    int s = 0, e = N - 1;
    ll result = arr[0];
    while (s <= e) {
        int mid = (s + e) / 2;
        if (abs(arr[mid] - r) < abs(result - r)) {
            result = arr[mid];
        }
        if (arr[mid] < r) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return result;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    pair<ll, ll> ans;
    ans.first = 1000000000;
    ans.second = 1000000000;
    for (int i = 0; i < N; i++) {
        ll ans_sum = abs(ans.first + ans.second);
        ll b = bs(-arr[i]);
        if (abs(arr[i] + b) < ans_sum && arr[i] != b) {
            if (arr[i] <= b) {
                ans.first = arr[i];
                ans.second = b;
            }
            else {
                ans.first = b;
                ans.second = arr[i];
            }
        }
    }

    cout << ans.first << " " << ans.second;
    return 0;
}
