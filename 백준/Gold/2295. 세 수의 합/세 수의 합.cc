#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
typedef long long ll;
using namespace std;

int N, M;

unordered_map<int, int>um;

int binarySearch(vector<int>& A, int x, int left, int right) {
    if (left > right) {
        return false;
    }

    int mid = left + (right - left) / 2;

    if (A[mid] == x) {
        return mid;
    }
    else if (A[mid] > x) {
        return binarySearch(A, x, left, mid - 1);
    }
    else {
        return binarySearch(A, x, mid + 1, right);
    }
}

int main() {
    
    cin >> N;
    vector<int> init;
    for (int i = 0; i < N; i++) {
        int n1;
        cin >> n1;
        init.push_back(n1);
    }

    vector<int> twotwo;

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            twotwo.push_back(init[i] + init[j]);
        }
    }

    sort(twotwo.begin(), twotwo.end());

    //twotwo.erase(unique(twotwo.begin(), twotwo.end()), twotwo.end());
    
    sort(init.begin(), init.end());

    int ans = 0;

    for (int i = N-1; i >=0; i--) {
        for (int j = 0; j < i; j++) {
            int target = init[i] - init[j];
            //if (target < 0)continue;
            if (binary_search(twotwo.begin(), twotwo.end(), init[i] - init[j])) {

                ans = max(ans, init[i]);
            }
        }
    }

    cout << ans;

    return 0;
}
//0 1 2 3 4 
// mid = 2
// mid = 3