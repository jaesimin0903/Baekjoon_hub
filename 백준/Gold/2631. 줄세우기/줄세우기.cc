#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// LIS를 계산하는 함수 (O(N log N))
int LIS_length(const vector<int>& arr) {
    vector<int> lis;

    for (int i = 0; i < arr.size(); i++) {
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        if (it == lis.end()) {
//            cout << arr[i] << "\n";
            lis.push_back(arr[i]);
        }
        else {
            *it = arr[i];
            //for (auto v : arr) {
            //    cout << v << " ";
            //}
            //cout << "\n";
        }
    }

    return lis.size();
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // LIS의 길이를 구함
    int lis_len = LIS_length(arr);

    // 최소 이동 횟수는 전체 길이에서 LIS의 길이를 뺀 값
    int min_moves = N - lis_len;

    cout << min_moves << endl;

    return 0;
}
