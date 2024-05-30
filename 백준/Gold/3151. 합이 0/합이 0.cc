#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int arr[10010];

int main() {
    int N;
    cin >> N;

    
    unordered_map<int, int> num;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        num[arr[i]]++;
    }

    sort(arr,arr+N);

    long long ans = 0;

    for (int i = 0; i < N -1; i++) {
        for (int j = i + 1; j < N; j++) {
            auto ub = upper_bound(arr + j + 1, arr + N, -(arr[i] + arr[j]));
            auto db = lower_bound(arr + j + 1, arr + N, -(arr[i] + arr[j]));
            ans += ub - db;
        }
    }

    cout << ans << "\n";

    return 0;
}
